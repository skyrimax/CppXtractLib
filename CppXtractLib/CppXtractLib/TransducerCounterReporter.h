// TransducerCounterReporter.h
// Maxime Royal
// Version 1.0

#ifndef TRANSDUCER_COUNTER_REPORTER_H
#define TRANSDUCER_COUNTER_REPORTER_H


#include "Reporter.h"
#include <list>

class TransducerCounter;


// Le role de créer et afficher un rapport en
//utilisant le compte d'un ou plusieurs
// TransducerCounter.
class TransducerCounterReporter : public Reporter
{
public:
	// Constructeur, construit aussi Transducer
	// et initialise la valeur de mOffsetCounter,
	// par défaut à 0.
	TransducerCounterReporter(int offsetCounter = 0);
	// Destructeur par défaut disponible.
	virtual ~TransducerCounterReporter() = default;
	// Constructeur de copie par défaut disponible.
	TransducerCounterReporter(const TransducerCounterReporter & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	TransducerCounterReporter& operator=(const TransducerCounterReporter & transducer) = default;

	// Ajouter un TransducerCounter à la liste.
	void addTransducerCounter(TransducerCounter * transducerCounter);
	// Définit le format du rapport.
	void setFormat(size_t width, char fillChar);
	// Défnit la valeur de mOffsetCounter
	void setOffsetCounter(int offsetCounter);

	//Génère et affice le rapport.
	std::string report() override;

protected:
	int mOffsetCounter;
	std::list<TransducerCounter*> mTransducerCounters;
	size_t mWidth{ 0 };
	char mFillChar{ ' ' };
};


#endif // TRANSDUCER_COUNTER_REPORTER_H