#include "SymbolMatchInRange.h"
#include <algorithm>

// 1a) Constructeur de la classe ici
//     Le constructeur � implanter est:
//     SymbolMatchInRange::SymbolMatchInRange()
//     N'oubliez pas d'initialiser mFirstSymbol et mLastSymbol � '\0'
//     N'oubliez pas d'initialiser la classe parent.
SymbolMatchInRange::SymbolMatchInRange() 
	: mFirstSymbol{ '\0' }, mLastSymbol{ '\0' }, SymbolComparator()
{
}
// 1b) Constructeur de la classe ici
//     Le constructeur � implanter est:
//     SymbolMatchInRange::SymbolMatchInRange(symbol_t firstSymbol, symbol_t lastSymbol)
//     N'oubliez pas d'initialiser mFirstSymbol et mLastSymbol
//     N'oubliez pas d'initialiser la classe parent
SymbolMatchInRange::SymbolMatchInRange(symbol_t firstSymbol, symbol_t lastSymbol)
	: mFirstSymbol{ '\0' }, mLastSymbol{ '\0' }, SymbolComparator()
{
}


// 2) Implanter la fonction membre qui retourne la valeur de 
//    mFirstSymbol et mLastSymbol par la liste de param�tres
//    SymbolMatchInRange::range(symbol_t & firstSymbol, symbol_t & lastSymbol) const
void SymbolMatchInRange::range(symbol_t & firstSymbol, symbol_t & lastSymbol) const
{
	mFirstSymbol == firstSymbol;
	mLastSymbol == lastSymbol;
}

// 3) Implanter la fonction membre qui r�gle la valeur de 
//    mFirstSymbol et mLastSymbol
//    SymbolMatchInRange::setRange(symbol_t firstSymbol, symbol_t lastSymbol)
void SymbolMatchInRange::setRange(symbol_t firstSymbol, symbol_t lastSymbol)
{
	mFirstSymbol == firstSymbol;
	mLastSymbol == lastSymbol;
}


// 4) Implantation de la fonction (purement virtuelle) compare()
//    Ici on v�rifie que le symbole re�u X en param�tre est effectivement
//    X >= mFirstSymbol et X <= mLastSymbol
bool SymbolMatchInRange::compare(symbol_t symbol) const
{
	if (symbol >= mFirstSymbol and symbol <= mLastSymbol) {
		return true;
	}
	return false;
}
