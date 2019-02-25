#ifndef Q_FILE_SELECTOR_H
#define Q_FILE_SELECTOR_H

// Inclusion du fichier QWidget nécessaire pour l'héritage de QFileSelector.
#include <QWidget>

// Déclaration anticipée 
class QPushButton;			// Pour le bouton du QFileSelector
class QLabel;				// Pour l'étiquette du QFileSelector

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
	QFileSelector(QWidget * parent = nullptr, QPushButton *button = nullptr, QLabel *label = nullptr);

	// Type utilitaire servant à simplifier la syntaxe d'un pointeur de fonction.
	using ComplyFileNameFunction = QString(*)(const QString &, size_t);

	// Accesseurs
	// Fonction membre retournant vrai si le fichier sélectionné n'est pas vide.
	bool isFileSelected() const;
	// Fonction membre retournant le fichier sélectionné par l'usager.
	const QString & selectedFile() const;

	// Mutateurs
	// Fonction membre définissant le texte à afficher sur le bouton du sélecteur.
	void setButtonText(const QString & buttonText);
	// Mutateur déterminant le rôle du QFileSelector à Role::Open.
	// Définir aussi les textes qui seront affichés dans la boîte de dialogue.
	void setOpen(const QString & openTitle, const QString & openFilter = QString());
	// Mutateur déterminant le rôle du QFileSelector à Role::SaveAs.
	// Défini aussi les textes qui seront affichés dans la boîte de dialogue.
	void setSaveAs(const QString & saveTitle, const QString & saveFilter = QString());	
	// Mutateur définissant le dossier d'accueil de la boîte de dialogue.
	void setDir(const QString & dir);
	// Mutateur définissant le texte à afficher lorsqu'aucun fichier n'est sélectionné.
	void setNoFileSelectedText(const QString & text);
	// Mutateur définissant la fonction qui rendra conforme le nom de fichier pour l'affichage.
	void setComplyFileNameFunction(ComplyFileNameFunction complyFileNameFunction);

	// Ajout de mutateurs
	// Fonction membre pour activer/désactiver le bouton et l'étiquette de texte
	void setEnabled(bool b);

	// Signaux (tous les signaux sont public)
signals:
	// Signal émit lorsque le fichier est modifié.
	void fileChanged(const QString & filename);

private:
	// Variables membres
	// Pointeur de fonction vers la fonction réalisant la conformité du nom à afficher.
	ComplyFileNameFunction mComplyFileNameFunction;
	// Type représentant les deux rôles possibles du QFileSelector.
	enum class Role { Open, SaveAs };
	// Role du FileSelector.
	Role mRole;
	// Le fichier sélectionné - vide si le fichier n'a jamais été sélectionné 
	// ou si l'utilisateur a appuyé sur "cancel".
	QString mSelectedFile;
	// La longueur maximum du nom de fichier à afficher.
	size_t mMaxLengthToDisplay;
	// Les textes à afficher dans la boîte de dialogue "open".
	QString mOpenTitle, mOpenFilter;
	// Les textes à afficher dans la boîte de dialogue "save as".
	QString mSaveAsTitle, mSaveAsFilter;
	// Le dossier d'accueil lorqu'une boîte de dialogue ouvre.
	QString mCurrentDirectory;
	// Le texte à afficher lorsqu'aucun fichier n'est sélectionné.
	QString mNoFileSelectedString;
	// Le bouton.
	QPushButton * mButton;
	// Le label servant à l'affichage à l'écran.
	QLabel * mFileName;
	// Fonction utilitaire privée servant à appeler la boîte de dialogue
	// pour obtenir le nom de fichier.
	QString getFileName();
	// Fonction utilitaire privée servant à racourcir le nom du fichier simplement.
	QString shortenFileName() const;

	// Slots privées
private slots:
	// Slot servant à réaliser l'action lorsque l'usager appuie 
	// sur le bouton "Sélectionner fichier...".
	void selectFile();

};

#endif // Q_FILE_SELECTOR_H
