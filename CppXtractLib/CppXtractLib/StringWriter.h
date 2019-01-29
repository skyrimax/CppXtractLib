#ifndef STRING_WRITER_H
#define STRING_WRITER_H


#include "Writer.h"
#include <sstream>

// Classe représentant un extrant de type chaîne de caractères pour un FST.
// Ainsi, l'automate peut produire sa sortie directement dans une chaîne 
// de caractères.
class StringWriter : public Writer
{
public:
	// Constructeur par défaut disponible.
	StringWriter() = default;
	// Destructeur par défaut disponible.
	virtual ~StringWriter() = default;
	// Constructeur de copie par défaut disponible.
	StringWriter(const StringWriter & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	StringWriter& operator=(const StringWriter & symbComp) = default;

	// Réinitialise la chaîne de caractères
	void reset();
	// Retourne la chaîne de caractères générée.
	std::string string() const;

	void write(symbol_t symbol) override;
	void write(const std::string & text) override;
	bool isAvailable() const override;

protected:
	std::stringstream mOutputString;
};


#endif // STRING_WRITER_H