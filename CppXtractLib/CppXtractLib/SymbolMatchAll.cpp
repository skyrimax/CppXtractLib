#include "SymbolMatchAll.h"
/*
Frédéric Grondines
2019-01-23
Version 0.11
*/

//Pas de constructeur à implanter.


//La fonction virtuelle de cette classe retourne toujours vrai
bool SymbolMatchAll::compare(symbol_t symbol) const
{
	return 1;
}