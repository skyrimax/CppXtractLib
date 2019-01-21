#include "TransducerRepeater.h"

// Note: Le rôle de la classe TransducerRepeater
//		 est donné à la plage 12 cahier de laboratoire

// Fonction membre transduce()
std::string TransducerRepeater::transduce(symbol_t symbol)
{
	return std::string(1, symbol);
}