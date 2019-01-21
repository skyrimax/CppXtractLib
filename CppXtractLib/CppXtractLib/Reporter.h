// Reporter.h
// Maxime Royal
// Version 1.0

#ifndef REPORTER_H
#define REPORTER_H


#include <string>


// La classe Reporter est une classe abstraite d�finissant le 
// comportement d�un reporteur.
// Son r�le �tant de retourner une cha�ne 
// de caract�res destin�e � la sortie. Si l'action ne g�n�re pas de 
// cha�ne de caract�res, une cha�ne de caract�res vide est retourn�e.
class Reporter
{
public:
	// Constructeur par d�faut disponible.
	Reporter() = default;
	// Destructeur par d�faut disponible.
	virtual ~Reporter() = default;
	// Constructeur de copie par d�faut disponible.
	Reporter(const Reporter & transducer) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	Reporter& operator=(const Reporter & transducer) = default;

	// Effectue l'action requise et retourne, si applicable, 
	// une cha�ne de caract�res destin�e � la sortie.
	virtual std::string report() = 0;
};


#endif // REPORTER_H