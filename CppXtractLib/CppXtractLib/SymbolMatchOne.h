#ifndef SYMBOL_MATCH_ONE_H
#define SYMBOL_MATCH_ONE_H


#include "SymbolComparator.h"


// La classe SymbolDistinctOne est une classe de
// comparateur. Son role est de comparer si le
// symbol est identique � celui sp�cifier.
class SymbolMatchOne : public SymbolComparator
{
public:
	// Constructeur permettant de sp�cifier le symbole
	SymbolMatchOne(symbol_t symbol = '\0');
	// Destructeur par d�faut.
	virtual ~SymbolMatchOne() = default;
	// Constructeur de copie par d�faut.
	SymbolMatchOne(const SymbolMatchOne & symbComp) = default;
	// Surchargeur d'op�ration par d�faut.
	SymbolMatchOne& operator=(const SymbolMatchOne & symbComp) = default;

	// Mutateur d�f�nissant le synmbole de comparaison.
	void setSymbol(symbol_t symbol);
	// Accesseur retournant le symbole de comparaison.
	symbol_t symbol() const;

	// Compare si le sympole est identique � celui sp�cifi�.
	bool compare(symbol_t symbol) const;

protected:
	//Symbole de comparaison.
	symbol_t mSymbol;
};


#endif // SYMBOL_MATCH_ONE_H