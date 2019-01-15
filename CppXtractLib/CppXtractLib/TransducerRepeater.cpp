#include "TransducerRepeater.h"
//Frédéric Grondines
//Version 0.1
//2019-01-15

/*Fonction qui va retourner le symbole
acutuellement traité*/

std::string TransducerRepeater::transduce(symbol_t symbol)
{
	return std::string(1,symbol);
}
