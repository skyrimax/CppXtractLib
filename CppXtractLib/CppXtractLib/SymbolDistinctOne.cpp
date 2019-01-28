#include "SymbolDistinctOne.h"

// 1) Constructeur de la classe ici
SymbolDistinctOne::SymbolDistinctOne(symbol_t symbol)
	: SymbolMatchOne(symbol)
{
}

// 2) Implantation de la fonction (purement virtuelle) compare()
bool SymbolDistinctOne::compare(symbol_t symbol) const
{
	return !SymbolMatchOne::compare(symbol);
}