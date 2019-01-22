#ifndef SYMBOL_DISTINCT_ONE_H
#define SYMBOL_DISTINCT_ONE_H
/*
Frédéric Grondines
2019-01-22
Version 0.1
*/

#include "SymbolMatchOne.h"


//! \brief 
class SymbolDistinctOne : public SymbolMatchOne
{
public:
	SymbolDistinctOne(symbol_t symbol = '\0');
	virtual ~SymbolDistinctOne() = default;
	SymbolDistinctOne(const SymbolDistinctOne & symbComp) = default;
	SymbolDistinctOne& operator=(const SymbolDistinctOne & symbComp) = default;

	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ONE_H