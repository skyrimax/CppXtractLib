#ifndef SCREEN_WRITER_H
#define SCREEN_WRITER_H


#include "Writer.h"
#include <iostream>


// Classe représentant un extrant de type écran pour un FST.
// Ainsi, l'automate peut produire sa sortie directement sur la console.
class ScreenWriter : public Writer
{
public:
	// Constructeur par défaut disponible.
	ScreenWriter() = default;
	// Destructeur par défaut disponible.
	virtual ~ScreenWriter() = default;
	// Constructeur de copie par défaut disponible.
	ScreenWriter(const ScreenWriter & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	ScreenWriter& operator=(const ScreenWriter & symbComp) = default;

	void write(symbol_t symbol) override;
	void write(const std::string & text) override;

	bool isAvailable() const override;
};


#endif // SCREEN_WRITER_H