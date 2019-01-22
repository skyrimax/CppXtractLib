#ifndef SYMBOL_DISTINCT_ANY_H
#define SYMBOL_DISTINCT_ANY_H


#include "SymbolMatchAny.h"


//! \brief 
class SymbolDistinctAny : public SymbolMatchAny
{
public:
	SymbolDistinctAny() = default;
	SymbolDistinctAny(symbol_t symbol);
	SymbolDistinctAny(const std::list<symbol_t> & symbols);
	SymbolDistinctAny(const std::initializer_list<symbol_t> & symbols);
	virtual ~SymbolDistinctAny() = default;
	SymbolDistinctAny(const SymbolDistinctAny & symbComp) = default;
	SymbolDistinctAny& operator=(const SymbolDistinctAny & symbComp) = default;

	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_DISTINCT_ANY_H