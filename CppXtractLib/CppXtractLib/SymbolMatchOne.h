#ifndef SYMBOL_MATCH_ONE_H
#define SYMBOL_MATCH_ONE_H


#include "SymbolComparator.h"


//! \brief 
class SymbolMatchOne : public SymbolComparator
{
public:
	SymbolMatchOne(symbol_t symbol = '\0');
	virtual ~SymbolMatchOne() = default;
	SymbolMatchOne(const SymbolMatchOne & symbComp) = default;
	SymbolMatchOne& operator=(const SymbolMatchOne & symbComp) = default;

	void setSymbol(symbol_t symbol);
	symbol_t symbol() const;

	bool compare(symbol_t symbol) const;

protected:
	symbol_t mSymbol;
};


#endif // SYMBOL_MATCH_ONE_H