#ifndef SCREEN_WRITER_H
#define SCREEN_WRITER_H


#include "Writer.h"
#include <iostream>


// Classe repr�sentant un extrant de type �cran pour un FST.
// Ainsi, l'automate peut produire sa sortie directement sur la console.
class ScreenWriter : public Writer
{
public:
	// Constructeur par d�faut disponible.
	ScreenWriter() = default;
	// Destructeur par d�faut disponible.
	virtual ~ScreenWriter() = default;
	// Constructeur de copie par d�faut disponible.
	ScreenWriter(const ScreenWriter & symbComp) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	ScreenWriter& operator=(const ScreenWriter & symbComp) = default;

	void write(symbol_t symbol) override;
	void write(const std::string & text) override;

	bool isAvailable() const override;
};


#endif // SCREEN_WRITER_H