#include "CppXtractLibGUI.h"
#include "qmessagebox.h"

// Déclaration anticipée
class CppXtractLibGUI;

// Classe qui doit gérer certains éléments d'interface graphique
class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT
		
public:
	QCppXtractParamWidget(CppXtractLibGUI *mainWin);

		// le reste de la déclaration des

private:
	CppXtractLibGUI *mMainWin;

};

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