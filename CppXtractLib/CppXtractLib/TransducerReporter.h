// TransducerReporter.h
// Maxime Royal
// Version 1.0

#ifndef TRANSDUCER_REPORTER_H
#define TRANSDUCER_REPORTER_H


#include "Transducer.h"

class Reporter;


// La classe TransducerReporter retourner une chaine de
// caractères généré par un autre objet de type
// Reporter.
// TransducerReporter is owner of Reporter* by mReporter.
class TransducerReporter : public Transducer
{
public:
	// Constructeur, construit aussi Transducer et initialise
	// le pointeur reporter à nullptr.
	TransducerReporter(Reporter * reporter = nullptr);
	// Destructeur, supprime également l"objet de type
	// Reporeter pointé par reporter.
	virtual ~TransducerReporter();
	// ???
	TransducerReporter(const TransducerReporter & transducer) = delete;
	// ???
	TransducerReporter& operator=(const TransducerReporter & transducer) = delete;

	// Assigne un nouvel objet de type Reporter au pointeur
	// reporteur après avoir supprimé un potentiel objet
	// dèjà assigné.
	void setReporter(Reporter * reporter);

	// Appel la fonctioon report de l'objet de type Reporteur
	// si celui-ci est assigné, sinon retourne une chaine de
	// de caractère vide.
	std::string transduce(symbol_t symbol) override;

protected:
	Reporter * mReporter;
};


#endif // TRANSDUCER_REPORTER_H