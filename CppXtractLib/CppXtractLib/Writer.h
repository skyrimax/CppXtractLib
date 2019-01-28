#ifndef WRITER_H
#define WRITER_H


#include "Symbol.h"
#include <string>


// brief Reader est une classe abstraite générique représentant l'extrant
// d'un transducteur fini (FST).
//
// Writer est une classe abstraite dont le rôle est d'écrire vers une 
// source quelconque. Trois fonctions doivent être 
// redéfinies (override) : 
//		- public: virtual bool isAvailable() const = 0;
//		  Cette fonction doit retourner vrai si Writer est disponible 
//		  (adéquatement initialisé) et qu'il reste des caractères à extraire.
//		- public: virtual void write(symbol_t symbol) = 0;
//		  Cette fonction écrit un symbole.
//		- public: virtual void write(const std::string & text) = 0;
//		  Cette fonction écrit une chaîne de caractères.
class Writer
{
public:
	// Constructeur par défaut disponible.
	Writer() = default;
	// Destructeur par défaut disponible.
	virtual ~Writer() = default;
	// Constructeur de copie par défaut disponible.
	Writer(const Writer & symbComp) = default;
	// Opérateur d'assignation de copie par défaut disponible.
	Writer& operator=(const Writer & symbComp) = default;

	// Fonction écrivant un symbole à la sortie.
	virtual void write(symbol_t symbol) = 0;
	// Fonction écrivant une chaîne de caractères à la sortie.
	virtual void write(const std::string & text) = 0;

	// Fonction définissant si la sortie est disponible pour écrire.
	virtual bool isAvailable() const = 0;
};


#endif // WRITER_H