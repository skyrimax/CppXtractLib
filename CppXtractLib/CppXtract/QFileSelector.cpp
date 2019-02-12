#include "QFileSelector.h"										// Inclusion du fichier d'en-t�te correspondant

#include <QPushButton>											// Pour le bouton
#include <QLabel>												// Pour la zone d'affichage
#include <QVBoxLayout>											// Pour le layout vertical
#include <QFileDialog>											// Pour les bo�tes de dialogue "Open" et "Save as"


QFileSelector::QFileSelector(QWidget * parent)					// Constructeur par d�faut
	:	QWidget(parent),										// Sp�cification du constructeur parent
		mComplyFileNameFunction{ nullptr },						// Initialisation du pointeur de fonction
		mRole{ Role::Open },									// Type de fen�tre "Open" par d�faut
		mMaxLengthToDisplay{ 50 },								// Largeur du texte maximum : valeur arbitraire
		mOpenTitle("Open file"),								// Titre de la fen�tre "Open" par d�faut
		mOpenFilter(),											// Liste des filtres pour la fen�tre "Open" par d�faut (aucun)
		mSaveAsTitle("Save file as"),							// Titre de la fen�tre "Save as" par d�faut
		mSaveAsFilter(),										// Liste des filtres pour la fen�tre "Save as" par d�faut (aucun)
		mCurrentDirectory(),									// R�pertoire par d�faut lors de l'amorce de la bo�te de dialogue "Open" ou "Save as"
		mNoFileSelectedString("-"),								// Texte par d�faut lorsqu'aucun fichier n'est s�lectionn�
		mButton { new QPushButton("Select a file...") },		// Cr�ation et texte du bouton
		mFileName { new QLabel(mNoFileSelectedString) }			// Cr�ation et texte de la zone de texte
{
	// D�termine certaines caract�ristiques des widgets
	mFileName->setAlignment(Qt::AlignHCenter);

	// Effectue le montage du layout vertical et l'assigne � soi-m�me, le widget
	QVBoxLayout * layout{ new QVBoxLayout };
	layout->addWidget(mButton);
	layout->addWidget(mFileName);
	setLayout(layout);

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
