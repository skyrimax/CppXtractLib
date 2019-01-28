// SymbolDistinctOne.h
// Maxime Royal
// Version 1.0

#ifndef SYMBOL_DISTINCT_ONE_H
#define SYMBOL_DISTINCT_ONE_H


#include "SymbolMatchOne.h"


// La classe SymbolDistinctOne est une classe de
// comparateur. Son role est de comparer si le
// symbol est diff�rent de celui sp�cifier.
class SymbolDistinctOne : public SymbolMatchOne
{
public:
	// Constructeur permettant de sp�cifier le symbole.
	SymbolDistinctOne(symbol_t symbol = '\0');
	// Destructeur par d�faut.
	virtual ~SymbolDistinctOne() = default;
	// Constructeur de copie par d�faut.
	SymbolDistinctOne(const SymbolDistinctOne & symbComp) = default;
	// Surchargeur d'op�ration par d�faut.
	SymbolDistinctOne& operator=(const SymbolDistinctOne & symbComp) = default;

	// Compare si le sympole est diff�rent de celui sp�cifi�.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ONE_H