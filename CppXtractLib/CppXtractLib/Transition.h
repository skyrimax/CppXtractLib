#ifndef TRANSITION_H
#define TRANSITION_H


#include "Symbol.h"
#include <list>
#include <string>

class State;
class SymbolComparator;
class Transducer;


// La classe Transition repr�sente une transition de l�automate.
// Transition n�est pas propri�taire de l��tat suivant (mNextState).
// Transition est propri�taire du comparateur (mSymbolComparator) et des 
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

	// D�termine l��tat suivant si la transition est effective.
	// Attention, la transition n�est pas propri�taire de l��tat 
	// suivant.
	// Param : - state est un pointeur vers l��tat suivant. 
	void setNextState(State * state);
	// D�termine le comparateur. Si un comparateur est d�j� associ�,
	// ce dernier est lib�r� avant d��tre remplac�.
	// Attention, la classe Transition devient propri�taire du 
	// comparateur qui lui est associ�. 
	// Param : - compareSymbol est un pointeur vers un comparateur
	// 			allou� dynamiquement. 
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