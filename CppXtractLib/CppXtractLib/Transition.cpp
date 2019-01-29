#include "Transition.h"


#include "State.h"
#include "SymbolComparator.h"
#include "Transducer.h"



// 1a) Implanter le constructeur
//     Transition(State * nextState, SymbolComparator * symbolComparator)
//     N'oubliez pas d'initialiser les variables membres mNextState,
//     mSymbolComparator
Transition::Transition(State * nextState, SymbolComparator * symbolComparator) 
	:mNextState{nextState},mSymbolComparator{symbolComparator}
{
}


// 1b) Implanter le destructeur
//     La transition poss�de (propri�taire) d'un mSymbolComparator - il faut le
//     d�truire. Elle poss�de N transducteurs, il faut les d�truire.
//     Ne pas d�truire mNextState puisque la transition n'est pas le
//     propri�taire de l'�tat.
Transition::~Transition()
{
	delete mSymbolComparator;
	
	for (auto transducer : mTransducers) {
		delete transducer;
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
void Transition::setNextState(State * state)
{
	mNextState = state;
}

// 5) R�gler l'objet comparateur qui repr�sente le comparateur
//    de symboles de la transition
void Transition::setComparator(SymbolComparator * compareSymbol)
{
	mSymbolComparator = compareSymbol;
}

// 6) Ajouter un transducteur dans la liste des transducteurs
//    Note 1: EMP�CHER deux tranducteurs identiques dans
//            la liste des traducteurs
//    Note 2: Utiliser la technique de l'ajout d'un symbole dans la
//            liste des symboles d'un comparateur pour r�aliser cette
//            fonction membre
void Transition::addTransducer(Transducer * transducer)
{
	for (auto t : mTransducers) {
		if (t == transducer) {
			return;
		}
	}
	mTransducers.push_back(transducer);
}

// 7) Est-ce que les conditions de transition ont �t� satisfaites?
//    Note: utiliser la fonction polymorphique compare() du comparateur 
//          pour obtenir cette r�ponse.
bool Transition::isTransiting(symbol_t symbol) const
{
	return mSymbolComparator->compare(symbol);
}


// 8) Ex�cuter les actions associ�es � la transition.
//    Note: parcourir la liste des transducteurs et utiliser la fonction
//          polymorphique transduce() pour accomplir cette t�che
std::string Transition::transduce(symbol_t symbol)
{
	std::string str;
	for (auto transducer : mTransducers) {
		str+=transducer->transduce(symbol);
		
	}
	return str;
}