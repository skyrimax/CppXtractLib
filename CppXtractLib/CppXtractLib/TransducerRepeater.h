// TransducerRepporter.h
// Maxime Royal
// version 1.0

#ifndef TRANSDUCER_REPEATER_H
#define TRANSDUCER_REPEATER_H


#include "Transducer.h"


// La classe TransducerReporter retourne le
// symbole qui lui est envoyé.
class TransducerRepeater : public Transducer
{
public:
	// Constructeur par défaut disponible.
	TransducerRepeater() = default;
	// Destructeur par défaut disponible.
	virtual ~TransducerRepeater() = default;
	// Constructeur de copie par défaut disponible.
	TransducerRepeater(const TransducerRepeater & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	TransducerRepeater& operator=(const TransducerRepeater & transducer) = default;

	// Retourne le symbole qui lui est passé.
	std::string transduce(symbol_t symbol) override;
};


#endif // TRANSDUCER_REPEATER_H