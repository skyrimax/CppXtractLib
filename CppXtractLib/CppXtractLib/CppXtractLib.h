#ifndef XTRACT_H
#define XTRACT_H


#include "FST.h"

class TransducerCounter;

namespace cppXtractLib
{
	//! \brief 
	// CppXtract est une classe permettant le traitement des commentaires C/C++.
	// C'est une version spécifique de la classe générique FST. Le constructeur
	// de CppXtract construit les diagrammes d'états-transitions de l'automate
	// et toutes les initialisations requises.
	class CppXtract : public FST
	{
	public:
		CppXtract();
		~CppXtract() = default;
		CppXtract(const CppXtract & x) = delete;
		CppXtract& operator=(const CppXtract & x) = delete;
		// Retourne le nombre de caractères blancs
		size_t spaceCount() const;
		// Retourne le nombre de lignes
		size_t lineCount() const;
		// Retourne le nombre de caractères lus
		size_t charCount() const;
		// Retourne le nombre de commentaires style-C
		size_t cStyleCommentCount() const;
		// Retourne le nombre de commentaires style-C++
		size_t cppStyleCommentCount() const;
		// Retourne le nombre de chaînes de caractères litérales
		size_t stringLiteralCount() const;
		// Retourne le nombre de caractères litéraux
		size_t charLiteralCount() const;

	protected:
		TransducerCounter * mTransducerStartBySpaceCounter;
		TransducerCounter * mTransducerStartByLineCounter;
		TransducerCounter * mTransducerStartByCharCounter;
		TransducerCounter * mTransducerSpaceCounter;
		TransducerCounter * mTransducerLineCounter;
		TransducerCounter * mTransducerCharCounter;
		TransducerCounter * mTransducerCStyleCommentCounter;
		TransducerCounter * mTransducerCppStyleCommentCounter;
		TransducerCounter * mTransducerLiteralStringCounter;
		TransducerCounter * mTransducerLiteralCharCounter;

		void initialize() override;
		void writeOptionInfo(Writer & writer) override;
	};
}

#endif // XTRACT_H