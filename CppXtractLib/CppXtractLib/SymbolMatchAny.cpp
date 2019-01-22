#include "SymbolMatchAny.h"
/*
Frédéric Grondines
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

// 1c) Implantation du constructeur acceptant des symboles comme paramètres 
// passés au constructeur
SymbolMatchAny::SymbolMatchAny(const std::initializer_list<symbol_t> & symbols)
	: SymbolComparator()
{ 
	addSymbol(symbols); 
}

// 2a) Implantation de la fonction membre pour ajouter un symbole à l'objet
void SymbolMatchAny::addSymbol(symbol_t symbol) 
{ 
	// Empêche les doublons.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Cette solution est plutôt naïve mais reste plus simple pour le 
	// laboratoire 1 et plus compréhensible pour les étudiants se 
	// familiarisant avec le langage C++.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Les étudiants intéressés pourront considérer l'usage de la classe 
	// std::unordered_set<symbol_t> au lieu de la classe std::list<symbol_t> 
	// comme conteneur de symbol_t.
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	for (auto const & s : mSymbols) {
		if (s == symbol) {
			return;
		}
	}
	mSymbols.push_back(symbol);//Insère le nouveau symbole à la fin de la liste
}

// 2b) Implantation de la fonction membre pour ajouter une liste de symboles 
//     à l'objet
void SymbolMatchAny::addSymbol(const std::list<symbol_t> & symbols)
{ 
	for (auto const & symbol : symbols) {
		addSymbol(symbol);
	}
}

// 2c) Implantation de la Fonction membre pour ajouter des symboles reçus comme 
//     paramètres à l'objet
void SymbolMatchAny::addSymbol(const std::initializer_list<symbol_t> & symbols) 
{ 
	for (auto const & symbol : symbols) {
		addSymbol(symbol);
	}
}

// 3) Implantation de la fonction (purement virtuelle) compare()
//    Ici on compare le symbole symbol reçu en paramètre avec les
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