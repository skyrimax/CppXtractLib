#ifndef TRANSDUCER_STATIC_WRITER_H
#define TRANSDUCER_STATIC_WRITER_H


#include "Transducer.h"


// Classe transducteur retournant une cha�ne de caract�res fixe.
class TransducerStaticWriter : public Transducer
{
public:
	// Constructeur par d�faut disponible.
	TransducerStaticWriter(std::string const & text = "");
	// Destructeur par d�faut disponible.
	virtual ~TransducerStaticWriter() = default;
	// Constructeur de copie par d�faut disponible.
	TransducerStaticWriter(const TransducerStaticWriter & transducer) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	TransducerStaticWriter& operator=(const TransducerStaticWriter & transducer) = default;

	// Accesseur de la cha�ne de caract�res � afficher.
	std::string text() const;
	// Mutateur de la cha�ne de caract�res � afficher.
	void setText(std::string const & text);

	std::string transduce(symbol_t symbol);

protected:
	std::string mText;
};


#endif // TRANSDUCER_STATIC_WRITER_H