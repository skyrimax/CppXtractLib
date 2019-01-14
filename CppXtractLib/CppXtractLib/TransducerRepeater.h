#ifndef TRANSDUCER_REPEATER_H
#define TRANSDUCER_REPEATER_H


#include "Transducer.h"


//! \brief 
class TransducerRepeater : public Transducer
{
public:
	TransducerRepeater() = default;
	virtual ~TransducerRepeater() = default;
	TransducerRepeater(const TransducerRepeater & transducer) = default;
	TransducerRepeater& operator=(const TransducerRepeater & transducer) = default;

	std::string transduce(symbol_t symbol) override;
};


#endif // TRANSDUCER_REPEATER_H