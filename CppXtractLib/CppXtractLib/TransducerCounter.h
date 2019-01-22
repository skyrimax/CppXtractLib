// TransducerCounter.h
// Maxime Royal
// Version 1.0

#ifndef TRANSDUCER_COUNTER_H
#define TRANSDUCER_COUNTER_H


#include "Transducer.h"


// Le role de la classe TransducerCounter
// est de retenir un compte er le retourner
// lorsque demandé.
class TransducerCounter : public Transducer
{
public:
	// Constructeur, construit aussi Transducer
	// et initialise la valeur de mCount.
	TransducerCounter();
	// Destructeur par défaut disponible.
	virtual ~TransducerCounter() = default;
	// Constructeur de copie par défaut disponible.
	TransducerCounter(const TransducerCounter & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	TransducerCounter& operator=(const TransducerCounter & transducer) = default;

	// Réinitialise mCOunt à 0.
	void reset();
	// Retourne la valeur de mCount.
	size_t count() const;

	// Intrément la valeur de mCount
	// et retourne une chaine vide.
	//override est facultatif, il permet de dire au compilateur\
	que l'on va implenter la fonction.
	std::string transduce(symbol_t symbol) override;

protected:
	// Retiens la valeur d'un comptage.
	size_t mCount;
};


#endif // TRANSDUCER_COUNTER_H