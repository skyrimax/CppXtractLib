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


// 1) Implanter le destructeur
//    Il faut détruire les états qui se trouvent dans la liste
//    mStates
FST::~FST()
{
	for (auto ss : mStates)
	{
		delete ss;
	}
       // utiliser une boucle for et l'instruction delete pour effacer
       // les états qui se trouvent dans mStates	
}

// 2) Ajouter un état dans le FST
//    Note 1: utiliser la liste mStates
//    Note 2: EMPÊCHER deux états identiques d'être
//          dans la liste mStates
void FST::addState(State * state)
{
	for (auto const & ss : mStates) {
		if (ss == state)
		{
			return;
		}
	}
	mStates.push_back(state);
	
	//Débur de copiage de fonction du prof
	/*std::list<State*>::iterator it;
	it = std::find(mStates.begin(), mStates.end(), state);
	if (it == mStates.end())*/
}
	// Utiliser une boucle for (par exemple) pour détecter les doublons
	// Si tout va bien, ajouter state dans la liste de mStates avec sa
        // fonction membre push_back()

// 3) Ajouter un état initial dans le FST
//    Rappel: le FST peut traiter plus d'un diagramme d'états à la fois.
//            c'est prouquoi il peut y avoir plus d'un état intial.
//    Note 1: utiliser la liste mInitialStates
//    Note 2: EMPÊCHER deux états identiques d'être
//            dans la liste mInitialStates
void FST::addInitialState(State * state) 
{ 
	for (auto const & is : mInitialStates)
	{
		if (is == state)
		{
			return;
		}
	}
		mInitialStates.push_back(state);
	// Utiliser une boucle for (par exemple) pour détecter les doublons
	// Si tout va bien, ajouter state dans la liste de mInitialStates avec sa
        // fonction membre push_back()
}

// 4) Démarrer le traitement des symboles Go FST Go!
//    Retourner une liste de booléennes pour indiquer les état finaux
//    sont des états acceptants ou non.
//    Rappel: le FST peut traiter plus d'un diagramme d'états à la fois
//            d'où la nécessité de traiter les états initiaux et les états courants
//            sous forme de listes.
//    Note: doit fournir un objet endant de classe Reader et un objet 
//          endant de classe Writer.
std::list<bool> FST::process(Reader & reader, Writer & writer, bool optionInfo) 
{
	// Initialiser le FST
	initialize();
	// Les états initiaux sont maintenant les états courants (actuels)
	mCurrentStates = mInitialStates;
	// Traiter les symboles d'entrée tant et aussi qu'il y en a...
	while (reader.isAvailable() && writer.isAvailable()) {
		// Traiter le symbole...
		processSymbol(reader, writer);
	}
	// Après le traitement de tous les symboles, afficher un message?
	if (optionInfo) {
		writeOptionInfo(writer);
	}

	// Est-ce que le FST a arrêté sur des états acceptants?
	// Mettre dans une liste true pour oui, false pour non et
	// retourner cette liste.
	std::list<bool> acceptingStates;
	for (auto currentState : mCurrentStates) {
		acceptingStates.push_back(currentState->isAccepting());
	}
	return acceptingStates;
}

// 5a) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'un fichier et envoyer les sorties
//     vers l'écran.
std::list<bool> FST::processFromFileToScreen(const std::string & inputFileName, bool optionInfo)
{
	FileReader fileReader(inputFileName);
	ScreenWriter screenWriter;

	return process(fileReader, screenWriter, optionInfo);
}

// 5b) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'un fichier et envoyer les sorties vers
//           une chaîne de caractères.
std::list<bool> FST::processFromFileToString(const std::string & inputFileName, std::string & outputString, bool optionInfo)
{
	StringWriter stringWriter;
	FileReader fileReader(inputFileName);

	std::list<bool> res{ process(fileReader, stringWriter, optionInfo) };
	outputString = stringWriter.string();

	return res;
}

// 5c) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'un fichier et envoyer les sorties vers
//           un fichier.
std::list<bool> FST::processFromFileToFile(const std::string & inputFileName, const std::string & outputFileName, bool optionInfo)
{
	FileWriter fileWriter(outputFileName);
	FileReader fileReader(inputFileName);

	return{ process(fileReader, fileWriter, optionInfo) };
	
	// S'inspirer de processFromFileToScreen pour coder cette
        // fonction membre
}

// 5d) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'une chaîne de caractères et envoyer les sorties vers
//           l'écran.
std::list<bool> FST::processFromStringToScreen(const std::string & inputString, bool optionInfo)
{
	StringReader stringReader(inputString);
	ScreenWriter screenWriter;

	return process(stringReader, screenWriter, optionInfo);
}

// 5e) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'une chaîne de caractères et envoyer les sorties vers
//           une chaîne de caractères.
std::list<bool> FST::processFromStringToString(const std::string & inputString, std::string & outputString, bool optionInfo)
{

	StringReader stringReader(inputString);
	StringWriter stringWriter;

	std::list<bool> res{ process(stringReader, stringWriter, optionInfo) };
	outputString = stringWriter.string();

	return res;


	// S'inspirer de processFromFileToScreen et processFromFileToString 
        // pour coder cette fonction membre
}

// 5f) Démarrer le traitement des symboles Go FST Go!
//     Retourner une liste de booléennes pour indiquer les état finaux
//     sont des états acceptants ou non.
//     Note: utiliser l'entrée à partir d'une chaîne de caractères et envoyer les sorties vers
//           un fichier.
std::list<bool> FST::processFromStringToFile(const std::string & inputString, const std::string & outputFileName, bool optionInfo)
{
	StringReader stringReader(inputString);
	FileWriter fileWriter(outputFileName);

	return{ process(stringReader, fileWriter, optionInfo) };
	// S'inspirer de processFromStringToScreen et processFromFileToFile 
        // pour coder cette fonction membre
}

// 6) Lit un symbole d'entrée et détermine s'il doit transiter ou non
//    vers le prochain état. 
//    Si oui, exécuter l'action des transducteur et assigner le
//    prochain état comme l'état courant (actuel).
void FST::processSymbol(Reader & reader, Writer & writer) {
	symbol_t symbol{ reader.readOne() };
	for (auto & currentState : mCurrentStates) {
		Transition* transition{ currentState->isTransiting(symbol) };
		if (transition) {
			writer.write(transition->transduce(symbol));
			currentState = transition->nextState();
		}
	}
}

