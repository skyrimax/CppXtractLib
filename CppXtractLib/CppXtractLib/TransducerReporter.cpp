#include "TransducerReporter.h"
#include "Reporter.h"

TransducerReporter::TransducerReporter(Reporter * reporter)
	: Transducer(), mReporter{ reporter }
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
	if (mReporter)
	{
		return mReporter->report();
	}
	else
	{
		return std::string();
	}
}