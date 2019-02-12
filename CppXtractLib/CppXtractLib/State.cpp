#include "State.h"
#include "Transition.h"

// 1a) Implanter le constructeur
//     N'oubliez pas d'initialiser la variable membre mAccepting
State::State(bool accepting) 
	: mAccepting{ accepting } 
{
}

// 1b) Implanter le destructeur
//     N'oubliez pas de détruire les transitions contenues dans la liste
State::~State()
{ 
	for (auto transition : mTransitions) { 
		delete transition; 
	} 
}

// 2) Accesseur, retourner la valeur mAccepting 
bool State::isAccepting() const 
{ 
	return mAccepting; 
}

// 3) Mutateur, régler la valeur de mAccepting
void State::setAccepting(bool accepting) 
{ 
	mAccepting = accepting; 
}

// 4) Ajouter une transition dans l'état
//    Note: EMPÊCHER deux transitions identiques d'être
//          dans la liste de transitions
void State::addTransition(Transition * transition) 
{ 
	//if (contains(mTransitions, transition)) { 
	//	throw std::invalid_argument("Transition already included"); 
	//} else { 
	//	mTransitions.push_back(transition); 
	//}
	std::list<Transition*>::iterator it;
	it = std::find(mTransitions.begin(), mTransitions.end(), transition);
	if (it == mTransitions.end())
		mTransitions.push_back(transition);

}

// 5) Retourner la transition dont les conditions de
//    transition sont satisfaites. Sinon, retourner nullptr
Transition* State::isTransiting(symbol_t symbol) const
{
	for (auto transition : mTransitions) {
		if (transition->isTransiting(symbol)) {
			return transition;
		}
	}

	return nullptr;
}