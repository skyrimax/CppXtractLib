#ifndef READER_H
#define READER_H


#include "Symbol.h"


// Reader est une classe abstraite g�n�rique repr�sentant l'intrant 
// d'un transducteur fini (FST).
//
// Reader est une classe abstraite dont le r�le est de lire un caract�re 
// � la fois � partir d'une source quelconque. Deux fonctions doivent �tre 
// red�finies (override) : 
//		- public: virtual bool isAvailable() const = 0;
//		  Cette fonction doit retourner vrai si Reader est disponible 
//		  (ad�quatement initialis�) et qu'il reste des caract�res � extraire.
//		- protected: virtual symbol_t readOneFromSource() = 0;
//		  Cette fonction extrait un seul symbole du lecteur.
class Reader
{
public:
	// Constructeur par d�faut disponible.
	Reader() = default;
	// Destructeur par d�faut disponible.
	virtual ~Reader() = default;
	// Constructeur de copie par d�faut disponible.
	Reader(const Reader & reader) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	Reader& operator=(const Reader & reader) = default;

	// Retourne le dernier symbole lu. Ne fait pas de lecture dans l'entr�e.
	symbol_t lastSymbol() const;

	// Effectue la lecture d'un symbole dans l'entr�e et le retourne.
	// Cette fonction effectue aussi l'assignation de la lecture � 
	// mLastSymbol.
	symbol_t readOne();

	// D�termine si l'entr�e est disponible pour lire.
	virtual bool isAvailable() const = 0;

protected:
	// Le dernier symbole lu.
	symbol_t mLastSymbol{ '\0' };

	// Effectue la lecture d'un symbole dans l'entr�e et le retourne.
	virtual symbol_t readOneFromSource() = 0;
};


#endif // READER_H