#ifndef Q_FILE_SELECTOR_H							// Garde fou (Header Guard)
#define Q_FILE_SELECTOR_H


#include <QWidget>									// Inclusion du fichier QWidget n�cessaire pour l'h�ritage de QFileSelector.

// Section des "Forward d�clarations". 
// L'inclusion compl�te des "*.h" n'est pas n�cessaire ici puisque seulement des pointeurs d'objet sont utilis�s.
// N�anmoins, les inclusions sont n�cessaires dans le cpp.
class QPushButton;									// Forward d�claration du QPushButton.
class QLabel;										// Forward d�claration du QLabel.



// D�claration du Widget QFileSelector.
// 
// Ce widget sert � offrir un widget permettant de s�lectionner un fichier et de le voir � l'�cran.
// Deux r�les existent pour ce widget :
//	- ouverture d'un fichier : Role::Open
//	- enregistrer sous pour un fichier : Role::SaveAs
// Ce sont les mutateurs "setOpen" et "setSaveAs" qui d�terminent le r�le.
//
// Il est possible de formater le nom du fichier � l'�cran selon les besoins. 
// Le mutateur "setComplyFileNameFunction" permet de d�finir cette fonction.
// La signature de la fonction � passer est : QString (*)(const QString &, size_t)
//	- la valeur de retour est le nom du fichier format�
//	- le premier param�tre est le nom de fichier original
//	- le deuxi�me param�tre est la taille du nom de fichier utilis�e pour r�aliser le formatage.
//
// L'accesseur "selectedFile" retourne le nom du fichier s�lectionn�.
//
// Le signal "fileChanged" est �mit lorsque l'utilisateur change de fichier.
// 
class QFileSelector : public QWidget
{
	Q_OBJECT

public:
	// Constructeur. 
	QFileSelector(QWidget * parent = nullptr);
	// Note : les 5 autres fonctions obligatoires par d�faut sont valides!

	// Type utilitaire servant � simplifier la syntaxe d'un pointeur de fonction.
	using ComplyFileNameFunction = QString(*)(const QString &, size_t);

	// Accesseurs
	bool isFileSelected() const;							// Accesseur utilitaire retournant vrai si le fichier s�lectionn� n'est pas vide.
	const QString & selectedFile() const;					// Accesseur retournant le fichier s�lectionn� par l'usager.

	// Mutateurs
	void setButtonText(const QString & buttonText);			// Mutateur d�finissant le texte � afficher sur le bouton du s�lecteur.
	void setOpen(const QString & openTitle,					// Mutateur d�terminant le r�le du QFileSelector � Role::Open.
				 const QString & openFilter = QString());	// D�fini aussi les textes qui seront affich�s dans la bo�te de dialogue.

	void setSaveAs(const QString & saveTitle, 
				   const QString & saveFilter = QString());	// Mutateur d�terminant le r�le du QFileSelector � Role::SaveAs.
															// D�fini aussi les textes qui seront affich�s dans la bo�te de dialogue.
	void setDir(const QString & dir);						// Mutateur d�finissant le dossier d'accueil de la bo�te de dialogue.
	void setNoFileSelectedText(const QString & text);		// Mutateur d�finissant le texte � afficher lorsqu'aucun fichier n'est s�lectionn�.
	void setComplyFileNameFunction(ComplyFileNameFunction complyFileNameFunction);
															// Mutateur d�finissant la fonction qui rendra conforme le nom de fichier pour l'affichage.

	// Signaux (tous les signaux sont public)
signals:
	void fileChanged(const QString & filename);		// Signal �mit lorque le fichier est modifi�.

private:
	// Variables membres
	ComplyFileNameFunction mComplyFileNameFunction;	// Pointeur de fonction vers la fonction r�alisant la conformit� du nom � afficher.
	enum class Role { Open, SaveAs };				// Type repr�sentant les deux r�les possibles du QFileSelector.
	Role mRole;										// Role du FileSelector.
	QString mSelectedFile;							// Le fichier s�lectionn� - vide si le fichier n'a jamais �t� s�lectionn� ou si l'utilisateur a appuy� sur "cancel".
	
	size_t mMaxLengthToDisplay;						// La longueur maximum du nom de fichier � afficher.
	QString mOpenTitle, mOpenFilter;				// Les textes � afficher dans la bo�te de dialogue "open".
	QString mSaveAsTitle, mSaveAsFilter;			// Les textes � afficher dans la bo�te de dialogue "save as".
	QString mCurrentDirectory;						// Le dossier d'accueil lorqu'une bo�te de dialogue ouvre.
	QString mNoFileSelectedString;					// Le texte � afficher lorsqu'aucun fichier n'est s�lectionn�.

	QPushButton * mButton;							// Le bouton.
	QLabel * mFileName;								// Le label servant � l'affichage � l'�cran.

	QString getFileName();							// Fonction utilitaire priv�e servant � appeler la bo�te de dialogue pour obtenir le nom de fichier.
	QString shortenFileName() const;				// Fonction utilitaire priv�e servant � racourcir le nom du fichier simplement.

	// Slots priv�es
private slots:
	void selectFile();								// Slot servant � r�aliser l'action lorsque l'usager appuie sur le bouton "S�lectionner fichier...".

};

#endif // Q_FILE_SELECTOR_H
