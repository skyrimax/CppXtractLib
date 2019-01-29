#ifndef STRING_READER_H
#define STRING_READER_H


#include "Reader.h"
#include <sstream>


// Classe repr�sentant un intrant de type cha�ne de caract�respour un FST.
// Ainsi, l'automate peut lire directement � partir d'une cha�ne de caract�res.
class StringReader : public Reader
{
public:
	// Constructeur par d�faut disponible.
	StringReader() = default;
	// Constructeur avec cha�ne de caract�res � lire.
	StringReader(const std::string & text);
	// Destructeur par d�faut disponible.
	virtual ~StringReader() = default;
	// Constructeur de copie par d�faut disponible.
	StringReader(const StringReader & symbComp) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	StringReader& operator=(const StringReader & symbComp) = default;

	// D�termine la cha�ne de caract�res � lire.
	void setString(const std::string & text);

	bool isAvailable() const override;

protected:
	std::stringstream mInputString;

	symbol_t readOneFromSource() override;
};


#endif // STRING_READER_H