#include "Transition.h"

#include "State.h"
#include "SymbolComparator.h"
#include "Transducer.h"

// 1a) Implanter le constructeur
Transition::Transition(State * nextState, SymbolComparator * symbolComparator)
	:mNextState{ nextState }, mSymbolComparator{ symbolComparator }
{
	//mNextState = nextState;
	//mSymbolComparator = symbolComparator;
}

// 1b) Implanter le destructeur
Transition::~Transition()
{
	delete mSymbolComparator;

	for (auto const & t : mTransducers)
	{
		delete t;
	}
}

// 2) Retouner le contenu de mNextState qui repr�sente l'�tat
//    destination (prochain �tat) de la transition.
State* Transition::nextState() const
{
	return mNextState;
}

// 3) Retourner le comparateur de la transition
SymbolComparator* Transition::symbolComparator() const
{
	return mSymbolComparator;
}

// 4) R�gler l'objet mNextState qui repr�sente l'�tat
//    destination (prochain �tat) de la transition
void Transition::setNextState(State* state)
{
	mNextState = state;
}

// 5) R�gler l'objet comparateur qui repr�sente le comparateur
//    de symboles de la transition
void Transition::setComparator(SymbolComparator* compareSymbol)
{
	mSymbolComparator = compareSymbol;
}

// 6) Ajouter un transducteur dans la liste des transducteurs
void Transition::addTransducer(Transducer* transducer)
{
	if (std::find(mTransducers.begin(), mTransducers.end(), transducer) == mTransducers.end())
	{
		mTransducers.push_back(transducer);
	}
}

// 7) Est-ce que les conditions de transition ont �t� satisfaites?
bool Transition::isTransiting(symbol_t symbol) const
{
	return mSymbolComparator->compare(symbol);
}

// 8) Ex�cuter les actions associ�es � la transition.
std::string Transition::transduce(symbol_t symbol)
{
	std::string str{ '\0' };
	for (auto const & t : mTransducers)
	{
		str + t->transduce(symbol);
	}

	return str;
}