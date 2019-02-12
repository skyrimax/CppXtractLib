#include "FST.h"


#include "State.h"
#include "Reader.h"
#include "FileReader.h"
#include "StringReader.h"
#include "Writer.h"
#include "FileWriter.h"
#include "StringWriter.h"
#include "ScreenWriter.h"
#include "Transition.h"

//#include "StlUtilities.h"

// 1) Implanter le destructeur
//    Il faut d�truire les �tats qui se trouvent dans la liste
//    mStates
FST::~FST()
{
	for (auto state : mStates) {
		delete state;
	}
}

// 2) Ajouter un �tat dans le FST
//    Note 1: utiliser la liste mStates
//    Note 2: EMP�CHER deux �tats identiques d'�tre
//          dans la liste mStates
void FST::addState(State * state) 
{ 
	//if (contains(mStates, state)) { 
	//	throw std::invalid_argument("State already included"); 
	//} else { 
	//	mStates.push_back(state); 
	//}
	std::list<State*>::iterator it;
	it = std::find(mStates.begin(), mStates.end(), state);
	if (it == mStates.end())
		mStates.push_back(state);

}

// 3) Ajouter un �tat initial dans le FST
//    Rappel: le FST peut traiter plus d'un diagramme d'�tats � la fois.
//            c'est prouquoi il peut y avoir plus d'un �tat intial.
//    Note 1: utiliser la liste mInitialStates
//    Note 2: EMP�CHER deux �tats identiques d'�tre
//            dans la liste mInitialStates
void FST::addInitialState(State * state) 
{ 
	//if (contains(mInitialStates, state)) { 
	//	throw std::invalid_argument("Initial state already included");
	//} else { 
	//	mInitialStates.push_back(state); 
	//} 
	std::list<State*>::iterator it;
	it = std::find(mInitialStates.begin(), mInitialStates.end(), state);
	if (it == mInitialStates.end())
		mInitialStates.push_back(state);
}

// 4) D�marrer le traitement des symboles Go FST Go!
//    Retourner une liste de bool�ennes pour indiquer les �tat finaux
//    sont des �tats acceptants ou non.
//    Rappel: le FST peut traiter plus d'un diagramme d'�tats � la fois
//            d'o� la n�cessit� de traiter les �tats initiaux et les �tats courants
//            sous forme de listes.
//    Note: doit fournir un objet endant de classe Reader et un objet 
//          endant de classe Writer.
std::list<bool> FST::process(Reader & reader, Writer & writer, bool optionInfo) 
{
	// Initialiser le FST
	initialize();
	// Les �tats initiaux sont maintenant les �tats courants (actuels)
	mCurrentStates = mInitialStates;
	// Traiter les symboles d'entr�e tant et aussi qu'il y en a...
	while (reader.isAvailable() && writer.isAvailable()) {
		// Traiter le symbole...
		processSymbol(reader, writer);
	}
	// Apr�s le traitement de tous les symboles, afficher un message?
	if (optionInfo) {
		writeOptionInfo(writer);
	}

	// Est-ce que le FST a arr�t� sur des �tats acceptants?
	// Mettre dans une liste true pour oui, false pour non et
	// retourner cette liste.
	std::list<bool> acceptingStates;
	for (auto currentState : mCurrentStates) {
		acceptingStates.push_back(currentState->isAccepting());
	}
	return acceptingStates;
}

// 5a) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'un fichier et envoyer les sorties
//     vers l'�cran.
std::list<bool> FST::processFromFileToScreen(const std::string & inputFileName, bool optionInfo)
{
	FileReader fileReader(inputFileName);
	ScreenWriter screenWriter;

	return process(fileReader, screenWriter, optionInfo);
}

// 5b) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'un fichier et envoyer les sorties vers
//           une cha�ne de caract�res.
std::list<bool> FST::processFromFileToString(const std::string & inputFileName, std::string & outputString, bool optionInfo)
{
	FileReader fileReader(inputFileName);
	StringWriter stringWriter;

	std::list<bool> res{ process(fileReader, stringWriter, optionInfo) };
	outputString = stringWriter.string();

	return res;
}

// 5c) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'un fichier et envoyer les sorties vers
//           un fichier.
std::list<bool> FST::processFromFileToFile(const std::string & inputFileName, const std::string & outputFileName, bool optionInfo)
{
	FileReader fileReader(inputFileName);
	FileWriter fileWriter(outputFileName);

	return process(fileReader, fileWriter, optionInfo);
}

// 5d) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'une cha�ne de caract�res et envoyer les sorties vers
//           l'�cran.
std::list<bool> FST::processFromStringToScreen(const std::string & inputString, bool optionInfo)
{
	StringReader stringReader(inputString);
	ScreenWriter screenWriter;

	return process(stringReader, screenWriter, optionInfo);
}

// 5e) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'une cha�ne de caract�res et envoyer les sorties vers
//           une cha�ne de caract�res.
std::list<bool> FST::processFromStringToString(const std::string & inputString, std::string & outputString, bool optionInfo)
{
	StringReader stringReader(inputString);
	StringWriter stringWriter;

	std::list<bool> res{ process(stringReader, stringWriter, optionInfo) };
	outputString = stringWriter.string();

	return res;
}

// 5f) D�marrer le traitement des symboles Go FST Go!
//     Retourner une liste de bool�ennes pour indiquer les �tat finaux
//     sont des �tats acceptants ou non.
//     Note: utiliser l'entr�e � partir d'une cha�ne de caract�res et envoyer les sorties vers
//           un fichier.
std::list<bool> FST::processFromStringToFile(const std::string & inputString, const std::string & outputFileName, bool optionInfo)
{
	StringReader stringReader(inputString);
	FileWriter fileWriter(outputFileName);

	return process(stringReader, fileWriter, optionInfo);
}

// 6) Lit un symbole d'entr�e et d�termine s'il doit transiter ou non
//    vers le prochain �tat. 
//    Si oui, ex�cuter l'action des transducteur et assigner le
//    prochain �tat comme l'�tat courant (actuel).
void FST::processSymbol(Reader & reader, Writer & writer) {
	symbol_t symbol{ reader.readOne() };
	if (symbol != -1) { // patch
		for (auto & currentState : mCurrentStates) {
			Transition* transition{ currentState->isTransiting(symbol) };
			if (transition) {
				writer.write(transition->transduce(symbol));
				currentState = transition->nextState();
			}
		}
	}
}

