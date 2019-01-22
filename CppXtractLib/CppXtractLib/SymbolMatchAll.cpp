#include "SymbolMatchAll.h"
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

// 1) Pas de constructeur à implanter.

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on retourne toujours la valeur true
//    puisque SymbolMatchAll est toujours vrai peu importe le symbole
//    passé en paramètre.

bool SymbolMatchAll::compare(symbol_t symbol) const
{
	return 1;
}