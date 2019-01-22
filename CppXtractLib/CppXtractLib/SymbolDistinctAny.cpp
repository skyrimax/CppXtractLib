#include "SymbolDistinctAny.h"
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

// 1a) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol = '\0')
//     N'oubliez pas d'initialiser la classe parent.
SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol)
	:SymbolMatchAny()
{
}

// 1b) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}

// 1c) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on fait l'inverse (négation) de la fonction compare() du parent.
//    Autrement dit, l'action de SymbolDistinctAny::compare(symbol_t symbol)
//    est simplement l'inverse de SymbolMatchAny::compare(symbol_t symbol)
bool SymbolDistinctAny::compare(symbol_t symbol) const
{
	return !SymbolMatchAny::compare(symbol);
}