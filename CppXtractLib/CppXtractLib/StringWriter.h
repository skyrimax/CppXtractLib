#ifndef STRING_WRITER_H
#define STRING_WRITER_H


#include "Writer.h"
#include <sstream>

// Classe repr�sentant un extrant de type cha�ne de caract�res pour un FST.
// Ainsi, l'automate peut produire sa sortie directement dans une cha�ne 
// de caract�res.
class StringWriter : public Writer
{
public:
	// Constructeur par d�faut disponible.
	StringWriter() = default;
	// Destructeur par d�faut disponible.
	virtual ~StringWriter() = default;
	// Constructeur de copie par d�faut disponible.
	StringWriter(const StringWriter & symbComp) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	StringWriter& operator=(const StringWriter & symbComp) = default;

	// R�initialise la cha�ne de caract�res
	void reset();
	// Retourne la cha�ne de caract�res g�n�r�e.
	std::string string() const;

	void write(symbol_t symbol) override;
	void write(const std::string & text) override;
	bool isAvailable() const override;

protected:
	std::stringstream mOutputString;
};


#endif // STRING_WRITER_H