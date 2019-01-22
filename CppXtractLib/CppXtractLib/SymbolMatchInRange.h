#ifndef SYMBOL_MATCH_IN_RANGE_H
#define SYMBOL_MATCH_IN_RANGE_H
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

#include "SymbolComparator.h"


//! \brief 
// Boundary symbols are included
class SymbolMatchInRange : public SymbolComparator
{
public:
	SymbolMatchInRange();
	SymbolMatchInRange(symbol_t firstSymbol, symbol_t lastSymbol);
	virtual ~SymbolMatchInRange() = default;
	SymbolMatchInRange(const SymbolMatchInRange & symbComp) = default;
	SymbolMatchInRange& operator=(const SymbolMatchInRange & symbComp) = default;

	void range(symbol_t & firstSymbol, symbol_t & lastSymbol) const;
	void setRange(symbol_t firstSymbol, symbol_t lastSymbol);

	bool compare(symbol_t symbol) const override;

protected:
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};


#endif // SYMBOL_MATCH_IN_RANGE_H