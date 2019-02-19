#include <QPushButton>											// Pour le bouton
#include <QLabel>												// Pour la zone d'affichage
#include <QFileDialog>											// Pour les bo�tes de dialogue "Open" et "Save as"
#include "QFileSelector.h"										// Inclusion du fichier d'en-t�te correspondant


// Constructeur
QFileSelector::QFileSelector(QWidget * parent, QPushButton *button, QLabel *label)
	:	QWidget(parent),  // Sp�cification du constructeur parent
		// Initialisation du pointeur de fonction
		mComplyFileNameFunction{ nullptr },
		// Type de fen�tre "Open" par d�faut
		mRole{ Role::Open },
		// Largeur du texte maximum : valeur arbitraire
		mMaxLengthToDisplay{ 50 },
		// Titre de la fen�tre "Open" par d�faut
		mOpenTitle("Open file"),
		// Liste des filtres pour la fen�tre "Open" par d�faut (aucun)
		mOpenFilter(),
		// Titre de la fen�tre "Save as" par d�faut
		mSaveAsTitle("Save file as"),
		// Liste des filtres pour la fen�tre "Save as" par d�faut (aucun)
		mSaveAsFilter(),
		// R�pertoire par d�faut lors de l'amorce de la bo�te de dialogue "Open" ou "Save as"
		mCurrentDirectory(),
		// Texte par d�faut lorsqu'aucun fichier n'est s�lectionn�
		mNoFileSelectedString("-"),
		// Texte du bouton
		mButton{ button },
		// Texte de la zone de texte
		mFileName { label }
{
	// D�termine certaines caract�ristiques des widgets
	mFileName->setAlignment(Qt::AlignHCenter);
	mFileName->setText(mNoFileSelectedString);
	mButton->setText("Select a file...");

	// Connecte le signal "clicked" du bouton � la slot "selectFile" de ce widget.
	connect(mButton, &QPushButton::clicked, this, &QFileSelector::selectFile);
}

// Mutateurs
void QFileSelector::setButtonText(const QString & text)
{
	mButton->setText(text);
}

void QFileSelector::setOpen(const QString & openTitle, const QString & openFilter)
{
	mRole = Role::Open;
	mOpenTitle = openTitle;
	mOpenFilter = openFilter;
}

void QFileSelector::setSaveAs(const QString & saveTitle, const QString & saveFilter)
{
	mRole = Role::SaveAs;
	mSaveAsTitle = saveTitle;
	mSaveAsFilter = saveFilter;
}

void QFileSelector::setDir(const QString & dir)
{
	mCurrentDirectory = dir;
}

void QFileSelector::setNoFileSelectedText(const QString & text)
{
	mNoFileSelectedString = text;
}

void QFileSelector::setComplyFileNameFunction(ComplyFileNameFunction complyFileNameFunction)
{
	mComplyFileNameFunction = complyFileNameFunction;
}

// Accesseurs
bool QFileSelector::isFileSelected() const
{
	return !mSelectedFile.isEmpty();
}

const QString & QFileSelector::selectedFile() const
{
	return mSelectedFile;
}

QString QFileSelector::getFileName()
{
	switch (mRole) {
		case Role::Open:
			return QFileDialog::getOpenFileName(this, mOpenTitle, mCurrentDirectory, mOpenFilter);
		case Role::SaveAs:
			return QFileDialog::getSaveFileName(this, mSaveAsTitle, mCurrentDirectory, mSaveAsFilter);
			break;
	}
	return QString();
}

// Fonctions utilitaires
// Fait la s�lection de fichier en faisant l'a�guillage du type de bo�te de dialogue
void QFileSelector::selectFile()
{
	QString userSelectedFile(getFileName());

	if (userSelectedFile != mSelectedFile) {
		mSelectedFile = userSelectedFile;
		if (mSelectedFile.isEmpty()) {
			mFileName->setText("-");
			mFileName->setToolTip("");
		} else {
			mFileName->setText(mComplyFileNameFunction ? mComplyFileNameFunction(mSelectedFile, mMaxLengthToDisplay) : shortenFileName());
			mFileName->setToolTip(mSelectedFile);
		}

		emit fileChanged(mSelectedFile);
	}
}

// Applique une strat�gie de conformit� de nom de fichier par d�faut.
// Lorsque le pointeur de fonction mComplyFileNameFunction n'est pas d�fini, 
// on utilise cette fonction.
// Autrement dit, lorsque l'utilisateur n'a pas assigner une fonction 
// personnalis�e de conformit�, cette fonction est une fonction substitue par 
// d�faut.
QString QFileSelector::shortenFileName() const
{
	if (mSelectedFile.length() <= mMaxLengthToDisplay) {
		return mSelectedFile;
	}

	return QString('.', 3) + mSelectedFile.right(mMaxLengthToDisplay);
}
