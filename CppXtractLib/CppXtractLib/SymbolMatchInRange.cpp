#include "SymbolMatchInRange.h"
#include <algorithm>

// 1a) Constructeur de la classe ici
SymbolMatchInRange::SymbolMatchInRange()
	: SymbolComparator()
{
	mFirstSymbol = '\0';
	mLastSymbol = '\0';
}

// 1b) Constructeur de la classe ici
SymbolMatchInRange::SymbolMatchInRange(symbol_t firstSymbol, symbol_t lastSymbol)
{
	mFirstSymbol = firstSymbol;
	mLastSymbol = lastSymbol;
}


// 2) Implanter la fonction membre qui retourne la valeur de 
//    mFirstSymbol et mLastSymbol par la liste de paramètres
void SymbolMatchInRange::range(symbol_t & firstSymbol, symbol_t & lastSymbol) const
{
	firstSymbol = mFirstSymbol;
	lastSymbol = mLastSymbol;
}


// 3) Implanter la fonction membre qui régle la valeur de 
//    mFirstSymbol et mLastSymbol
void SymbolMatchInRange::setRange(symbol_t firstSymbol, symbol_t lastSymbol)
{
	mFirstSymbol = firstSymbol;
	mLastSymbol = lastSymbol;
}


// 4) Implantation de la fonction (purement virtuelle) compare()
bool SymbolMatchInRange::compare(symbol_t symbol) const
{
	return ((symbol >= mFirstSymbol) and (symbol <= mLastSymbol));
}