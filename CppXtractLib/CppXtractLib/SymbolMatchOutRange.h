#ifndef SYMBOL_MATCH_OUT_RANGE_H
#define SYMBOL_MATCH_OUT_RANGE_H


#include "SymbolMatchInRange.h"


// La classe SymbolMatchInRange est une classe de
// comparateur. Son role est de comparer si le
// symbole est à l'extérieur des borne définies.
// Les bornes sont incluses dans la comparaison.
class SymbolMatchOutRange : public SymbolMatchInRange
{
public:
	// Constructeur définissant les deux bornes
	// à \0, est également par défaut.
	SymbolMatchOutRange() = default;
	// Constructeur permettant de définir les
	// deux bornes.
	SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol);
	// Destructeur par défaut.
	virtual ~SymbolMatchOutRange() = default;
	// Constructeur de copie par défaut.
	SymbolMatchOutRange(const SymbolMatchOutRange & symbComp) = default;
	// Surchargeur d'opérateur par défaut.
	SymbolMatchOutRange& operator=(const SymbolMatchOutRange & symbComp) = default;

	// Compare si le symbole est à l'extérieur des bornes,
	// les bornes sont incluse dans la comparaison.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_OUT_RANGE_H