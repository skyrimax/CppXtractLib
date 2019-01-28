#ifndef FILE_WRITER_H
#define FILE_WRITER_H


#include "Writer.h"
#include <fstream>


// Classe représentant un extrant de type fichier pour un FST.
// Ainsi, l'automate peut produire sa sortie directement dans un fichier 
// texte.
class FileWriter : public Writer
{
public:
	// Constructeur par défaut disponible.
	FileWriter() = default;
	// Constructeur avec nom de fichier à ouvrir. Pour savoir si 
	// l'ouverture est réussie, il faut valider avec la fonction isAvailable.
	FileWriter(const std::string & outputFileName);
	// Destructeur par défaut disponible.
	virtual ~FileWriter() = default;
	// Constructeur de copie par défaut disponible.
	FileWriter(const FileWriter & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	FileWriter& operator=(const FileWriter & symbComp) = default;

	// Ouvre le fichier spéficié. Retourne faux se le fichier n'est pas ouvert.
	bool open(const std::string & outputFileName);
	// Ferme le fichier ouvert.
	void close();

	void write(symbol_t symbol) override;
	void write(const std::string & text) override;
	bool isAvailable() const override;

protected:
	std::ofstream mOutputFile;
};


#endif // FILE_WRITER_H