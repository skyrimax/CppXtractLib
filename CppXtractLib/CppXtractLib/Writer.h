#ifndef WRITER_H
#define WRITER_H


#include "Symbol.h"
#include <string>


// brief Reader est une classe abstraite g�n�rique repr�sentant l'extrant
// d'un transducteur fini (FST).
//
// Writer est une classe abstraite dont le r�le est d'�crire vers une 
// source quelconque. Trois fonctions doivent �tre 
// red�finies (override) : 
//		- public: virtual bool isAvailable() const = 0;
//		  Cette fonction doit retourner vrai si Writer est disponible 
//		  (ad�quatement initialis�) et qu'il reste des caract�res � extraire.
//		- public: virtual void write(symbol_t symbol) = 0;
//		  Cette fonction �crit un symbole.
//		- public: virtual void write(const std::string & text) = 0;
//		  Cette fonction �crit une cha�ne de caract�res.
class Writer
{
public:
	// Constructeur par d�faut disponible.
	Writer() = default;
	// Destructeur par d�faut disponible.
	virtual ~Writer() = default;
	// Constructeur de copie par d�faut disponible.
	Writer(const Writer & symbComp) = default;
	// Op�rateur d'assignation de copie par d�faut disponible.
	Writer& operator=(const Writer & symbComp) = default;

	// Fonction �crivant un symbole � la sortie.
	virtual void write(symbol_t symbol) = 0;
	// Fonction �crivant une cha�ne de caract�res � la sortie.
	virtual void write(const std::string & text) = 0;

	// Fonction d�finissant si la sortie est disponible pour �crire.
	virtual bool isAvailable() const = 0;
};


#endif // WRITER_H