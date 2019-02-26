#include "stdafx.h"
#include <QClipboard>
#include "cppxtract.h"
#include "QCppXtractParamWidget.h"
#include <CppXtractLib.h>
#include "qtplaintextdialog.h"


class QCppXtractParamWidget; //Déclaration anticipée

CppXtract::CppXtract(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Modification du titre de la fenêtre principale
	setWindowTitle(u8R"**(CppXtract - Laboratoire #2)**");

	mCppXtractParamWidget = new QCppXtractParamWidget(this);

	//Désactiver le bouton "Extraitre les commentaires"
	ui.mProcessButton->setEnabled(false);
	//Connection du signal parameterchanged au slot updateProcessButton()
	connect(mCppXtractParamWidget, &QCppXtractParamWidget::parameterChanged, this, &CppXtract::updateProcessButton);

	//Connecter le signal Clicked() au slot process()
	connect(ui.mProcessButton, &QPushButton::clicked, this, &CppXtract::process);
}

void CppXtract::showAboutCppXtract() {
//Créer le message
	QString aboutCppXtract{ \
	u8R"---(CppXtract ets un logiciel d'extraction de commentaires du langage C++.

Ce programme a été réalisé par :
	- Frédéric Grondines
	- Guillaume Faucher
	- Mathieu Labelle
	- Maxime Royal
	- Mikaël Valton Charette

Dans le cadre du cours :
	- GPA434 - Ingénierie des systèmes orientés-objet
	- Laboratoire 2

Version 1.0)---"};

//Afficher le message
	QMessageBox::about(this, u8R"(À propos de CppXtract)", aboutCppXtract);
};


