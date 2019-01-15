#include "TransducerReporter.h"
#include "Reporter.h"
//Frédéric Grondines
//Version 0.1
//2019-01-15

/*Constructeur et création du Transducer.*/
TransducerReporter::TransducerReporter(Reporter * reporter)
	:Transducer(), mReporter{reporter}
{
}

/*Libération de la mémoire de l'objet pointé lors
de la destruction de l'objet.*/
TransducerReporter::~TransducerReporter()
{
	delete mReporter;
}

/*Libération de l'ancienne mémoire du pointeur
et ensuite assignation du nouvel objet*/
void TransducerReporter::setReporter(Reporter * reporter)
{
	delete mReporter;
	mReporter = reporter;
}

/*Une chaîne de charactère sera retourner par l'objet pointer
par le pointeur. La chaîne de charactère est générée par le 
Reporter, soi-disant, la fonction report. Un test est fait 
afin de voir si un objet est existant.*/
std::string TransducerReporter::transduce(symbol_t symbol)
{
	if (mReporter)
	{
		return mReporter->report();
	}
	else {
		return std::string();
	}
}