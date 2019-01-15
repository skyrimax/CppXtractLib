#include "TransducerCounterReporter.h"
#include <sstream>
#include <iomanip>
#include "TransducerCounter.h"
//Frédéric Grondines
//Version 0.1
//2019-01-15

/*Constructeur et création du parent et initialisation
du mOffsetCounter.*/
TransducerCounterReporter::TransducerCounterReporter(int offsetCounter)
	:Reporter(),mOffsetCounter{offsetCounter}
{
}

/*Création de la liste qui contient des 
addresses de type TransducteurCounter. La fonction
push_back ajouter des items en reculant les anciens.*/
void TransducerCounterReporter::addTransducerCounter(TransducerCounter * transducerCounter)
{
	mTransducerCounters.push_back(transducerCounter);
}

/*Assignation pour le format d'affichage,
avoir de belles colonnes et bien lisible.
mWidth est le nombre de caractère à afficher.*/
void TransducerCounterReporter::setFormat(size_t width, char fillChar)
{
	mWidth = width ;
	mFillChar = fillChar;
}


void TransducerCounterReporter::setOffsetCounter(int offsetCounter)
{
	mOffsetCounter = offsetCounter;
}

/*La boucle parcour la liste d'objet de TransducerCounter
pour compter les caractères. La fonction count() est dans l'objet
TransducerCounter.*/
std::string TransducerCounterReporter::report()
{
	int count{ mOffsetCounter };
	for (auto counter : mTransducerCounters) {
		count += static_cast<int>(counter->count());
	}

	std::stringstream strStream;
	strStream << std::setw(mWidth) << std::setfill(mFillChar) << count;
	return strStream.str();
}