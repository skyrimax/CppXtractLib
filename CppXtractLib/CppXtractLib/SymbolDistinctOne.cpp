#include "SymbolDistinctOne.h"
/*
Frédéric Grondines
2019-01-23
Version 0.11
*/


//Implantation du constructeur.
//On initialise la classe parent (SymbolMAtchOne()).
//Ce constructeur reçoit un symbole.
SymbolDistinctOne::SymbolDistinctOne(symbol_t symbol)
	:SymbolMatchOne()
{
}


//Implantation de la fonction virtuelle de cette classe
//Elle fait l'inverse de SymbolMatchOne::compare(symbol_t symbol)
bool SymbolDistinctOne::compare(symbol_t symbol) const
{
	return !SymbolMatchOne::compare(symbol);
}