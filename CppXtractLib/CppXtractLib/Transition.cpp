#include "Transition.h"
#include "State.h"
#include "SymbolComparator.h"
#include "Transducer.h"


// 1a) Implanter le constructeur
//     Transition(State * nextState, SymbolComparator * symbolComparator)
//     N'oubliez pas d'initialiser les variables membres mNextState,
//     mSymbolComparator
Transition::Transition(State * nextState, SymbolComparator * symbolComparator) 
	: mNextState{ nextState }, mSymbolComparator{ symbolComparator } 
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
	delete mSymbolComparator; 
	mSymbolComparator = compareSymbol; 
}

// 6) Ajouter un transducteur dans la liste des transducteurs
//   Note: EMPÊCHER deux tranducteurs identiques dans
//         la liste des traducteurs
void Transition::addTransducer(Transducer * transducer) 
{
	//if (contains(mTransducers, transducer)) { 
	//	throw std::invalid_argument("Transducer already included"); 
	//} else { 
	//	mTransducers.push_back(transducer); 
	//} 
	std::list<Transducer*>::iterator it;
	it = std::find(mTransducers.begin(), mTransducers.end(), transducer);
	if (it == mTransducers.end())
		mTransducers.push_back(transducer);
}

// 7) Est-ce que les conditions de transition ont été satisfaites?
//    Note: utiliser la fonction polymorphique compare() du comparateur 
//          pour obtenir cette réponse.
bool Transition::isTransiting(symbol_t symbol) const 
{ 
	return mSymbolComparator ? mSymbolComparator->compare(symbol) : false; 
}

// 8) Exécuter les actions associées à la transition.
//    Note: parcourir la liste des transducteurs et utiliser la fonction
//          polymorphique transduce() pour accomplir cette tâche
std::string Transition::transduce(symbol_t symbol) 
{
	std::string transducedString;
	for (auto transducer : mTransducers) {
		transducedString += transducer->transduce(symbol);
	}
	return transducedString;
}
