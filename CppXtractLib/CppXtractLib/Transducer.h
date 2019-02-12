#ifndef TRANSDUCER_H
#define TRANSDUCER_H


#include "Symbol.h"
#include <string>


// La classe Transducer est une classe abstraite d�finissant le 
// comportement d�un transducteur. 
// Son r�le �tant d'effectuer une action et de retourner une cha�ne 
// de caract�res destin�e � la sortie. Si l'action ne g�n�re pas de 
// cha�ne de caract�res, une cha�ne de caract�res vide est retourn�e.
class Transducer
{
public:
	// Constructeur par d�faut disponible.
	Transducer() = default;
	// Destructeur par d�faut disponible.
	virtual ~Transducer() = default;
	// Constructeur de copie par d�faut disponible.
	Transducer(const Transducer & transducer) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	Transducer& operator=(const Transducer & transducer) = default;

	// Effectue l'action requise et retourne, si applicable, 
	// une cha�ne de caract�res destin�e � la sortie.
	virtual std::string transduce(symbol_t symbol) = 0;
};


#endif // TRANSDUCER_H