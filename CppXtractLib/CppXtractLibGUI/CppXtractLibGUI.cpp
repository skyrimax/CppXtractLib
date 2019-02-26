#include "CppXtractLibGUI.h"
#include "QCppXtractParamWidget.h"
#include "qmessagebox.h"
#include "CppXtract.h"
#include <qclipboard.h>
#include "qtplaintextdialog.h"


// Déclaration anticipée
class CppXtractLibGUI;


CppXtractLibGUI::CppXtractLibGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Insérer l'icône de l'application
	// Le URL de l'icône est indiqué dans le Qt Resource Editor
	setWindowIcon(QIcon(":/CppXtractLibGUI/Resources/cbooboob.png"));

	// Changer le titre de la fenêtre principale par programmation
	setWindowTitle(u8R"**(CppXtractLib - Aide à la réalisation partie #2)**");

	// Créer un objet de classe QCppXtractParamWidget et lui passer un pointeur de la fenêtre principale.
	mCppXtractParamWidget = new QCppXtractParamWidget(this);

	// Désactiver le bouton "Extraire les commentaires"
	ui.mProcessButton->setEnabled(false);

	// Connecter le signal parameterChanged() venant de QCppXtractParamWidget
	// au slot updateProcessButton() de CppXtractLibGUI (fenêtre principale)
	connect(mCppXtractParamWidget, &QCppXtractParamWidget::parameterChanged, this, 
		&CppXtractLibGUI::updateProcessButton);

	// Connecter le signal clicked venant du bouton "Extraire les commentaires"
	// au slot process() de CppXtractLibGUI (fenêtre principale)
	connect(ui.mProcessButton, &QPushButton::clicked, this, &CppXtractLibGUI::process);
}

void CppXtractLibGUI::showAboutCppXtract(){
	// Créer le message
	QString aboutCppXtract{ \
		u8R"---(CppXtract est un logiciel d'extraction de commentaires du langage C++.

Ce programme a été réalisé par :
- Guillaume Faucher
- Tony Wong
- Jean-Christophe Demers

Dans le cadre du cours :
- GPA434 - Ingénierie des systèmes orientés-objet
- Laboratoire 2

Version 1.1)---" };
	// Afficher le message
	QMessageBox::about(this, u8R"(À propos de CppXtract)", aboutCppXtract);
	
}

void CppXtractLibGUI::showAboutCpp(){
	// Le texte est en format HTML
	QString aboutCpp{
		"C++ is a general-purpose programming language.It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation."
		"<br><br>"
		"It was designed with a bias toward system programming and embedded, resource-constrained and large systems, with performance, efficiency and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, servers (e.g. e-commerce, Web search or SQL servers), and performance-critical applications (e.g. telephone switches or space probes). C++ is a compiled language, with implementations of it available on many platforms. Many vendors provide C++ compilers, including the Free Software Foundation, Microsoft, Intel, and IBM."
		"<br><br>"
		"C++ is standardized by the International Organization for Standardization (ISO). C++ was developed by Bjarne Stroustrup at Bell Labs since 1979, as an extension of the C language as he wanted an efficient and flexible language similar to C, which also provided high-level features for program organization."
		"<br><br>"
		"Many other programming languages have been influenced by C++, including C#, D, Java, and even newer versions of C."
		"<br><br>"
		"Source principale: <a href=\"https://en.wikipedia.org/wiki/C%2B%2B\">C++ sur Wikipedia</a>"
	};
	// Créer un QMessageBox de toute pièce
	QMessageBox messageBox(QMessageBox::NoIcon, u8R"(À propos du langage C++)",
		aboutCpp, QMessageBox::Ok, this, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

	QPixmap icon(":/CppXtractLibGUI/Resources/cpp_logo.png");
	messageBox.setIconPixmap(icon.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));

	// QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	// QGridLayout* layout = static_cast<QGridLayout*>(messageBox.layout());
	// layout->addItem(horizontalSpacer, layout->rowCount(),0,1,layout->columnCount());
	messageBox.setTextFormat(Qt::RichText);
	messageBox.exec();

}
void CppXtractLibGUI::showAboutQt() { qApp->aboutQt(); }

// Active le bouton "Extraire les commentaires" si les options de sorties sont valides
void CppXtractLibGUI::updateProcessButton(){
	ui.mProcessButton->setEnabled(mCppXtractParamWidget->isValid());
}

