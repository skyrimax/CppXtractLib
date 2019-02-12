#ifndef Q_PLAIN_TEXT_DIALOG
#define Q_PLAIN_TEXT_DIALOG


#include <QDialog>


//
// Boîte de dialogue offrant la possibilité d'afficher un texte non éditable.
//
// Les paramètres du constructeur sont :
//	- parent :			le widget parent
//	- text :			le texte à afficher
//	- modal :			si la fenêtre est modale ou non
//	- initialSize :		la taille initiale de la fenêtre - si donnée, la 
//						fenêtre de dialogue est centrée selon la taille 
//						déterminée
//
// Voici un exemple d'usage :
// QPlainTextDialog myPlainTextDlg(	this,
//									"texte à afficher",
//									true,
//									QSize(800, 600));
// myPlainTextDlg.exec();
//


class QPlainTextDialog : public QDialog
{
	Q_OBJECT

public:
	QPlainTextDialog(QWidget * parent, const QString & text, bool modal = true, QSize const & initialSize = QSize());
};

#endif // Q_PLAIN_TEXT_DIALOG