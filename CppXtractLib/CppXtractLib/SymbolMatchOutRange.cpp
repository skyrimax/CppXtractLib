#include "SymbolMatchOutRange.h"
/*
Frédéric Grondines
2019-01-23
Version 0.11
*/


//Implantation du premier constructeur.
//On initialise la classe parent (SymbolMatchInRange())
SymbolMatchOutRange::SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol)
	:SymbolMatchInRange()
{

}


//Implantation de la fonction virtuelle héritée du parent et renvoie l'inverse\
	de la fonction SymbolMatchInRange::compare(symbol)
bool SymbolMatchOutRange::compare(symbol_t symbol) const
{
	return !SymbolMatchInRange::compare(symbol);
}

