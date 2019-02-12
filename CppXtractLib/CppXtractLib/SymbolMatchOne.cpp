#include "SymbolMatchOne.h"

// 1) Implantation du constructeur acceptant un symbole
SymbolMatchOne::SymbolMatchOne(symbol_t symbol) 
	: mSymbol{ symbol } 
{
}

// 2a) Implantation de la fonction membre pour ajouter un symbole dans l'objet
//     (Mutateur)
void SymbolMatchOne::setSymbol(symbol_t symbol)
{ 
	mSymbol = symbol; 
}

// 2b) Implantation de la fonction membre pour lire le symbole de l'obket
//     (Accesseur)
symbol_t SymbolMatchOne::symbol() const 
{ 
	return mSymbol; 
}

// 3) Implantation de la fonction (purement virtuelle) compare()
//    Ici on compare le symbole symbol reçu en paramètre avec le
//    symbole de l'objet.
//    Retourner true si on trouve symbol dans mSymbol. Retourner
//    false autrement.
bool SymbolMatchOne::compare(symbol_t symbol) const
{ 
	return symbol == mSymbol; 
}
