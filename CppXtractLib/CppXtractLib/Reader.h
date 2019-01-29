#ifndef READER_H
#define READER_H


#include "Symbol.h"


// Reader est une classe abstraite générique représentant l'intrant 
// d'un transducteur fini (FST).
//
// Reader est une classe abstraite dont le rôle est de lire un caractère 
// à la fois à partir d'une source quelconque. Deux fonctions doivent être 
// redéfinies (override) : 
//		- public: virtual bool isAvailable() const = 0;
//		  Cette fonction doit retourner vrai si Reader est disponible 
//		  (adéquatement initialisé) et qu'il reste des caractères à extraire.
//		- protected: virtual symbol_t readOneFromSource() = 0;
//		  Cette fonction extrait un seul symbole du lecteur.
class Reader
{
public:
	// Constructeur par défaut disponible.
	Reader() = default;
	// Destructeur par défaut disponible.
	virtual ~Reader() = default;
	// Constructeur de copie par défaut disponible.
	Reader(const Reader & reader) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	Reader& operator=(const Reader & reader) = default;

	// Retourne le dernier symbole lu. Ne fait pas de lecture dans l'entrée.
	symbol_t lastSymbol() const;

	// Effectue la lecture d'un symbole dans l'entrée et le retourne.
	// Cette fonction effectue aussi l'assignation de la lecture à 
	// mLastSymbol.
	symbol_t readOne();

	// Détermine si l'entrée est disponible pour lire.
	virtual bool isAvailable() const = 0;

protected:
	// Le dernier symbole lu.
	symbol_t mLastSymbol{ '\0' };

	// Effectue la lecture d'un symbole dans l'entrée et le retourne.
	virtual symbol_t readOneFromSource() = 0;
};


#endif // READER_H