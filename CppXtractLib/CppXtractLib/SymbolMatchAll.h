#ifndef SYMBOL_MATCH_ALL_H
#define SYMBOL_MATCH_ALL_H


#include "SymbolComparator.h"


//! \brief 
class SymbolMatchAll : public SymbolComparator
{
public:
	SymbolMatchAll() = default;
	virtual ~SymbolMatchAll() = default;
	SymbolMatchAll(const SymbolMatchAll & symbComp) = default;
	SymbolMatchAll& operator=(const SymbolMatchAll & symbComp) = default;

	bool compare(symbol_t symbol) const override;
};


#endif // SYMBOL_MATCH_ALL_H