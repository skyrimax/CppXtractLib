#include "SymbolDistinctAny.h"

// 1a) Constructeur de la classe ici
//     Le constructeur � implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol = '\0')
//     N'oubliez pas d'initialiser la classe parent.
SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol= '\0') : SymbolMatchAny()
{
	addSymbol(symbol);
}

// 1b) Constructeur de la classe ici
//     Le constructeur � implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols) : SymbolMatchAny()
{
	addSymbol(symbols);
}


// 1c) Constructeur de la classe ici
//     Le constructeur � implanter est:
//     SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols) 
//     N'oubliez pas d'initialiser la classe parent
SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols) : SymbolMatchAny()
{
	addSymbol(symbols);
}


// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on fait l'inverse (n�gation) de la fonction compare() du parent.
//    Autrement dit, l'action de SymbolDistinctAny::compare(symbol_t symbol)
//    est simplement l'inverse de SymbolMatchAny::compare(symbol_t symbol)

bool SymbolDistinctAny::compare(symbol_t symbol) const
{
	//for (auto const & s : mSymbols) {
	//	if (symbol != s) {
	//		return true;
	//	}
	//}

	//return false;
	return !SymbolMatchAny::compare(symbol);


}
