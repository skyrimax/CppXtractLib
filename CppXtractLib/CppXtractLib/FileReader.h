#ifndef FILE_READER_H
#define FILE_READER_H


#include "Reader.h"
#include <fstream>


// Classe repr�sentant un intrant de type fichier pour un FST.
// Ainsi, l'automate peut lire directement � partir d'un fichier 
// texte.
class FileReader : public Reader
{
public:
	// Constructeur par d�faut disponible.
	FileReader() = default;
	// Constructeur avec nom de fichier � ouvrir. Pour savoir si 
	// l'ouverture est r�ussie, il faut valider avec la fonction isAvailable.
	FileReader(const std::string & inputFileName);
	// Destructeur par d�faut disponible.
	virtual ~FileReader() = default;
	// Constructeur de copie par d�faut disponible.
	FileReader(const FileReader & reader) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
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