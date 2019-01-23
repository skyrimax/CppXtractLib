#ifndef SYMBOL_MATCH_IN_RANGE_H
#define SYMBOL_MATCH_IN_RANGE_H


#include "SymbolComparator.h"


// La classe SymbolMatchInRange est une classe de
// comparateur. Son role est de comparer si le
// symbole est entre les borne d�finies. Les bornes
// sont incluses dans la comparaison.
class SymbolMatchInRange : public SymbolComparator
{
public:
	// Constructeur d�finissant les deux bornes
	// � \0.
	SymbolMatchInRange();
	// Constructeur permettant de d�finir les
	// deux bornes.
	SymbolMatchInRange(symbol_t firstSymbol = '\n', symbol_t lastSymbol='\n');
	// Destructeur par d�faut.
	virtual ~SymbolMatchInRange() = default;
	// Constructeur de copie par d�faut.
	SymbolMatchInRange(const SymbolMatchInRange & symbComp) = default;
	// Surchargeur d'op�rateur par d�faut.
	SymbolMatchInRange& operator=(const SymbolMatchInRange & symbComp) = default;

	// Accesseur des valeurs des deux borne au
	// travers de ses deux param�tres.
	void range(symbol_t & firstSymbol, symbol_t & lastSymbol) const;
	// Mutateur des bornes.
	void setRange(symbol_t firstSymbol, symbol_t lastSymbol);

	// Compare si le symbole est compris entre les bornes,
	// les bornes sont incluse dans la comparaison.
	bool compare(symbol_t symbol) const override;

protected:
	// Bornes sup�rieure et inf�rieure.
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};


#endif // SYMBOL_MATCH_IN_RANGE_H