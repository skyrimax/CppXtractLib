#ifndef SYMBOL_COMPARATOR_H
#define SYMBOL_COMPARATOR_H
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

#include "Symbol.h"


// La classe SymbolComparator est une classe abstraite définissant le 
// comportement d’un comparateur de symbole. 
// Son rôle étant de comparer le symbole et de déterminer s’il 
// correspond à un critère spécifique.
class SymbolComparator
{
public:
	// Constructeur par défaut disponible.
	SymbolComparator() = default;
	// Destructeur par défaut disponible.
	virtual ~SymbolComparator() = default;
	// Constructeur de copie par défaut disponible.
	SymbolComparator(const SymbolComparator & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	SymbolComparator& operator=(const SymbolComparator & symbComp) = default;

	// Compare si le symbole correspond au critère déterminé par la classe.
	virtual bool compare(symbol_t symbol) const = 0;
};


#endif // SYMBOL_COMPARATOR_H