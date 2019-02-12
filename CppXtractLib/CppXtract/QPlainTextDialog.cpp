#include "QPlainTextDialog.h"							// Inclusion du fichier d'en-tête correspondant


#include <QVBoxLayout>									// Pour l'assemblage vertical
#include <QPlainTextEdit>								// Widget gérant l'affichage d'un texte sans mise en forme à l'écran
#include <QDialogButtonBox>								// Widget pour les boutons se trouvant au bas de la boîte de dialogue
#include <QIcon>										// Classe gérant l'icône de la fenêtre
#include <QApplication>									// Classe de l'application principale
#include <QDesktopWidget>								// Classe permettant de connaître les caractéristiques de l'écran

QPlainTextDialog::QPlainTextDialog(QWidget * parent, const QString & text, bool modal, QSize const & initialSize)
	: QDialog(parent)
{
	// Set dialog properties
	setWindowTitle("Résultat de l'extraction des commentaires");
	if (parent) {
		setWindowIcon(parent->windowIcon());
	}
	setModal(modal);

	// Adjust initial size relative to screen if any initial size is provided
	QRect screenGeometry(QApplication::desktop()->screenGeometry());
	if (initialSize.isValid()) {
		setGeometry((screenGeometry.width() - initialSize.width()) / 2, (screenGeometry.height() - initialSize.height()) / 2, initialSize.width(), initialSize.height());
	}
	
	// Create and initialize widgets
	QPlainTextEdit * plainTextEdit{ new QPlainTextEdit };
	QDialogButtonBox * buttonBox{ new QDialogButtonBox(QDialogButtonBox::Ok) };
	plainTextEdit->setReadOnly(true);
	plainTextEdit->setPlainText(text);

	// Create layout and build the disposition
	QVBoxLayout * dlgLayout{ new QVBoxLayout };
	dlgLayout->addWidget(plainTextEdit);
	dlgLayout->addWidget(buttonBox);
	setLayout(dlgLayout);

	// Connect the button
	QObject::connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}
