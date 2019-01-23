// SymbolDistinctAny.h
// Maxime Royal
// Version 1.0

#ifndef SYMBOL_DISTINCT_ANY_H
#define SYMBOL_DISTINCT_ANY_H


#include "SymbolMatchAny.h"


// La classe SymbolDistinctAny est une classe de
// comparateur. Son role est de comparer si le
// symbol est diff�rent de ceux sp�cifi� par la liste.
class SymbolDistinctAny : public SymbolMatchAny
{
public:
	// Constructeur par d�faut, aucune sp�cification.
	SymbolDistinctAny() = default;
	// Constructeur permettant de sp�cifier un symbole
	// � ajouter � la liste.
	SymbolDistinctAny(symbol_t symbol = '\0');
	// Constructeur permettant d'ajouter les symboles d'une
	// liste pr�d�finie.
	SymbolDistinctAny(const std::list<symbol_t> & symbols);
	// Constructeur permettant de sp�cifier une liste de symboles.
	SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols = { '\0' });
	// Destructeur par d�faut.
	virtual ~SymbolDistinctAny() = default;
	// Constructeur de copie par d�faut.
	SymbolDistinctAny(const SymbolDistinctAny & symbComp) = default;
	// Surchargeur d'op�rateur par d�faut
	SymbolDistinctAny& operator=(const SymbolDistinctAny & symbComp) = default;

	// Compare si le symbole est diff�rent de ceux
	// de la liste.
	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ANY_H