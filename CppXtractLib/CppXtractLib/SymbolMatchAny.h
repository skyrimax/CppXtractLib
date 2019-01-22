#ifndef SYMBOL_MATCH_ANY_H
#define SYMBOL_MATCH_ANY_H
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

#include "SymbolComparator.h"
#include <list>


// Compare si le symbole correspond à au moins un symbole provenant d’une
// liste prédéterminée.
class SymbolMatchAny : public SymbolComparator
{
public:
	// Constructeur par défaut disponible.
	SymbolMatchAny() = default;
	// Constructeur avec un seul symbole.
	SymbolMatchAny(symbol_t symbol);
	// Constructeur avec une liste de symboles (list).
	SymbolMatchAny(const std::list<symbol_t> & symbols);
	// Constructeur par une liste de symboles (initializer_list).
	SymbolMatchAny(const std::initializer_list<symbol_t> & symbols);
	// Destructeur par défaut disponible.
	virtual ~SymbolMatchAny() = default;
	// Constructeur de copie par défaut disponible.
	SymbolMatchAny(const SymbolMatchAny & symbComp) = default;
	// Opérateur d’assignation de copie par défaut disponible.
	SymbolMatchAny& operator=(const SymbolMatchAny & symbComp) = default;
	// Ajoute un symbole à la liste.
	void addSymbol(symbol_t symbol);
	// Ajoute une liste de symboles à la liste (list).
	void addSymbol(const std::list<symbol_t> & symbols);
	// Ajoute une liste de symboles à la liste (initializer_list).
	void addSymbol(const std::initializer_list<symbol_t> & symbols);

	// Effectue la comparaison. Le symbole correspond à au moins 
	// un élément de la liste.
	bool compare(symbol_t symbol) const override;

protected:
	// Voir note dans la fonction : void addSymbol(symbol_t symbol);
	std::list<symbol_t> mSymbols;
};


#endif // SYMBOL_MATCH_ANY_H