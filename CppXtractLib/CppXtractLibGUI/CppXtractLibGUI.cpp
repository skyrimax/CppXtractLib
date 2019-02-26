#include "CppXtractLibGUI.h"
#include "QCppXtractParamWidget.h"
#include "qmessagebox.h"
#include "CppXtract.h"
#include <qclipboard.h>
#include "qtplaintextdialog.h"


// D�claration anticip�e
class CppXtractLibGUI;


CppXtractLibGUI::CppXtractLibGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Ins�rer l'ic�ne de l'application
	// Le URL de l'ic�ne est indiqu� dans le Qt Resource Editor
	setWindowIcon(QIcon(":/CppXtractLibGUI/Resources/cbooboob.png"));

	// Changer le titre de la fen�tre principale par programmation
	setWindowTitle(u8R"**(CppXtractLib - Aide � la r�alisation partie #2)**");

	// Cr�er un objet de classe QCppXtractParamWidget et lui passer un pointeur de la fen�tre principale.
	mCppXtractParamWidget = new QCppXtractParamWidget(this);

	// D�sactiver le bouton "Extraire les commentaires"
	ui.mProcessButton->setEnabled(false);

	// Connecter le signal parameterChanged() venant de QCppXtractParamWidget
	// au slot updateProcessButton() de CppXtractLibGUI (fen�tre principale)
	connect(mCppXtractParamWidget, &QCppXtractParamWidget::parameterChanged, this, 
		&CppXtractLibGUI::updateProcessButton);

	// Connecter le signal clicked venant du bouton "Extraire les commentaires"
	// au slot process() de CppXtractLibGUI (fen�tre principale)
	connect(ui.mProcessButton, &QPushButton::clicked, this, &CppXtractLibGUI::process);
}

void CppXtractLibGUI::showAboutCppXtract(){
	// Cr�er le message
	QString aboutCppXtract{ \
		u8R"---(CppXtract est un logiciel d'extraction de commentaires du langage C++.

Ce programme a �t� r�alis� par :
- Guillaume Faucher
- Tony Wong
- Jean-Christophe Demers

Dans le cadre du cours :
- GPA434 - Ing�nierie des syst�mes orient�s-objet
- Laboratoire 2

Version 1.1)---" };
	// Afficher le message
	QMessageBox::about(this, u8R"(� propos de CppXtract)", aboutCppXtract);
	
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
	// Cr�er un QMessageBox de toute pi�ce
	QMessageBox messageBox(QMessageBox::NoIcon, u8R"(� propos du langage C++)",
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

	// D'abord s'assurer que le fichier d'entr�e est valide
	QFileInfo inputFileInfo(mCppXtractParamWidget->inputFilename());
	if (!fileOk(inputFileInfo, errorMsg)) {
		QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
		return;
	}
	// Cr�er la FST pour l'extraction des commentaires
	CppXtract cppXtract;

	// Ex�cuter l'extraction des commentaires selon les options de sortie
	switch (mCppXtractParamWidget->outputType()) {
		// L'utilisateur a s�lectionn� la sortie vers un fichier
		case QCppXtractParamWidget::OutputType::File: {
			errorMsg.clear();
			QFileInfo outputFileInfo(mCppXtractParamWidget->outputFilename());
				// Extra paranoy�
			if (!fileOk(outputFileInfo, errorMsg, false)) {
				QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
				return;
			}
			else {
					// Ex�cute l'extraction
					cppXtract.processFromFileToFile(inputFileInfo.filePath().toStdString(),
						outputFileInfo.filePath().toStdString(),
						mCppXtractParamWidget->isStatIncluded());
					QMessageBox::information(this, u8R"(Op�ration termin�e)",
						QString(u8R"(Le fichier de sortie )") + "\"" + outputFileInfo.fileName() +
						"\" " + u8R"( a �t� cr��.)");
			}
			break;
		}
			// L'utilisateur a choisi la sortie vers le presse papier
		case QCppXtractParamWidget::OutputType::Clipboard: {
			QMessageBox::information(this, u8R"(Op�ration s�lectionn�e)",
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
			// L'utilisateur a choisi la sortie vers l'�cran
		case QCppXtractParamWidget::OutputType::Screen: {
			QMessageBox::information(this, u8R"(Op�ration s�lectionn�e)",
				QString(u8R"(Le r�sultat s'affichera � l'�cran suivante!)"));

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
	// Pr�parer le message d'erreur...
	errMsg = checkRead ? u8R"(Le fichier d'entr�e)" : "Le fichier de sortie ";
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
			errMsg += QString(u8R"(Il est prot�g� contre la lecture.)") + "\n";
			return false;
		}
	}
	// En �criture...
	else {
		// L'utilisateur doit avoir la permission d'�criture
		// dans ce dosier
		if (!QFileInfo(xFile.path()).isWritable()) {
			errMsg += QString(u8R"(Pas de permission d'�criture dans le dossier.)") + "\n";
				return false;
		}
		// Si le fichier de sortie existe alors l'utilisateur doit
		// avoir la permission d'�criture dans le fichier (�craser le fichier)
		if ((QFileInfo(xFile.filePath()).exists()) && !QFileInfo(xFile.filePath()).isWritable()) {
			errMsg += QString(u8R"(Il est prot�g� contre l'�criture.)") + "\n";
			return false;
		}
	}
	// Tout va bien
	return true;
}