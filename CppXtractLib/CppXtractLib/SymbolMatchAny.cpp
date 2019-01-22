#include "SymbolMatchAny.h"
/*
Fr�d�ric Grondines
2019-01-22
Version 0.1
*/

#include <algorithm>

// 1a) Implantation du constructeur acceptant un symbole
SymbolMatchAny::SymbolMatchAny(symbol_t symbol)
	: SymbolComparator()
{ 
	addSymbol(symbol); 
}

// 1b) Implantation du Constructeur acceptant des symboles dans une liste
SymbolMatchAny::SymbolMatchAny(const std::list<symbol_t> & symbols) 
	: SymbolComparator()
{ 
	addSymbol(symbols); 
}

// 1c) Implantation du constructeur acceptant des symboles comme param�tres 
// pass�s au constructeur
SymbolMatchAny::SymbolMatchAny(const std::initializer_list<symbol_t> & symbols)
	: SymbolComparator()
{ 
	addSymbol(symbols); 
}

// 2a) Implantation de la fonction membre pour ajouter un symbole � l'objet
void SymbolMatchAny::addSymbol(symbol_t symbol) 
{ 
	// Emp�che les doublons.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Cette solution est plut�t na�ve mais reste plus simple pour le 
	// laboratoire 1 et plus compr�hensible pour les �tudiants se 
	// familiarisant avec le langage C++.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Les �tudiants int�ress�s pourront consid�rer l'usage de la classe 
	// std::unordered_set<symbol_t> au lieu de la classe std::list<symbol_t> 
	// comme conteneur de symbol_t.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	for (auto const & s : mSymbols) {
		if (s == symbol) {
			return;
		}
	}
	mSymbols.push_back(symbol);//Ins�re le nouveau symbole � la fin de la liste
}

// 2b) Implantation de la fonction membre pour ajouter une liste de symboles 
//     � l'objet
void SymbolMatchAny::addSymbol(const std::list<symbol_t> & symbols)
{ 
	for (auto const & symbol : symbols) {
		addSymbol(symbol);
	}
}

// 2c) Implantation de la Fonction membre pour ajouter des symboles re�us comme 
//     param�tres � l'objet
void SymbolMatchAny::addSymbol(const std::initializer_list<symbol_t> & symbols) 
{ 
	for (auto const & symbol : symbols) {
		addSymbol(symbol);
	}
}

// 3) Implantation de la fonction (purement virtuelle) compare()
//    Ici on compare le symbole symbol re�u en param�tre avec les
//    symboles de la liste mSymbols.
//    Retourner true si on trouve symbol dans mSymbols. Retourner
//    false autrement.
bool SymbolMatchAny::compare(symbol_t symbol) const 
{ 
	for (auto const & s : mSymbols) { 
		if (symbol == s) {
			return true;
		}
	} 
	
	return false; 
}