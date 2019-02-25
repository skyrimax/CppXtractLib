#ifndef Q_FILE_SELECTOR_H
#define Q_FILE_SELECTOR_H

// Inclusion du fichier QWidget n�cessaire pour l'h�ritage de QFileSelector.
#include <QWidget>

// D�claration anticip�e 
class QPushButton;			// Pour le bouton du QFileSelector
class QLabel;				// Pour l'�tiquette du QFileSelector

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
	QFileSelector(QWidget * parent = nullptr, QPushButton *button = nullptr, QLabel *label = nullptr);

	// Type utilitaire servant � simplifier la syntaxe d'un pointeur de fonction.
	using ComplyFileNameFunction = QString(*)(const QString &, size_t);

	// Accesseurs
	// Fonction membre retournant vrai si le fichier s�lectionn� n'est pas vide.
	bool isFileSelected() const;
	// Fonction membre retournant le fichier s�lectionn� par l'usager.
	const QString & selectedFile() const;

	// Mutateurs
	// Fonction membre d�finissant le texte � afficher sur le bouton du s�lecteur.
	void setButtonText(const QString & buttonText);
	// Mutateur d�terminant le r�le du QFileSelector � Role::Open.
	// D�finir aussi les textes qui seront affich�s dans la bo�te de dialogue.
	void setOpen(const QString & openTitle, const QString & openFilter = QString());
	// Mutateur d�terminant le r�le du QFileSelector � Role::SaveAs.
	// D�fini aussi les textes qui seront affich�s dans la bo�te de dialogue.
	void setSaveAs(const QString & saveTitle, const QString & saveFilter = QString());	
	// Mutateur d�finissant le dossier d'accueil de la bo�te de dialogue.
	void setDir(const QString & dir);
	// Mutateur d�finissant le texte � afficher lorsqu'aucun fichier n'est s�lectionn�.
	void setNoFileSelectedText(const QString & text);
	// Mutateur d�finissant la fonction qui rendra conforme le nom de fichier pour l'affichage.
	void setComplyFileNameFunction(ComplyFileNameFunction complyFileNameFunction);

	// Ajout de mutateurs
	// Fonction membre pour activer/d�sactiver le bouton et l'�tiquette de texte
	void setEnabled(bool b);

	// Signaux (tous les signaux sont public)
signals:
	// Signal �mit lorsque le fichier est modifi�.
	void fileChanged(const QString & filename);

private:
	// Variables membres
	// Pointeur de fonction vers la fonction r�alisant la conformit� du nom � afficher.
	ComplyFileNameFunction mComplyFileNameFunction;
	// Type repr�sentant les deux r�les possibles du QFileSelector.
	enum class Role { Open, SaveAs };
	// Role du FileSelector.
	Role mRole;
	// Le fichier s�lectionn� - vide si le fichier n'a jamais �t� s�lectionn� 
	// ou si l'utilisateur a appuy� sur "cancel".
	QString mSelectedFile;
	// La longueur maximum du nom de fichier � afficher.
	size_t mMaxLengthToDisplay;
	// Les textes � afficher dans la bo�te de dialogue "open".
	QString mOpenTitle, mOpenFilter;
	// Les textes � afficher dans la bo�te de dialogue "save as".
	QString mSaveAsTitle, mSaveAsFilter;
	// Le dossier d'accueil lorqu'une bo�te de dialogue ouvre.
	QString mCurrentDirectory;
	// Le texte � afficher lorsqu'aucun fichier n'est s�lectionn�.
	QString mNoFileSelectedString;
	// Le bouton.
	QPushButton * mButton;
	// Le label servant � l'affichage � l'�cran.
	QLabel * mFileName;
	// Fonction utilitaire priv�e servant � appeler la bo�te de dialogue
	// pour obtenir le nom de fichier.
	QString getFileName();
	// Fonction utilitaire priv�e servant � racourcir le nom du fichier simplement.
	QString shortenFileName() const;

	// Slots priv�es
private slots:
	// Slot servant � r�aliser l'action lorsque l'usager appuie 
	// sur le bouton "S�lectionner fichier...".
	void selectFile();

};

#endif // Q_FILE_SELECTOR_H
