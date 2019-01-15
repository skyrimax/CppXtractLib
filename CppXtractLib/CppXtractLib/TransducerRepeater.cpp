#include "TransducerRepeater.h"

// Retourne la chaîne de caractère
std::string TransducerRepeater::transduce(symbol_t symbol) {

	return std::string(1,symbol);

}