#ifndef SYMBOL_MATCH_ALL_H
#define SYMBOL_MATCH_ALL_H


#include "SymbolComparator.h"


// La classe SymbolMatchAll est une classe de
// comparateur. SOn role est de comparer si le
// symbole fait partie de l'ASCII, retourne donc
// toujours VRAI.
class SymbolMatchAll : public SymbolComparator
{
public:
	// Constructeur par d�faut.
	SymbolMatchAll() = default;
	// Destructeur par d�faut.
	virtual ~SymbolMatchAll() = default;
	// Constructeur de copie par d�faut.
	SymbolMatchAll(const SymbolMatchAll & symbComp) = default;
	// Surcharge d'op�rateur par d�faut.
	SymbolMatchAll& operator=(const SymbolMatchAll & symbComp) = default;

	// Compare si le symbole fait partie de l'ASCII,
	// retourne donc toujours VRAI.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_ALL_H