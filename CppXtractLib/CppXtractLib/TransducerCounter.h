#ifndef TRANSDUCER_COUNTER_H
#define TRANSDUCER_COUNTER_H


#include "Transducer.h"


//! \brief 
class TransducerCounter : public Transducer
{
public:
	TransducerCounter();
	virtual ~TransducerCounter() = default;
	TransducerCounter(const TransducerCounter & transducer) = default;
	TransducerCounter& operator=(const TransducerCounter & transducer) = default;

	void reset();
	size_t count() const;

	std::string transduce(symbol_t symbol) override;

protected:
	size_t mCount;
};


#endif // TRANSDUCER_COUNTER_H