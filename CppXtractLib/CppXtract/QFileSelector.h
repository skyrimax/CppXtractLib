#ifndef Q_FILE_SELECTOR_H							// Garde fou (Header Guard)
#define Q_FILE_SELECTOR_H


#include <QWidget>									// Inclusion du fichier QWidget nécessaire pour l'héritage de QFileSelector.

// Section des "Forward déclarations". 
// L'inclusion complète des "*.h" n'est pas nécessaire ici puisque seulement des pointeurs d'objet sont utilisés.
// Néanmoins, les inclusions sont nécessaires dans le cpp.
class QPushButton;									// Forward déclaration du QPushButton.
class QLabel;										// Forward déclaration du QLabel.



// Déclaration du Widget QFileSelector.
// 
// Ce widget sert à offrir un widget permettant de sélectionner un fichier et de le voir à l'écran.
// Deux rôles existent pour ce widget :
//	- ouverture d'un fichier : Role::Open
//	- enregistrer sous pour un fichier : Role::SaveAs
// Ce sont les mutateurs "setOpen" et "setSaveAs" qui déterminent le rôle.
//
// Il est possible de formater le nom du fichier à l'écran selon les besoins. 
// Le mutateur "setComplyFileNameFunction" permet de définir cette fonction.
// La signature de la fonction à passer est : QString (*)(const QString &, size_t)
//	- la valeur de retour est le nom du fichier formaté
//	- le premier paramètre est le nom de fichier original
//	- le deuxième paramètre est la taille du nom de fichier utilisée pour réaliser le formatage.
//
// L'accesseur "selectedFile" retourne le nom du fichier sélectionné.
//
// Le signal "fileChanged" est émit lorsque l'utilisateur change de fichier.
// 
class QFileSelector : public QWidget
{
	Q_OBJECT

public:
	// Constructeur. 
	QFileSelector(QWidget * parent = nullptr);
	// Note : les 5 autres fonctions obligatoires par défaut sont valides!

	// Type utilitaire servant à simplifier la syntaxe d'un pointeur de fonction.
	using ComplyFileNameFunction = QString(*)(const QString &, size_t);

	// Accesseurs
	bool isFileSelected() const;							// Accesseur utilitaire retournant vrai si le fichier sélectionné n'est pas vide.
	const QString & selectedFile() const;					// Accesseur retournant le fichier sélectionné par l'usager.

	// Mutateurs
	void setButtonText(const QString & buttonText);			// Mutateur définissant le texte à afficher sur le bouton du sélecteur.
	void setOpen(const QString & openTitle,					// Mutateur déterminant le rôle du QFileSelector à Role::Open.
				 const QString & openFilter = QString());	// Défini aussi les textes qui seront affichés dans la boîte de dialogue.

	void setSaveAs(const QString & saveTitle, 
				   const QString & saveFilter = QString());	// Mutateur déterminant le rôle du QFileSelector à Role::SaveAs.
															// Défini aussi les textes qui seront affichés dans la boîte de dialogue.
	void setDir(const QString & dir);						// Mutateur définissant le dossier d'accueil de la boîte de dialogue.
	void setNoFileSelectedText(const QString & text);		// Mutateur définissant le texte à afficher lorsqu'aucun fichier n'est sélectionné.
	void setComplyFileNameFunction(ComplyFileNameFunction complyFileNameFunction);
															// Mutateur définissant la fonction qui rendra conforme le nom de fichier pour l'affichage.

	// Signaux (tous les signaux sont public)
signals:
	void fileChanged(const QString & filename);		// Signal émit lorque le fichier est modifié.

private:
	// Variables membres
	ComplyFileNameFunction mComplyFileNameFunction;	// Pointeur de fonction vers la fonction réalisant la conformité du nom à afficher.
	enum class Role { Open, SaveAs };				// Type représentant les deux rôles possibles du QFileSelector.
	Role mRole;										// Role du FileSelector.
	QString mSelectedFile;							// Le fichier sélectionné - vide si le fichier n'a jamais été sélectionné ou si l'utilisateur a appuyé sur "cancel".
	
	size_t mMaxLengthToDisplay;						// La longueur maximum du nom de fichier à afficher.
	QString mOpenTitle, mOpenFilter;				// Les textes à afficher dans la boîte de dialogue "open".
	QString mSaveAsTitle, mSaveAsFilter;			// Les textes à afficher dans la boîte de dialogue "save as".
	QString mCurrentDirectory;						// Le dossier d'accueil lorqu'une boîte de dialogue ouvre.
	QString mNoFileSelectedString;					// Le texte à afficher lorsqu'aucun fichier n'est sélectionné.

	QPushButton * mButton;							// Le bouton.
	QLabel * mFileName;								// Le label servant à l'affichage à l'écran.

	QString getFileName();							// Fonction utilitaire privée servant à appeler la boîte de dialogue pour obtenir le nom de fichier.
	QString shortenFileName() const;				// Fonction utilitaire privée servant à racourcir le nom du fichier simplement.

	// Slots privées
private slots:
	void selectFile();								// Slot servant à réaliser l'action lorsque l'usager appuie sur le bouton "Sélectionner fichier...".

};

#endif // Q_FILE_SELECTOR_H
