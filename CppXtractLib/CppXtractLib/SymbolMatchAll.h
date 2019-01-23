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
	// Constructeur par défaut.
	SymbolMatchAll() = default;
	// Destructeur par défaut.
	virtual ~SymbolMatchAll() = default;
	// Constructeur de copie par défaut.
	SymbolMatchAll(const SymbolMatchAll & symbComp) = default;
	// Surcharge d'opérateur par défaut.
	SymbolMatchAll& operator=(const SymbolMatchAll & symbComp) = default;

	// Compare si le symbole fait partie de l'ASCII,
	// retourne donc toujours VRAI.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_ALL_H