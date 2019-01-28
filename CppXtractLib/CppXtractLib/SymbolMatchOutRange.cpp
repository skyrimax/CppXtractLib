#include "SymbolMatchOutRange.h"

// 1a) Constructeur de la classe ici
SymbolMatchOutRange::SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol)
	:SymbolMatchInRange(firstSymbol, lastSymbol)
{
}


// 2) Implantation de la fonction (purement virtuelle) compare()
bool SymbolMatchOutRange::compare(symbol_t symbol) const
{
	return !SymbolMatchInRange::compare(symbol);
}