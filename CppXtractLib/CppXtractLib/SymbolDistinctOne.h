// SymbolDistinctOne.h
// Maxime Royal
// Version 1.0

#ifndef SYMBOL_DISTINCT_ONE_H
#define SYMBOL_DISTINCT_ONE_H


#include "SymbolMatchOne.h"


// La classe SymbolDistinctOne est une classe de
// comparateur. Son role est de comparer si le
// symbol est différent de celui spécifier.
class SymbolDistinctOne : public SymbolMatchOne
{
public:
	// Constructeur permettant de spécifier le symbole.
	SymbolDistinctOne(symbol_t symbol = '\0');
	// Destructeur par défaut.
	virtual ~SymbolDistinctOne() = default;
	// Constructeur de copie par défaut.
	SymbolDistinctOne(const SymbolDistinctOne & symbComp) = default;
	// Surchargeur d'opération par défaut.
	SymbolDistinctOne& operator=(const SymbolDistinctOne & symbComp) = default;

	// Compare si le sympole est différent de celui spécifié.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ONE_H