#include "SymbolDistinctAny.h"
/*
Frédéric Grondines
2019-01-23
Version 0.11
*/


//Implantation du deuxième constructeur, le premier étant par défaut.
//On initialise la classe parent (SymbolMAtchAny())
//Ce constructeur reçoit un symbole.
SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol)
	:SymbolMatchAny()
{
}


//Implantation du troisième constructeur.
//On initialise la classe parent (SymbolMAtchAny())
//Ce constructeur reçoit une liste de symboles.
SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}


//Implantation du quatrième constructeur.
//On initialise la classe parent (SymbolMAtchAny()).
//Ce constructeur reçoit une liste de symboles.
SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}


//C'est l'implantation de la fonction virtuelle imposée du parent
//Pour cette classe, cette fonction fera l'inverse de SymbolMatchAny::compare(symbol_t symbol)
bool SymbolDistinctAny::compare(symbol_t symbol) const
{
	return !SymbolMatchAny::compare(symbol);
}