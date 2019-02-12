#ifndef TRANSITION_H
#define TRANSITION_H


#include "Symbol.h"
#include <list>
#include <string>

class State;
class SymbolComparator;
class Transducer;


// La classe Transition représente une transition de l’automate.
// Transition n’est pas propriétaire de l’état suivant (mNextState).
// Transition est propriétaire du comparateur (mSymbolComparator) et des 
// transducteurs (mTransducers).
// Note:
// Transition is not owner of mNextState
// Transition is owner of mSymbolComparator
// Transition is owner of all Transducer* in mTransducers
class Transition
{
public:
	Transition(State * nextState = nullptr, SymbolComparator * symbolComparator = nullptr);
	~Transition();
	Transition(const Transition & transition) = delete;
	Transition& operator=(const Transition & transition) = delete;

	State* nextState() const;
	SymbolComparator* symbolComparator() const;

	// Détermine l’état suivant si la transition est effective.
	// Attention, la transition n’est pas propriétaire de l’état 
	// suivant.
	// Param : - state est un pointeur vers l’état suivant. 
	void setNextState(State * state);
	// Détermine le comparateur. Si un comparateur est déjà associé,
	// ce dernier est libéré avant d’être remplacé.
	// Attention, la classe Transition devient propriétaire du 
	// comparateur qui lui est associé. 
	// Param : - compareSymbol est un pointeur vers un comparateur
	// 			alloué dynamiquement. 
	void setComparator(SymbolComparator * compareSymbol);
	void addTransducer(Transducer * transducer);

	bool isTransiting(symbol_t symbol) const;

	std::string transduce(symbol_t symbol);

private:
	State * mNextState;
	SymbolComparator * mSymbolComparator;
	std::list<Transducer*> mTransducers;
};


#endif // TRANSITION_H