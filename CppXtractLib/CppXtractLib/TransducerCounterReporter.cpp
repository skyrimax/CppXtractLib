#include "TransducerCounterReporter.h"

#include <sstream>
#include <iomanip>
# include "TransducerCounter.h"

// Constructeur
TransducerCounterReporter::TransducerCounterReporter(int offsetCounter)
	: Reporter(), mOffsetCounter{ offsetCounter }
{
}

// Ajout des amis
void TransducerCounterReporter::addTransducerCounter(TransducerCounter* transducerCounter)
{
	mTransducerCounters.push_back(transducerCounter);
}

void TransducerCounterReporter::setFormat(size_t width, char fillChar)
{
	mWidth = width;
	mFillChar = fillChar;
}

void TransducerCounterReporter::setOffsetCounter(int offsetCounter)
{
	mOffsetCounter = offsetCounter;
}

// Fonction qui fait une liste d'objet sous forme de pointeur.
// Ensuite parcours la liste pour effectuer la fonction count().
// Calcule le compte

std::string TransducerCounterReporter::report()
{
	int count{ mOffsetCounter };
	for (auto counter : mTransducerCounters) {
		count += static_cast<int>(counter->count());	// Static_cast utilisé, quand on est pas sur du retour du type et forcer le type désiré.
	}
	// Concept de flux de caractère.
	std::stringstream strStream;
	strStream << std::setw(mWidth) << std::setfill(mFillChar) << count;
	return strStream.str();
}