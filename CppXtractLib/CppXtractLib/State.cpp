#include "State.h"
#include "Transition.h"

// 1a) Implanter le constructeur
//     N'oubliez pas d'initialiser la variable membre mAccepting
State::State(bool accepting) : mAccepting(accepting)
{
}
// 1b) Implanter le destructeur
//     N'oubliez pas de détruire les transitions contenues dans la liste
State::~State()
{
	for (auto const & s : mTransitions) {
		delete s;
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
//    Note 1: EMPÊCHER deux transitions identiques d'être
//            dans la liste de transitions
//    Note 2: Utiliser la technique de l'ajout d'un symbole dans la
//            liste des symboles d'un comparateur pour réaliser cette
//            fonction membre
void State::addTransition(Transition * transition)
{
	if (std::find(mTransitions.begin(), mTransitions.end(), transition) == mTransitions.end()) {
		mTransitions.push_back(transition);
	}
}


// 5) Retourner la transition dont les conditions de
//    transition sont satisfaites. Sinon, retourner nullptr
Transition* State::isTransiting(symbol_t symbol) const
{
	for (auto const & s : mTransitions) {
		if (s->isTransiting(symbol))
		{
			return s;
		}
	}
	return nullptr;
}
