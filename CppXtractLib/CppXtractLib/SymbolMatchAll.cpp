#include "SymbolMatchAll.h"
/*
Fr�d�ric Grondines
2019-01-22
Version 0.1
*/

// 1) Pas de constructeur � implanter.

// 2) Implantation de la fonction (purement virtuelle) compare()
//    Ici on retourne toujours la valeur true
//    puisque SymbolMatchAll est toujours vrai peu importe le symbole
//    pass� en param�tre.

bool SymbolMatchAll::compare(symbol_t symbol) const
{
	return 1;
}