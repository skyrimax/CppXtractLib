#ifndef SYMBOL_MATCH_ONE_H
#define SYMBOL_MATCH_ONE_H
/*
Fr�d�ric Grondines
2019-01-22
Version 0.1
*/

#include "SymbolComparator.h"


//! \brief 
class SymbolMatchOne : public SymbolComparator
{
public:
	SymbolMatchOne(symbol_t symbol = '\0');
	virtual ~SymbolMatchOne() = default;

	//Constructeur de copie. Cr�ation d'un objet � l'aide d'un objet de m�me type.
	SymbolMatchOne(const SymbolMatchOne & symbComp) = default; 

	//Surcharge de l'op�rateur d'assignation (=) pour le type SymbolMatchOne.
	SymbolMatchOne& operator=(const SymbolMatchOne & symbComp) = default;

	void setSymbol(symbol_t symbol);
	symbol_t symbol() const;

	//Fonction obligatoire venant de la classe parent\
	et v�rifie si on a le caract�re que l'on cherche.
	bool compare(symbol_t symbol) const;

protected:
	symbol_t mSymbol;
};


#endif // SYMBOL_MATCH_ONE_H