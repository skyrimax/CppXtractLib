// TransducerRepporter.h
// Maxime Royal
// version 1.0

#ifndef TRANSDUCER_REPEATER_H
#define TRANSDUCER_REPEATER_H


#include "Transducer.h"


// La classe TransducerReporter retourne le
// symbole qui lui est envoy�.
class TransducerRepeater : public Transducer
{
public:
	// Constructeur par d�faut disponible.
	TransducerRepeater() = default;
	// Destructeur par d�faut disponible.
	virtual ~TransducerRepeater() = default;
	// Constructeur de copie par d�faut disponible.
	TransducerRepeater(const TransducerRepeater & transducer) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	TransducerRepeater& operator=(const TransducerRepeater & transducer) = default;

	// Retourne le symbole qui lui est pass�.
	std::string transduce(symbol_t symbol) override;
};


#endif // TRANSDUCER_REPEATER_H