#include "stdafx.h"
#include "cppxtract.h"

CppXtract::CppXtract(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Insérer l'icone de la fenêtre
	setWindowIcon(QIcon(":/CppXtract/Resources/TonyIcon.png"));

	//Modification du titre de la fenêtre
	setWindowTitle(u8R"**(CppXtract - Laboratoire #2)**");
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
	- GPA434 - Inénierie des systèmes orientés-objet
	- Laboratoire 2

Version 1.0)---"};

//Afficher le message
	QMessageBox::about(this, u8R"(À propos de CppXtract)", aboutCppXtract);
};

void CppXtract::showAboutCpp() {
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
	QMessageBox msgbox(QMessageBox::NoIcon, u8R"(À propos de C++)", cppDescription, QMessageBox::Ok, this, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

	//Icone de la fenêtre
	setWindowIcon(QIcon(":/CppXtract/Resources/TonyIcon.png"));

	//Création du pixmap pour l'icone du C++
	QPixmap cppLogo(":/CppXtract/Resources/cpp_logo.png");
	QRegion exposed;

	//Format du texte
	msgbox.setTextFormat(Qt::RichText);
	
	//Création du titre de la fenêtre
	msgbox.setWindowTitle("A propos du langage C++");
	msgbox.setIconPixmap(cppLogo.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	msgbox.exec();


};

void CppXtract::showAboutQt() { qApp->aboutQt(); };