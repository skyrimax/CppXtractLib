#ifndef TRANSDUCER_COUNTER_REPORTER_H
#define TRANSDUCER_COUNTER_REPORTER_H

#include "Reporter.h"
#include <list>

class TransducerCounter;


//! \brief 
class TransducerCounterReporter : public Reporter
{
public:
	TransducerCounterReporter(int offsetCounter = 0);
	virtual ~TransducerCounterReporter() = default;
	TransducerCounterReporter(const TransducerCounterReporter & transducer) = default;
	TransducerCounterReporter& operator=(const TransducerCounterReporter & transducer) = default;

	void addTransducerCounter(TransducerCounter * transducerCounter);
	void setFormat(size_t width, char fillChar);
	void setOffsetCounter(int offsetCounter);

	std::string report() override;

protected:
	int mOffsetCounter;
	std::list<TransducerCounter*> mTransducerCounters;
	size_t mWidth{ 0 };
	char mFillChar{ ' ' };
};


#endif // TRANSDUCER_COUNTER_REPORTER_H