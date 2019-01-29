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
//     La transition possède (propriétaire) d'un mSymbolComparator - il faut le
//     détruire. Elle possède N transducteurs, il faut les détruire.
//     Ne pas détruire mNextState puisque la transition n'est pas le
//     propriétaire de l'état.
Transition::~Transition()
{
	delete mSymbolComparator;
	
	for (auto transducer : mTransducers) {
		delete transducer;
	}
}

// 2) Retouner le contenu de mNextState qui représente l'état
//    destination (prochain état) de la transition. 
State* Transition::nextState() const
{
	return mNextState;
}

// 3) Retourner le comparateur de la transition
SymbolComparator* Transition::symbolComparator() const
{
	return mSymbolComparator;
}


// 4) Régler l'objet mNextState qui représente l'état
//    destination (prochain état) de la transition
void Transition::setNextState(State * state)
{
	mNextState = state;
}

// 5) Régler l'objet comparateur qui représente le comparateur
//    de symboles de la transition
void Transition::setComparator(SymbolComparator * compareSymbol)
{
	mSymbolComparator = compareSymbol;
}

// 6) Ajouter un transducteur dans la liste des transducteurs
//    Note 1: EMPÊCHER deux tranducteurs identiques dans
//            la liste des traducteurs
//    Note 2: Utiliser la technique de l'ajout d'un symbole dans la
//            liste des symboles d'un comparateur pour réaliser cette
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

// 7) Est-ce que les conditions de transition ont été satisfaites?
//    Note: utiliser la fonction polymorphique compare() du comparateur 
//          pour obtenir cette réponse.
bool Transition::isTransiting(symbol_t symbol) const
{
	return mSymbolComparator->compare(symbol);
}


// 8) Exécuter les actions associées à la transition.
//    Note: parcourir la liste des transducteurs et utiliser la fonction
//          polymorphique transduce() pour accomplir cette tâche
std::string Transition::transduce(symbol_t symbol)
{
	std::string str;
	for (auto transducer : mTransducers) {
		str+=transducer->transduce(symbol);
		
	}
	return str;
}