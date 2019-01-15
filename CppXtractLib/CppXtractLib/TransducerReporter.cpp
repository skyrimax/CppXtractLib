#include "TransducerReporter.h"
#include "Reporter.h"
//Fr�d�ric Grondines
//Version 0.1
//2019-01-15

/*Constructeur et cr�ation du Transducer.*/
TransducerReporter::TransducerReporter(Reporter * reporter)
	:Transducer(), mReporter{reporter}
{
}

/*Lib�ration de la m�moire de l'objet point� lors
de la destruction de l'objet.*/
TransducerReporter::~TransducerReporter()
{
	delete mReporter;
}

/*Lib�ration de l'ancienne m�moire du pointeur
et ensuite assignation du nouvel objet*/
void TransducerReporter::setReporter(Reporter * reporter)
{
	delete mReporter;
	mReporter = reporter;
}

/*Une cha�ne de charact�re sera retourner par l'objet pointer
par le pointeur. La cha�ne de charact�re est g�n�r�e par le 
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