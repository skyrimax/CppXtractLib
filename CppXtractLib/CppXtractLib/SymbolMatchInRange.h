#ifndef SYMBOL_MATCH_IN_RANGE_H
#define SYMBOL_MATCH_IN_RANGE_H


#include "SymbolComparator.h"


// La classe SymbolMatchInRange est une classe de
// comparateur. Son role est de comparer si le
// symbole est entre les borne définies. Les bornes
// sont incluses dans la comparaison.
class SymbolMatchInRange : public SymbolComparator
{
public:
	// Constructeur définissant les deux bornes
	// à \0.
	SymbolMatchInRange();
	// Constructeur permettant de définir les
	// deux bornes.
	SymbolMatchInRange(symbol_t firstSymbol = '\n', symbol_t lastSymbol='\n');
	// Destructeur par défaut.
	virtual ~SymbolMatchInRange() = default;
	// Constructeur de copie par défaut.
	SymbolMatchInRange(const SymbolMatchInRange & symbComp) = default;
	// Surchargeur d'opérateur par défaut.
	SymbolMatchInRange& operator=(const SymbolMatchInRange & symbComp) = default;

	// Accesseur des valeurs des deux borne au
	// travers de ses deux paramêtres.
	void range(symbol_t & firstSymbol, symbol_t & lastSymbol) const;
	// Mutateur des bornes.
	void setRange(symbol_t firstSymbol, symbol_t lastSymbol);

	// Compare si le symbole est compris entre les bornes,
	// les bornes sont incluse dans la comparaison.
	bool compare(symbol_t symbol) const override;

protected:
	// Bornes supérieure et inférieure.
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};


#endif // SYMBOL_MATCH_IN_RANGE_H