#include "SymbolDistinctAny.h"
/*
Fr�d�ric Grondines
2019-01-23
Version 0.11
*/


//Implantation du deuxi�me constructeur, le premier �tant par d�faut.
//On initialise la classe parent (SymbolMAtchAny())
//Ce constructeur re�oit un symbole.
SymbolDistinctAny::SymbolDistinctAny(symbol_t symbol)
	:SymbolMatchAny()
{
}


//Implantation du troisi�me constructeur.
//On initialise la classe parent (SymbolMAtchAny())
//Ce constructeur re�oit une liste de symboles.
SymbolDistinctAny::SymbolDistinctAny(const std::list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}


//Implantation du quatri�me constructeur.
//On initialise la classe parent (SymbolMAtchAny()).
//Ce constructeur re�oit une liste de symboles.
SymbolDistinctAny::SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols)
	:SymbolMatchAny()
{
}


//C'est l'implantation de la fonction virtuelle impos�e du parent
//Pour cette classe, cette fonction fera l'inverse de SymbolMatchAny::compare(symbol_t symbol)
bool SymbolDistinctAny::compare(symbol_t symbol) const
{
	return !SymbolMatchAny::compare(symbol);
}