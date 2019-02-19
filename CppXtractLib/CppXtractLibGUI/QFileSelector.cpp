#include <QPushButton>											// Pour le bouton
#include <QLabel>												// Pour la zone d'affichage
#include <QFileDialog>											// Pour les boîtes de dialogue "Open" et "Save as"
#include "QFileSelector.h"										// Inclusion du fichier d'en-tête correspondant


// Constructeur
QFileSelector::QFileSelector(QWidget * parent, QPushButton *button, QLabel *label)
	:	QWidget(parent),  // Spécification du constructeur parent
		// Initialisation du pointeur de fonction
		mComplyFileNameFunction{ nullptr },
		// Type de fenêtre "Open" par défaut
		mRole{ Role::Open },
		// Largeur du texte maximum : valeur arbitraire
		mMaxLengthToDisplay{ 50 },
		// Titre de la fenêtre "Open" par défaut
		mOpenTitle("Open file"),
		// Liste des filtres pour la fenêtre "Open" par défaut (aucun)
		mOpenFilter(),
		// Titre de la fenêtre "Save as" par défaut
		mSaveAsTitle("Save file as"),
		// Liste des filtres pour la fenêtre "Save as" par défaut (aucun)
		mSaveAsFilter(),
		// Répertoire par défaut lors de l'amorce de la boîte de dialogue "Open" ou "Save as"
		mCurrentDirectory(),
		// Texte par défaut lorsqu'aucun fichier n'est sélectionné
		mNoFileSelectedString("-"),
		// Texte du bouton
		mButton{ button },
		// Texte de la zone de texte
		mFileName { label }
{
	// Détermine certaines caractéristiques des widgets
	mFileName->setAlignment(Qt::AlignHCenter);
	mFileName->setText(mNoFileSelectedString);
	mButton->setText("Select a file...");

	// Connecte le signal "clicked" du bouton à la slot "selectFile" de ce widget.
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
// Fait la sélection de fichier en faisant l'aïguillage du type de boîte de dialogue
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

// Applique une stratégie de conformité de nom de fichier par défaut.
// Lorsque le pointeur de fonction mComplyFileNameFunction n'est pas défini, 
// on utilise cette fonction.
// Autrement dit, lorsque l'utilisateur n'a pas assigner une fonction 
// personnalisée de conformité, cette fonction est une fonction substitue par 
// défaut.
QString QFileSelector::shortenFileName() const
{
	if (mSelectedFile.length() <= mMaxLengthToDisplay) {
		return mSelectedFile;
	}

	return QString('.', 3) + mSelectedFile.right(mMaxLengthToDisplay);
}
