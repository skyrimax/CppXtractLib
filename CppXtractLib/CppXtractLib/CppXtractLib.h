#ifndef XTRACT_H
#define XTRACT_H


#include "FST.h"

class TransducerCounter;

namespace cppXtractLib
{
	//! \brief 
	// CppXtract est une classe permettant le traitement des commentaires C/C++.
	// C'est une version sp�cifique de la classe g�n�rique FST. Le constructeur
	// de CppXtract construit les diagrammes d'�tats-transitions de l'automate
	// et toutes les initialisations requises.
	class CppXtract : public FST
	{
	public:
		CppXtract();
		~CppXtract() = default;
		CppXtract(const CppXtract & x) = delete;
		CppXtract& operator=(const CppXtract & x) = delete;
		// Retourne le nombre de caract�res blancs
		size_t spaceCount() const;
		// Retourne le nombre de lignes
		size_t lineCount() const;
		// Retourne le nombre de caract�res lus
		size_t charCount() const;
		// Retourne le nombre de commentaires style-C
		size_t cStyleCommentCount() const;
		// Retourne le nombre de commentaires style-C++
		size_t cppStyleCommentCount() const;
		// Retourne le nombre de cha�nes de caract�res lit�rales
		size_t stringLiteralCount() const;
		// Retourne le nombre de caract�res lit�raux
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