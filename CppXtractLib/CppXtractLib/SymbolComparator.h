#ifndef SYMBOL_COMPARATOR_H
#define SYMBOL_COMPARATOR_H
/*
Fr�d�ric Grondines
2019-01-22
Version 0.1
*/

#include "Symbol.h"


// La classe SymbolComparator est une classe abstraite d�finissant le 
// comportement d�un comparateur de symbole. 
// Son r�le �tant de comparer le symbole et de d�terminer s�il 
// correspond � un crit�re sp�cifique.
class SymbolComparator
{
public:
	// Constructeur par d�faut disponible.
	SymbolComparator() = default;
	// Destructeur par d�faut disponible.
	virtual ~SymbolComparator() = default;
	// Constructeur de copie par d�faut disponible.
	SymbolComparator(const SymbolComparator & symbComp) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	SymbolComparator& operator=(const SymbolComparator & symbComp) = default;

	// Compare si le symbole correspond au crit�re d�termin� par la classe.
	virtual bool compare(symbol_t symbol) const = 0;
};


#endif // SYMBOL_COMPARATOR_H