void CppXtract::showAboutCpp() {

	//Description du langage C++ provenant de Wikipedia
	QString cppDescription{ "\
		 C++ is a general - purpose programming language.It has imperative, object -\
		 oriented and generic programming features, while also providing facilities for low -\
		 level memory manipulation.<br>\
<br>\
		 It was designed with a bias toward system programming and embedded, resource - \
		 constrained and large systems, with performance, efficiency and flexibility of use\
		 as its design highlights. C++ has also been found useful in many other contexts,\
		 with key strengths being software infrastructure and resource - constrained applications,\
		 including desktop applications, servers (e.g.e - commerce, Web search or SQL servers),\
		 and performance - critical applications (e.g.telephone switches or space probes). C++ is\
		 a compiled language, with implementations of it available on many platforms. Many vendors\
		 provide C++ compilers, including the Free Software Foundation, Microsoft, Intel, and IBM.<br>\
<br>\
		 C++ is standardized by the International Organization for Standardization (ISO),\
		 with the latest standard version ratified and published by ISO in December 2017\
		 as ISO / IEC 14882:2017 (informally known as C++17). The C++ programming language\
		 was initially standardized in 1998 as ISO / IEC 14882 : 1998, which was then amended\
		 by the C++03, C++11 and C++14 standards.The current C++17 standard supersedes these\
		 with new features and an enlarged standard library.Before the initial standardization\
		 in 1998, C++ was developed by Bjarne Stroustrup at Bell Labs since 1979, as an extension\
		 of the C language as he wanted an efficient and flexible language similar to C, which\
		 also provided high - level features for program organization.<br>\
<br>\
		 Source principale : <a href = \" https://en.wikipedia.org/wiki/C%2B%2B.ca \">C++ sur Wikipedia</a>"
	};

	//Création de l'objet msgbox
	QMessageBox msgbox(QMessageBox::NoIcon, u8R"(À propos du langage C++)", cppDescription, 
		QMessageBox::Ok, this, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

	//Icone de la fenêtre
	setWindowIcon(QIcon(":/CppXtract/Resources/TonyIcon.png"));

	//Création du pixmap pour l'icone du C++
	QPixmap cppLogo(":/CppXtract/Resources/cpp_logo.png");
	QRegion exposed;

	//Format du texte
	msgbox.setTextFormat(Qt::RichText);

	//Création du logo de C++
	msgbox.setIconPixmap(cppLogo.scaled(64, 64, Qt::KeepAspectRatio, 
		Qt::SmoothTransformation));

	//Affichage de la fenêtre
	msgbox.exec();
};


void CppXtract::showAboutQt() { qApp->aboutQt(); };


void CppXtract::updateProcessButton()
{
	ui.mProcessButton->setEnabled(mCppXtractParamWidget->isValid());
};


void CppXtract::process()
{
	QString errorMsg;

	//S'assurert que le fichier d'entrée est valide
	QFileInfo inputFileInfo(mCppXtractParamWidget->inputFilename());
	if (!fileOk(inputFileInfo, errorMsg, false))
	{
		QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
		return;
	}
	//Créer la FST pour l'Extraction des commentaires
	lib::CppXtract cppXtract;

	//Exécuter l'extraction selon les options de sorties
	switch (mCppXtractParamWidget->outputType())
	{
	//L'utilisateur sélectionne la sortie vers un fichier
	case QCppXtractParamWidget::OutputType::File: 
	{
		errorMsg.clear();
		QFileInfo outputFileInfo(mCppXtractParamWidget->outputFilename());
		if (!fileOk(outputFileInfo, errorMsg, false))
		{
			QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
			return;
		}
		else
		{
			//Exécute l'extraction
			cppXtract.processFromFileToFile(inputFileInfo.filePath().toStdString(),
				outputFileInfo.filePath().toStdString(),
				mCppXtractParamWidget->isStatIncluded());
			QMessageBox::information(this, u8R"(Opération terminé, Merci Tony Wong!!!)",
				QString(u8R"(Le fichier de sortie )") + "\"" + outputFileInfo.fileName() +
				"\"" + u8R"( a été créé)");
		}
		break;
	}
	//L'utilisateur a choisi la sortie vers le presse-papier
	case QCppXtractParamWidget::OutputType::Clipboard: 
	{

		std::string StringClipboard;

		//Exécute l'extraction
		cppXtract.processFromFileToString(inputFileInfo.filePath().toStdString(),
			StringClipboard, mCppXtractParamWidget->isStatIncluded());
		//Convertir std::string en QString
		QString qstr = QString::fromLocal8Bit(StringClipboard.c_str());
		//Envoie du QString dans le clipboard par la fonction setText()
		clipBoard->clipboard()->setText(qstr, QClipboard::Clipboard);

		QMessageBox::information(this, u8R"(Opération sélectionnée)",
			QString(u8R"(Il faut envoyer les résultats vers le presse-papier!)"));

		break;
	}
	//L'utilisateur a choisi la sortie vers l'écran
	case QCppXtractParamWidget::OutputType::Screen: 
	{
		std::string StringClipboard;

		//Extraction des commentaires dans un string
		cppXtract.processFromFileToString(inputFileInfo.filePath().toStdString(),
			StringClipboard, mCppXtractParamWidget->isStatIncluded());

		//Convertir std::string en QString
		QString qstr = QString::fromLocal8Bit(StringClipboard.c_str());

		//Exécution de l'extraction vers l'écran
		QtPlainTextDialog resultDialog(this, qstr);
		resultDialog.exec();
		break;
	}

	}//Fin du switch-case
}//Fin de la procédure process()


bool CppXtract::fileOk(const QFileInfo &xFile, QString &errMsg, bool checkRead)
{
	//Préparer le message d'erreur
	errMsg = checkRead ? u8R"(Le fichier d'entrée)" : "Le fichier de sortie";
	errMsg += QString("\"") + xFile.fileName() + "\"" + " : "; 

	//D'Abord s'Assurer que nom du fichier n'est pas vide
	if (xFile.fileName().isEmpty()) {
		errMsg += "N'a pas de nom. \n";
		return false;
	}
	//Ensuite s'assurer que le chemin est un dossier qui existe
	if (!QFileInfo(xFile.path()).isDir())
	{
		errMsg += "Son chemin est incorrect.\n";
			return false;
	}
	//En lecture...
	if (checkRead)
	{
		//S'assurer que l'utilisateur a la permission lecture
		if (!QFileInfo(xFile.path()).isReadable())
		{
			errMsg += QString(u8R"(Il est protégé contre la lecture.)") + "\n";
			return false;
		}
	}
	//En écriture...
	else
	{
		//L'utilisateur doit avoir la permission d'écriture das le dossier
		if (!QFileInfo(xFile.path()).isWritable())
		{
			errMsg += QString(u8R"(Pas de permission d'écriture dans le dossier.)") + "\n";
			return false;
		}
		//Si le fichier de sortie existe alors l'utilisateur doit avoir la permission d'écriture
		if ((QFileInfo(xFile.filePath()).exists()) && !QFileInfo(xFile.filePath()).isWritable())
		{
			errMsg += QString(u8R"(Il est protégé contre l'écriture.)") + "\n";
			return false;
		}
	}
	//Tout va bien
	return true;
}


