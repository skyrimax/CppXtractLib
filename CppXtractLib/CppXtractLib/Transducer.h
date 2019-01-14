#ifndef TRANSDUCER_H
#define TRANSDUCER_H


#include "Symbol.h"
#include <string>


// La classe Transducer est une classe abstraite définissant le 
// comportement d’un transducteur. 
// Son rôle étant d'effectuer une action et de retourner une chaîne 
// de caractères destinée à la sortie. Si l'action ne génère pas de 
// chaîne de caractères, une chaîne de caractères vide est retournée.
class Transducer
{
public:
	// Constructeur par défaut disponible.
	Transducer() = default;
	// Destructeur par défaut disponible.
	virtual ~Transducer() = default;
	// Constructeur de copie par défaut disponible.
	Transducer(const Transducer & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	Transducer& operator=(const Transducer & transducer) = default;

	// Effectue l'action requise et retourne, si applicable, 
	// une chaîne de caractères destinée à la sortie.
	virtual std::string transduce(symbol_t symbol) = 0;
};


#endif // TRANSDUCER_H