#include "TransducerReporter.h"
#include "Reporter.h"

// Note: Le rôle de la classe TransducteurReporter
//		 est donné à la page 12 du cahier de laboratoire

//Constructeur de la classe
TransducerReporter::TransducerReporter(Reporter * reporter)
	: Transducer(), mReporter{ reporter }
{
}

//Destructeur
TransducerReporter::~TransducerReporter()
{
	delete mReporter;
}

//Mutateur de mReporter
void TransducerReporter::setReporter(Reporter * reporter)
{
	delete mReporter;
	mReporter = reporter;
}

// Appel la fonctioon report de l'objet de type Reporteur
// si celui-ci est assigné, sinon retourne une chaine de
// de caractère vide.
std::string TransducerReporter::transduce(symbol_t symbol)
{
	if (mReporter)
	{
		return mReporter->report();
	}
	else
	{
		return std::string();
	}
}