#ifndef SYMBOL_MATCH_OUT_RANGE_H
#define SYMBOL_MATCH_OUT_RANGE_H
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

#include "SymbolMatchInRange.h"


//! \brief 
// Boundary symbols are excluded
class SymbolMatchOutRange : public SymbolMatchInRange
{
public:
	SymbolMatchOutRange() = default;
	SymbolMatchOutRange(symbol_t firstSymbol, symbol_t lastSymbol);
	virtual ~SymbolMatchOutRange() = default;
	SymbolMatchOutRange(const SymbolMatchOutRange & symbComp) = default;
	SymbolMatchOutRange& operator=(const SymbolMatchOutRange & symbComp) = default;

	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_OUT_RANGE_H