#ifndef STRING_READER_H
#define STRING_READER_H


#include "Reader.h"
#include <sstream>


// Classe représentant un intrant de type chaîne de caractèrespour un FST.
// Ainsi, l'automate peut lire directement à partir d'une chaîne de caractères.
class StringReader : public Reader
{
public:
	// Constructeur par défaut disponible.
	StringReader() = default;
	// Constructeur avec chaîne de caractères à lire.
	StringReader(const std::string & text);
	// Destructeur par défaut disponible.
	virtual ~StringReader() = default;
	// Constructeur de copie par défaut disponible.
	StringReader(const StringReader & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	StringReader& operator=(const StringReader & symbComp) = default;

	// Détermine la chaîne de caractères à lire.
	void setString(const std::string & text);

	bool isAvailable() const override;

protected:
	std::stringstream mInputString;

	symbol_t readOneFromSource() override;
};


#endif // STRING_READER_H