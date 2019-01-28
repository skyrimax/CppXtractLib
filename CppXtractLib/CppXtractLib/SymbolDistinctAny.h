// SymbolDistinctAny.h
// Maxime Royal
// Version 1.0

#ifndef SYMBOL_DISTINCT_ANY_H
#define SYMBOL_DISTINCT_ANY_H


#include "SymbolMatchAny.h"


// La classe SymbolDistinctAny est une classe de
// comparateur. Son role est de comparer si le
// symbol est différent de ceux spécifié par la liste.
class SymbolDistinctAny : public SymbolMatchAny
{
public:
	// Constructeur par défaut, aucune spécification.
	SymbolDistinctAny() = default;
	// Constructeur permettant de spécifier un symbole
	// à ajouter à la liste.
	SymbolDistinctAny(symbol_t symbol = '\0');
	// Constructeur permettant d'ajouter les symboles d'une
	// liste prédéfinie.
	SymbolDistinctAny(const std::list<symbol_t> & symbols);
	// Constructeur permettant de spécifier une liste de symboles.
	SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols = { '\0' });
	// Destructeur par défaut.
	virtual ~SymbolDistinctAny() = default;
	// Constructeur de copie par défaut.
	SymbolDistinctAny(const SymbolDistinctAny & symbComp) = default;
	// Surchargeur d'opérateur par défaut
	SymbolDistinctAny& operator=(const SymbolDistinctAny & symbComp) = default;

	// Compare si le symbole est différent de ceux
	// de la liste.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ANY_H