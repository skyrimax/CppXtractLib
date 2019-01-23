#ifndef SYMBOL_MATCH_OUT_RANGE_H
#define SYMBOL_MATCH_OUT_RANGE_H


#include "SymbolMatchInRange.h"


// La classe SymbolMatchInRange est une classe de
// comparateur. Son role est de comparer si le
// symbole est � l'ext�rieur des borne d�finies.
// Les bornes sont incluses dans la comparaison.
class SymbolMatchOutRange : public SymbolMatchInRange
{
public:
	// Constructeur d�finissant les deux bornes
	// � \0, est �galement par d�faut.
	SymbolMatchOutRange() = default;
	// Constructeur permettant de d�finir les
	// deux bornes.
	SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol);
	// Destructeur par d�faut.
	virtual ~SymbolMatchOutRange() = default;
	// Constructeur de copie par d�faut.
	SymbolMatchOutRange(const SymbolMatchOutRange & symbComp) = default;
	// Surchargeur d'op�rateur par d�faut.
	SymbolMatchOutRange& operator=(const SymbolMatchOutRange & symbComp) = default;

	// Compare si le symbole est � l'ext�rieur des bornes,
	// les bornes sont incluse dans la comparaison.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_OUT_RANGE_H