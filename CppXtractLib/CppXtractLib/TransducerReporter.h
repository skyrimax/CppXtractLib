#ifndef TRANSDUCER_REPORTER_H
#define TRANSDUCER_REPORTER_H


#include "Transducer.h"

class Reporter;


//! \brief 
// TransducerReporter is owner of Reporter* by mReporter.
class TransducerReporter : public Transducer
{
public:
	TransducerReporter(Reporter * reporter = nullptr);
	virtual ~TransducerReporter();
	TransducerReporter(const TransducerReporter & transducer) = delete;
	TransducerReporter& operator=(const TransducerReporter & transducer) = delete;

	void setReporter(Reporter * reporter);

	std::string transduce(symbol_t symbol) override;

protected:
	Reporter * mReporter;
};


#endif // TRANSDUCER_REPORTER_H