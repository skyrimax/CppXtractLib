#include "TransducerReporter.h"

#include "Reporter.h"

// Création du constructeur

TransducerReporter::TransducerReporter(Reporter * reporter)

	:Transducer(), mReporter{ reporter } // Initialiser parent avant d'entrer dans les accolades et assigne les variables membres
{
}

TransducerReporter::~TransducerReporter()
{
	delete mReporter;
}

void TransducerReporter::setReporter(Reporter * reporter)
{
	delete mReporter;
	mReporter = reporter;

}

std::string TransducerReporter::transduce(symbol_t symbol)
{
	if (mReporter) {
		return mReporter->report();
	}
	else {
		return std::string();
	}
}