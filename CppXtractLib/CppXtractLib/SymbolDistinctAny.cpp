#include "SymbolDistinctAny.h"

// 1a) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol = '\0')
//     N'oubliez pas d'initialiser la classe parent.
SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol) 
	: SymbolMatchAny(symbol)
{ 
}

// 1b) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols) 
	: SymbolMatchAny(symbols)
{ 
}

// 1c) Constructeur de la classe ici
//     Le constructeur à implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols) 
	: SymbolMatchAny(symbols)
{ 
}

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on fait l'inverse (négation) de la fonction compare() du parent.
//    Autrement dit, l'action de SymbolDistinctAny::compare(symbol_t symbol)
//    est simplement l'i
bool SymbolDistinctAny::compare(symbol_t symbol) const 
{ 
	return !SymbolMatchAny::compare(symbol); 
}

