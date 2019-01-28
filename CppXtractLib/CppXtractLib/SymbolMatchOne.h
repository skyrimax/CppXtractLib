#ifndef SYMBOL_MATCH_ONE_H
#define SYMBOL_MATCH_ONE_H


#include "SymbolComparator.h"


// La classe SymbolDistinctOne est une classe de
// comparateur. Son role est de comparer si le
// symbol est identique à celui spécifier.
class SymbolMatchOne : public SymbolComparator
{
public:
	// Constructeur permettant de spécifier le symbole
	SymbolMatchOne(symbol_t symbol = '\0');
	// Destructeur par défaut.
	virtual ~SymbolMatchOne() = default;
	// Constructeur de copie par défaut.
	SymbolMatchOne(const SymbolMatchOne & symbComp) = default;
	// Surchargeur d'opération par défaut.
	SymbolMatchOne& operator=(const SymbolMatchOne & symbComp) = default;

	// Mutateur défénissant le synmbole de comparaison.
	void setSymbol(symbol_t symbol);
	// Accesseur retournant le symbole de comparaison.
	symbol_t symbol() const;

	// Compare si le sympole est identique à celui spécifié.
	bool compare(symbol_t symbol) const;

protected:
	//Symbole de comparaison.
	symbol_t mSymbol;
};


#endif // SYMBOL_MATCH_ONE_H