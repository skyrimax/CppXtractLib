#include "TransducerCounterReporter.h"

#include<sstream>
#include<iomanip>
#include"TransducerCounter.h"

TransducerCounterReporter::TransducerCounterReporter(int offsetcounter)
	: Reporter(),mOffsetCounter{ offsetcounter }
{
}

void TransducerCounterReporter::addTransducerCounter(TransducerCounter * transducerCounter)
{
	mTransducerCounters.push_back(transducerCounter);
}

void TransducerCounterReporter::setFormat(size_t width , char fillchar)
{
	mWidth = width;
	mFillChar = fillchar;
}

void TransducerCounterReporter::setOffsetCounter(int offsetCounter)
{
	mOffsetCounter = offsetCounter;
}

std::string TransducerCounterReporter::report()
{
	int count{ mOffsetCounter };
	for (auto counter : mTransducerCounters) {
		count += static_cast<int>(counter->count());
	}

	std::stringstream strStream;
	strStream << std::setw(mWidth) << std::setfill(mFillChar) << count;
	return strStream.str();
}