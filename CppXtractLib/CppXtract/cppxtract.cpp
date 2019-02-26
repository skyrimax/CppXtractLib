#include "stdafx.h"
#include "cppxtract.h"
#include "QCppXtractParamWidget.h"
#include <CppXtractLib.h>

//class QCppXtractParamWidget; // Déclaration anticipée

CppXtract::CppXtract(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Insérer l'icône de l'application
	// Le URL de l'icone est indiqué dans le Qt Resource Editor
	setWindowIcon(QIcon(":/CppXtract/Resources/cpp-file-format-symbol.png"));

	// Changer le titre de la fenêtre principale par programmation
	setWindowTitle(u8R"**(CppXtract)**");

	// Création de l'objet de type QCppXtractParamWidget
	mCppXtractParamWidget = new QCppXtractParamWidget(this);

	// Désactiver le bouton d'éxtraction des commentaires
	ui.extractButton->setEnabled(false);

	// Provoque updateProcessButton quand parameterChanged est triggered par mQppXtractParamWidget
	connect(mCppXtractParamWidget, &QCppXtractParamWidget::parameterChanged, this,
		&CppXtract::updadeProcessButton);

	connect(ui.extractButton, &QPushButton::clicked, this, &CppXtract::process);
}

void CppXtract::showAboutCppXtract()
{
	//Créer le message
	QString aboutCppXtract{ \
	u8R"---(CppXtract est un logiciel d'extraction de commentaire du langage C++

Ce programme a été réalisé par :
 - Frédéric Grondines
 - Guillaume Faucher
 - Mathieu Labelle
 - Maxime Royal
 - Mikaël Valton Charette

Dans le cadre du cours :
 - GPA434 - Ingénierie des systèmes orientés-objet
 - Laboratoire 2

Version 1.0)---" };

	// Afficher le message
	QMessageBox::about(this, u8R"(À propos de CppXtract)", aboutCppXtract);
}

bool CppXtract::fileOk(const QFileInfo & xFile, QString & errMsg, bool checkRead)
{
	// Préparer le message d'erreur...
	errMsg = checkRead ? u8R"(Le fichier d'entré )" : u8R"(Le fichier de sortie )";
	errMsg += QString("\"") + xFile.fileName() + "\"" + " : ";

	// D'abord s'assurer que le nom du fichier n'est pas vide (parano)
	if (xFile.fileName().isEmpty())
	{
		errMsg += "N'a pas de nom.\n";
		return false;
	}
	// En lecture...
	if (checkRead)
	{
		// S'assurer que l'utilisateur a la permission de lecture
		if (!QFileInfo(xFile.filePath()).isReadable())
		{
			errMsg += QString(u8R"(Il est protégé contre la lecture.)") + "\n";
			return false;
		}
	}
	else
	{
		// L'utilisateur doit avoir la d'écriture dans le dossier
		if (!QFileInfo(xFile.filePath()).isWritable())
		{
			errMsg += QString(u8R"(Pas de permission d'écriture dans le dossier.)") + "\n";
			return false;
		}
		// L'utilisateur doit avoir les droits d'écriture dans le fichier
		// si celui-ci existe
		if ((QFileInfo(xFile.filePath()).exists()) && !QFileInfo(xFile.filePath()).isWritable())
		{
			errMsg += QString(u8R"(Il est protégé contre l'écriture.)") + "\n";
			return false;
		}
	}
	// Tout va bien
	return true;
}

