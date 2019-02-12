#ifndef TRANSDUCER_STATIC_WRITER_H
#define TRANSDUCER_STATIC_WRITER_H


#include "Transducer.h"


// Classe transducteur retournant une chaîne de caractères fixe.
class TransducerStaticWriter : public Transducer
{
public:
	// Constructeur par défaut disponible.
	TransducerStaticWriter(std::string const & text = "");
	// Destructeur par défaut disponible.
	virtual ~TransducerStaticWriter() = default;
	// Constructeur de copie par défaut disponible.
	TransducerStaticWriter(const TransducerStaticWriter & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	TransducerStaticWriter& operator=(const TransducerStaticWriter & transducer) = default;

	// Accesseur de la chaîne de caractères à afficher.
	std::string text() const;
	// Mutateur de la chaîne de caractères à afficher.
	void setText(std::string const & text);

	std::string transduce(symbol_t symbol);

protected:
	std::string mText;
};


#endif // TRANSDUCER_STATIC_WRITER_H