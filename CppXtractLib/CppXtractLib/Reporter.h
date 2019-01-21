// Reporter.h
// Maxime Royal
// Version 1.0

#ifndef REPORTER_H
#define REPORTER_H


#include <string>


// La classe Reporter est une classe abstraite définissant le 
// comportement d’un reporteur.
// Son rôle étant de retourner une chaîne 
// de caractères destinée à la sortie. Si l'action ne génère pas de 
// chaîne de caractères, une chaîne de caractères vide est retournée.
class Reporter
{
public:
	// Constructeur par défaut disponible.
	Reporter() = default;
	// Destructeur par défaut disponible.
	virtual ~Reporter() = default;
	// Constructeur de copie par défaut disponible.
	Reporter(const Reporter & transducer) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	Reporter& operator=(const Reporter & transducer) = default;

	// Effectue l'action requise et retourne, si applicable, 
	// une chaîne de caractères destinée à la sortie.
	virtual std::string report() = 0;
};


#endif // REPORTER_H