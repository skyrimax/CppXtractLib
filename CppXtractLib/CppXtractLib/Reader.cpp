#include "Reader.h"



symbol_t Reader::lastSymbol() const 
{ 
	return mLastSymbol; 
}

symbol_t Reader::readOne() 
{ 
	mLastSymbol = isAvailable() ? readOneFromSource() : '\0'; 
	return mLastSymbol; 
}

