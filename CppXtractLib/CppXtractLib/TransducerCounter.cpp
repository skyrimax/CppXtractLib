#include "TransducerCounter.h"

// Note: Le rôle de la classe TransducerCounter
//       est donné à la page 12 du cahier de laboratoire

// Constructeur de la classe
TransducerCounter::TransducerCounter()
	: Transducer(), mCount{ 0 }
{
}

// Fonction membre reset()
void TransducerCounter::reset()
{
	mCount = 0;
}

// Fonction membre count()
size_t TransducerCounter::count() const
{
	return mCount;
}

// Fonction membre transduce()
std::string TransducerCounter::transduce(symbol_t symbol)
{
	++mCount;
	return std::string("");
}