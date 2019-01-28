#ifndef STATE_H
#define STATE_H

#include "Symbol.h"
#include <list>

class Transition;

//! \brief 
// State is onwner of all Transition* in mTransitions
// isTransiting(...) return the first valid transition => one path on the state machine
class State
{
public:
	State(bool accepting = false);
	virtual ~State();
	State(const State & state) = delete;			// Copy constructor not available!
	State& operator=(const State & state) = delete;	// Copy assignment operator not available!

	bool isAccepting() const;
	void setAccepting(bool accepting);

	//void addTransition(Transition * transition) { if (find(mTransitions.begin(), mTransitions.end(), transition) == mTransitions.end()) mTransitions.push_back(transition); else throw invalid_argument("Transition already included."); }
	void addTransition(Transition * transition);

	Transition* isTransiting(symbol_t symbol) const;

private:
	bool mAccepting;
	std::list<Transition*> mTransitions;
};


#endif // STATE_H