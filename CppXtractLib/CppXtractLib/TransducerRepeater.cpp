#include "TransducerRepeater.h"

/*Fonction qui va retourner le symbole
acutuellement trait�*/

std::string TransducerRepeater::transduce(symbol_t symbol)
{
	return std::string(1,symbol);
}
