#include "SymbolDistinctOne.h"

// 1) Constructeur de la classe ici
//    Le seul constructeur à implanter est:
//    SymbolDistinctOne::SymbolDistinctOne(symbol_t symbol = '\0')
//    N'oubliez pas d'initialiser la classe parent
SymbolDistinctOne::SymbolDistinctOne(symbol_t symbol = '\0') : SymbolMatchOne()
{
}

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on fait l'inverse (négation) de la fonction compare() du parent.
//    Autrement dit, l'action de SymbolDistinctOne::compare(symbol_t symbol)
//    est simplement l'inverse de SymbolMatchOne::compare(symbol_t symbol)
bool SymbolDistinctOne::compare(symbol_t symbol) const
{
	return !SymbolMatchOne::compare(symbol);
}
