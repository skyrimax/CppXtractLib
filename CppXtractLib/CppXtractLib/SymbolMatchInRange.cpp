#include "SymbolMatchInRange.h"
#include <algorithm>
/*
Frédéric Grondines
2019-01-23
Version 0.11
*/


//Implantation du premier constructeur.
//On initialise la classe parent (SymbolComparator())
//On initialise mLAstSymbol et mFirstSymbol à \0
SymbolMatchInRange::SymbolMatchInRange(): SymbolComparator(), mLastSymbol{'\0'}, mFirstSymbol{'\0'}
{
}


//Implantation du premier constructeur.
//On initialise la classe parent (SymbolComparator())
//On initialise mLAstSymbol et mFirstSymbol à leur paramètre respectif reçu dans la fonction
SymbolMatchInRange::SymbolMatchInRange(symbol_t firstSymbol, symbol_t lastSymbol)
	: SymbolComparator()
{
	mLastSymbol = lastSymbol;
	mFirstSymbol = firstSymbol;
}


//Fonction qui permet d'accèder à la section protected et de retourner la valeur de\
	mFirstSymbol et de mLastSymbol
void SymbolMatchInRange::range(symbol_t & firstSymbol, symbol_t & lastSymbol) const
{
	firstSymbol = mFirstSymbol;
	lastSymbol = mLastSymbol;
}


//Fonction qui va modifier la valeur de mFirstSymbol et mLastSymbol qui se trouve\
	dans la section protected
void SymbolMatchInRange::setRange(symbol_t firstSymbol, symbol_t lastSymbol)
{
	mFirstSymbol = firstSymbol;
	mLastSymbol = lastSymbol;
}


//Implantation de la fonction virtuelle qui va renvoyer True si\
	symbol >= mFirstSymbol et symbol >= mLastSymbol
bool SymbolMatchInRange::compare(symbol_t symbol) const
{
	if (symbol >= mFirstSymbol and symbol >= mLastSymbol)
	{
		return 1;
	}
	return 0;
}