void CppXtract::showAboutCpp()
{
	// Déclaration du texte à afficher avec les marqueurs de RichText
	QString aboutCppText{ \
		"C++ is a general-purpose programming language.It has imperative, object-<br>\
		oriented and generic programming features, while also providing facilities<br>\
		for low - level memory manipulation.<br>\
		<br>\
		It was designed with a bias toward system programming and embedded,<br>\
		resource-constrained and large systems, with performance, efficiency and<br>\
		flexibility of use as its design highlights. C++ has also been found useful in<br>\
		many other contexts, with key strengths being software infrastructure and<br>\
		resource-constrained applications, including desktop applications, servers<br>\
		(e.g.e - commerce, Web search or SQL servers), and performance-critical<br>\
		applications (e.g.telephone switches or space probes). C++ is a compiled<br>\
		language, with implementations of it available on many platforms.Many<br>\
		vendors provide C++ compilers, including the Free Software Foundation,<br>\
		Microsoft, Intel, and IBM.<br>\
		<br>\
		C++ is standardized by the International Organization for Standardization<br>\
		(ISO), with the latest standard version ratified and published by ISO in<br>\
		December 2017 as ISO / IEC 14882:2017 (informally known as C++17). The<br>\
		C++ programming language was initially standardized in 1998 as<br>\
		ISO / IEC 14882 : 1998, which was then amended by the C++03, C++11 and C++14<br>\
		standards.The current C++17 standard supersedes these with new features and<br>\
		an enlarged standard library.Before the initial standardization in 1998, C++<br>\
		was developed by Bjarne Stroustrup at Bell Labs since 1979, as an extension of<br>\
		the C language as he wanted an efficient and flexible language similar to C,<br>\
		which also provided high - level features for program organization. C++20 is<br>\
		the next planned standard thereafter, keeping with the current streak of a new<vr>\
		version every three years.<br>\
		<br>\
		Many other programming languages have been influenced by C++<br>\
		including C#, D, Java, and even newer versions of C.<br>\
		<br>\
		Source principale : <a href = \" https://en.wikipedia.org/wiki/C%2B%2B \"> sur Wikipedia </a>"
	};

	// Création du MessageBox
	QMessageBox aboutCpp(QMessageBox::NoIcon, u8R"(À propos du langage C++)", aboutCppText,
		QMessageBox::Ok, this);

	// Ajout du logo du C++
	QPixmap cppLogo(":/CppXtract/Resources/cpp_logo.png");
	QRegion exposed;

	// Imposer le format de Text RichText
	aboutCpp.setTextFormat(Qt::RichText);

	// Ajout de l'icône du C++ à la fenêtre
	aboutCpp.setIconPixmap(cppLogo.scaled(64, 64, Qt::KeepAspectRatio,
		Qt::SmoothTransformation));

	// Affichage de la fenêtre
	aboutCpp.exec();
}

void CppXtract::showAboutQt()
{
	qApp->aboutQt();
}

void CppXtract::updadeProcessButton()
{
	ui.extractButton->setEnabled(mCppXtractParamWidget->isValid());
}

void CppXtract::process()
{
	QString errorMsg;

	// D'abord s'assurer que le fichier d'entrée est valide
	QFileInfo inputFileInfo(mCppXtractParamWidget->inputFilename());
	if (!fileOk(inputFileInfo, errorMsg, true))
	{
		QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
		return;
	}
	//Créer la FST pour l'extraction des commentaires
	cppXtractLib::CppXtract cppXtract;
	// Exécuter l'extraction des commentaires selon les options de sortie
	switch (mCppXtractParamWidget->outputType())
	{
		//L'utilisateur a sélectionné la sortie vars un fichier
	case QCppXtractParamWidget::OutputType::File:
	{
		errorMsg.clear();
		QFileInfo outputFileInfo(mCppXtractParamWidget->outputFilename());
		// Méga parano
		if (!fileOk(outputFileInfo, errorMsg, false))
		{
			QMessageBox::warning(this, "Erreur", errorMsg + "\nAucune extraction n'a eu lieu");
			return;
		}
		else
		{
			// Exécuter l'extraction
			cppXtract.processFromFileToFile(inputFileInfo.filePath().toStdString(),
				outputFileInfo.filePath().toStdString(),
				mCppXtractParamWidget->isStatIncluded());
			QMessageBox::information(this, u8R"(Opération terminée)",
				QString(u8R"(Le fichier de sortie )") + "\"" + outputFileInfo.filePath() +
				"\"" + u8R"( a été créé.)");
		}
		break;
	}
		// L'utilisateur a choisi la sortie vers le presse-papier
	case QCppXtractParamWidget::OutputType::Clipboard:
	{
		/*QMessageBox::information(this, u8R"(Opération sélectionnée)",
			QString(u8R"(Il faut envoyer les résultats vers le presse papier!)"));*/

		//Création d'un pointeur sur le clipboard
		QClipboard* clipboard = QGuiApplication::clipboard();
		std::string str;

		if (!clipboard)
		{
			QMessageBox::warning(this, "Erreur", QString("N'as pas pu avoir acces au presse-papier")
				+ "\nAucune extraction n'as eu lieu");
			return;
		}
		else
		{
			//Exécute l'extraction
			cppXtract.processFromFileToString(inputFileInfo.filePath().toStdString(),
				str, mCppXtractParamWidget->isStatIncluded());
			clipboard->setText(QString(str.c_str()));
			QMessageBox::information(this, u8R"(Opération terminée)",
				QString(u8R"(Le résultat à été placé dans le presse-papier)"));
		}
		break;
	}
		// L'utilisateur a choisi vers l'écran
	case QCppXtractParamWidget::OutputType::Screen:
	{
		QMessageBox::information(this, u8R"(Opération sélectionnée)",
			QString(u8R"(Il faut envoyer les résultats vers l'écran!)"));
		break;
	}
	}
}
