#include "SymbolMatchOutRange.h"
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

// 1a) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolMatchOutRange::SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol)
//     N'oubliez pas d'initialiser la classe parent.
SymbolMatchOutRange::SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol)
	:SymbolMatchInRange()
{

}

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on fait l'inverse (négation) de la fonction compare() du parent.
//    Autrement dit, l'action de symbolMatchOutRange::compare(symbol_t symbol)
//    est simplement l'inverse de SymbolMatchInRange::compare(symbol)

bool SymbolMatchOutRange::compare(symbol_t symbol) const
{

}