// Extraction
void CppXtractLibGUI::process() {
	QString errorMsg;

	// D'abord s'assurer que le fichier d'entrée est valide
	QFileInfo inputFileInfo(mCppXtractParamWidget->inputFilename());
	if (!fileOk(inputFileInfo, errorMsg)) {
		QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
		return;
	}
	// Créer la FST pour l'extraction des commentaires
	CppXtract cppXtract;

	// Exécuter l'extraction des commentaires selon les options de sortie
	switch (mCppXtractParamWidget->outputType()) {
		// L'utilisateur a sélectionné la sortie vers un fichier
		case QCppXtractParamWidget::OutputType::File: {
			errorMsg.clear();
			QFileInfo outputFileInfo(mCppXtractParamWidget->outputFilename());
				// Extra paranoyé
			if (!fileOk(outputFileInfo, errorMsg, false)) {
				QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
				return;
			}
			else {
					// Exécute l'extraction
					cppXtract.processFromFileToFile(inputFileInfo.filePath().toStdString(),
						outputFileInfo.filePath().toStdString(),
						mCppXtractParamWidget->isStatIncluded());
					QMessageBox::information(this, u8R"(Opération terminée)",
						QString(u8R"(Le fichier de sortie )") + "\"" + outputFileInfo.fileName() +
						"\" " + u8R"( a été créé.)");
			}
			break;
		}
			// L'utilisateur a choisi la sortie vers le presse papier
		case QCppXtractParamWidget::OutputType::Clipboard: {
			QMessageBox::information(this, u8R"(Opération sélectionnée)",
				QString(u8R"(Copiez le presse-papier dans un fichier texte!)"));
			QClipboard *XtractClipboard = QGuiApplication::clipboard();
			std::string str;
			cppXtract.processFromFileToString(inputFileInfo.filePath().toStdString(),
				str,
				mCppXtractParamWidget->isStatIncluded());

			QString clipcomment = QString::fromLocal8Bit(str.c_str());

			XtractClipboard->setText(clipcomment);
			break;
		}
			// L'utilisateur a choisi la sortie vers l'écran
		case QCppXtractParamWidget::OutputType::Screen: {
			QMessageBox::information(this, u8R"(Opération sélectionnée)",
				QString(u8R"(Le résultat s'affichera à l'écran suivante!)"));

			std::string str;
			cppXtract.processFromFileToString(inputFileInfo.filePath().toStdString(),
				str,
				mCppXtractParamWidget->isStatIncluded());

			QString screencomment = QString::fromLocal8Bit(str.c_str());
			
			QtPlainTextDialog resultDialog(this,
				screencomment);
			resultDialog.exec();
			break;
		}
	}//fin de switch-case


}// fin de la fonction process()

bool CppXtractLibGUI::fileOk(const QFileInfo & xFile, QString &errMsg, bool checkRead) {
	// Préparer le message d'erreur...
	errMsg = checkRead ? u8R"(Le fichier d'entrée)" : "Le fichier de sortie ";
	errMsg += QString("\"") + xFile.fileName() + "\"" + " : ";

	// D'abord s'assurer que le nom du fichier n'est pas vide (parano)
	if (xFile.fileName().isEmpty()) {
		errMsg += "N'a pas de nom.\n";
		return false;
	}
	// Ensuite s'assurer que le chemin est un dossier qui existe
	if (!QFileInfo(xFile.path()).isDir()) {
		errMsg += "Son chemin est incorrect.\n";
		return false;
	}
	// En lecture...
	if (checkRead) {
		// S'assurer que l'utilisateur a la permission lecutre
		if (!QFileInfo(xFile.filePath()).isReadable()) {
			errMsg += QString(u8R"(Il est protégé contre la lecture.)") + "\n";
			return false;
		}
	}
	// En écriture...
	else {
		// L'utilisateur doit avoir la permission d'écriture
		// dans ce dosier
		if (!QFileInfo(xFile.path()).isWritable()) {
			errMsg += QString(u8R"(Pas de permission d'écriture dans le dossier.)") + "\n";
				return false;
		}
		// Si le fichier de sortie existe alors l'utilisateur doit
		// avoir la permission d'écriture dans le fichier (écraser le fichier)
		if ((QFileInfo(xFile.filePath()).exists()) && !QFileInfo(xFile.filePath()).isWritable()) {
			errMsg += QString(u8R"(Il est protégé contre l'écriture.)") + "\n";
			return false;
		}
	}
	// Tout va bien
	return true;
}