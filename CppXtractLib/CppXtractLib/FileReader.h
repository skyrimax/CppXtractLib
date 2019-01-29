#ifndef FILE_READER_H
#define FILE_READER_H


#include "Reader.h"
#include <fstream>


// Classe représentant un intrant de type fichier pour un FST.
// Ainsi, l'automate peut lire directement à partir d'un fichier 
// texte.
class FileReader : public Reader
{
public:
	// Constructeur par défaut disponible.
	FileReader() = default;
	// Constructeur avec nom de fichier à ouvrir. Pour savoir si 
	// l'ouverture est réussie, il faut valider avec la fonction isAvailable.
	FileReader(const std::string & inputFileName);
	// Destructeur par défaut disponible.
	virtual ~FileReader() = default;
	// Constructeur de copie par défaut disponible.
	FileReader(const FileReader & reader) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	FileReader& operator=(const FileReader & reader) = default;

	// Ouvre le fichier en lecture.
	bool open(const std::string & inputFileName);
	// Ferme le fichier
	void close();

	bool isAvailable() const override;

protected:
	std::ifstream mInputFile;

	symbol_t readOneFromSource() override;
};


#endif // FILE_READER_H