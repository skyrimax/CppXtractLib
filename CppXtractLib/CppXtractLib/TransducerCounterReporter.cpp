#include "TransducerCounterReporter.h"


#include <sstream>
#include <iomanip>
#include "TransducerCounter.h"

//Constructeur
TransducerCounterReporter::TransducerCounterReporter(int offsetCounter)
	: Reporter(), mOffsetCounter{ offsetCounter }
{
}

void TransducerCounterReporter::addTransducerCounter(TransducerCounter * transducerCounter)
{
	mTransducerCounters.push_back(transducerCounter);
}

void TransducerCounterReporter::setFormat(size_t width, char fillChar)
{
	mWidth = width;
	mFillChar = fillChar;
}

void TransducerCounterReporter::setOffsetCounter(int offsetCounter)
{
	mOffsetCounter = offsetCounter;
}

std::string TransducerCounterReporter::report()
{
	int count{ mOffsetCounter };
	for (auto counter : mTransducerCounters)
	{
		count += static_cast<int>(counter->count());
	}

	std::stringstream strStream;
	strStream << std::setw(mWidth) << std::setfill(mFillChar) << count;
	return strStream.str();
}