#include "CppXtract.h"


#include "State.h"
#include "Transition.h"
#include "Writer.h"

#include "SymbolMatchOne.h"
#include "SymbolDistinctOne.h"
#include "SymbolMatchAny.h"
#include "SymbolDistinctAny.h"
//#include "SymbolMatchInRange.h"
//#include "SymbolMatchOutRange.h"
#include "SymbolMatchAll.h"

#include "TransducerCounter.h"
#include "TransducerStaticWriter.h"
#include "TransducerRepeater.h"
#include "TransducerReporter.h"
#include "TransducerCounterReporter.h"

#include <sstream>

// CppXtract est une classe permettant le traitement des commentaires C/C++.
// C'est une version spécifique de la classe générique FST. Le constructeur
// de CppXtract construit les diagrammes d'états-transitions de l'automate
// et toutes les initialisations requises.
CppXtract::CppXtract()
{
	// Espace pour les numéros de ligne
	const int lineNbrWidth{ 5 };
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Diagramme d'états-transitions pour le comptage des caractères
	State * a1StateEmptyFile{ new State(true) };
	State * a1StateInline{ new State(true) };

	Transition * a1TransitStartBySpace = new Transition(a1StateInline, new SymbolMatchAny({ ' ', '\t' }));
	Transition * a1TransitStartByLine = new Transition(a1StateInline, new SymbolMatchOne('\n'));
	Transition * a1TransitStartByChar = new Transition(a1StateInline, new SymbolDistinctAny({ ' ', '\t', '\n' }));
	mTransducerStartBySpaceCounter = new TransducerCounter();
	mTransducerStartByLineCounter = new TransducerCounter();
	mTransducerStartByCharCounter = new TransducerCounter();
	a1TransitStartBySpace->addTransducer(mTransducerStartBySpaceCounter);
	a1TransitStartByLine->addTransducer(mTransducerStartByLineCounter);
	a1TransitStartByChar->addTransducer(mTransducerStartByCharCounter);

	Transition * a1TransitSpaceCounter = new Transition(a1StateInline, new SymbolMatchAny({ ' ', '\t' }));
	Transition * a1TransitLineCounter = new Transition(a1StateInline, new SymbolMatchOne('\n'));
	Transition * a1TransitCharCounter = new Transition(a1StateInline, new SymbolDistinctAny({ ' ', '\t', '\n' }));
	mTransducerSpaceCounter = new TransducerCounter();
	mTransducerLineCounter = new TransducerCounter();
	mTransducerCharCounter = new TransducerCounter();
	a1TransitSpaceCounter->addTransducer(mTransducerSpaceCounter);
	a1TransitLineCounter->addTransducer(mTransducerLineCounter);
	a1TransitCharCounter->addTransducer(mTransducerCharCounter);

	a1StateEmptyFile->addTransition(a1TransitStartBySpace);
	a1StateEmptyFile->addTransition(a1TransitStartByLine);
	a1StateEmptyFile->addTransition(a1TransitStartByChar);

	a1StateInline->addTransition(a1TransitSpaceCounter);
	a1StateInline->addTransition(a1TransitLineCounter);
	a1StateInline->addTransition(a1TransitCharCounter);
	// Ajouter ces états dans CppXtract
	addState(a1StateEmptyFile);
	addState(a1StateInline);
	// État initial
	addInitialState(a1StateEmptyFile);

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Diagramme d'états-transitions pour la reconnaissance des commentaires
	State * a2StateCode{ new State(true) };
	State * a2StateSlash{ new State() };
	State * a2StateCStyleComment{ new State() };
	State * a2StateCppStyleComment{ new State(true) };
	State * a2StateCStyleCommentStar{ new State() };
	State * a2StateCppStyleCommentEscChar{ new State() };
	State * a2StateString{ new State() };
	State * a2StateStringEscChar{ new State() };
	State * a2StateCharacter{ new State() };
	State * a2StateCharacterEscChar{ new State() };

	Transition * a2TransitSlashEnter{ new Transition(a2StateSlash, new SymbolMatchOne('/')) };

	Transition * a2TransitSlashExit{ new Transition(a2StateCode, new SymbolDistinctAny({ '/', '*' })) };

	Transition * a2TransitCStyleCommentEnter{ new Transition(a2StateCStyleComment, new SymbolMatchOne('*')) };
	a2TransitCStyleCommentEnter->addTransducer(new TransducerStaticWriter("Line no : "));
	//a2TransitCStyleCommentEnter->addTransducer(new TransducerStaticWriter("###"));
	TransducerCounterReporter * cStyleTransducerCounterReporter{ new TransducerCounterReporter(1) };
	cStyleTransducerCounterReporter->setFormat(lineNbrWidth, ' ');
	cStyleTransducerCounterReporter->addTransducerCounter(mTransducerStartByLineCounter);
	cStyleTransducerCounterReporter->addTransducerCounter(mTransducerLineCounter);
	a2TransitCStyleCommentEnter->addTransducer(new TransducerReporter(cStyleTransducerCounterReporter));
	a2TransitCStyleCommentEnter->addTransducer(new TransducerStaticWriter("   [C-style]\n/*"));
	mTransducerCStyleCommentCounter = new TransducerCounter;
	a2TransitCStyleCommentEnter->addTransducer(mTransducerCStyleCommentCounter);

	Transition * a2TransitCStyleCommentChar{ new Transition(a2StateCStyleComment, new SymbolDistinctOne('*')) };
	a2TransitCStyleCommentChar->addTransducer(new TransducerRepeater());
	Transition * a2TransitCStyleCommentStarEnter{ new Transition(a2StateCStyleCommentStar, new SymbolMatchOne('*')) };
	a2TransitCStyleCommentStarEnter->addTransducer(new TransducerRepeater());
	Transition * a2TransitCStyleCommentStarExit{ new Transition(a2StateCStyleComment, new SymbolDistinctAny({ '*', '/' })) };
	a2TransitCStyleCommentStarExit->addTransducer(new TransducerRepeater());
	Transition * a2TransitCStyleCommentStarAgain{ new Transition(a2StateCStyleCommentStar, new SymbolMatchOne('*')) };
	a2TransitCStyleCommentStarAgain->addTransducer(new TransducerRepeater());
	Transition * a2TransitCStyleCommentExit{ new Transition(a2StateCode, new SymbolMatchOne('/')) };
	a2TransitCStyleCommentExit->addTransducer(new TransducerStaticWriter("/\n\n"));

	Transition * a2TransitCppStyleCommentEnter{ new Transition(a2StateCppStyleComment, new SymbolMatchOne('/')) };
	a2TransitCppStyleCommentEnter->addTransducer(new TransducerStaticWriter("Line no : "));
	//a2TransitCppStyleCommentEnter->addTransducer(new TransducerStaticWriter("@@@"));
	TransducerCounterReporter * cppStyleTransducerCounterReporter{ new TransducerCounterReporter(1) };
	cppStyleTransducerCounterReporter->setFormat(lineNbrWidth, ' ');
	cppStyleTransducerCounterReporter->addTransducerCounter(mTransducerStartByLineCounter);
	cppStyleTransducerCounterReporter->addTransducerCounter(mTransducerLineCounter);
	a2TransitCppStyleCommentEnter->addTransducer(new TransducerReporter(cppStyleTransducerCounterReporter));
	a2TransitCppStyleCommentEnter->addTransducer(new TransducerStaticWriter("   [C++-style]\n//"));
	mTransducerCppStyleCommentCounter = new TransducerCounter;
	a2TransitCppStyleCommentEnter->addTransducer(mTransducerCppStyleCommentCounter);


	Transition * a2TransitCppStyleCommentChar{ new Transition(a2StateCppStyleComment, new SymbolDistinctAny({ '\\', '\n' })) };
	a2TransitCppStyleCommentChar->addTransducer(new TransducerRepeater());
	Transition * a2TransitCppStyleCommentEscCharEnter{ new Transition(a2StateCppStyleCommentEscChar, new SymbolMatchOne('\\')) };
	a2TransitCppStyleCommentEscCharEnter->addTransducer(new TransducerRepeater());
	Transition * a2TransitCppStyleCommentEscCharExit{ new Transition(a2StateCppStyleComment, new SymbolMatchAll()) };
	a2TransitCppStyleCommentEscCharExit->addTransducer(new TransducerRepeater());
	Transition * a2TransitCppStyleCommentExit{ new Transition(a2StateCode, new SymbolMatchOne('\n')) };
	a2TransitCppStyleCommentExit->addTransducer(new TransducerStaticWriter("\n\n"));

	Transition * a2TransitStringEnter{ new Transition(a2StateString, new SymbolMatchOne('"')) };
	mTransducerLiteralStringCounter = new TransducerCounter;
	a2TransitStringEnter->addTransducer(mTransducerLiteralStringCounter);
	Transition * a2TransitStringEscCharEnter{ new Transition(a2StateStringEscChar, new SymbolMatchOne('\\')) };
	Transition * a2TransitStringEscCharExit{ new Transition(a2StateString, new SymbolMatchAll()) };
	Transition * a2TransitStringExit{ new Transition(a2StateCode, new SymbolMatchAny({ '"', '\n' })) };

	Transition * a2TransitCharacterEnter{ new Transition(a2StateCharacter, new SymbolMatchOne('\'')) };
	mTransducerLiteralCharCounter = new TransducerCounter;
	a2TransitCharacterEnter->addTransducer(mTransducerLiteralCharCounter);
	Transition * a2TransitCharacterEscCharEnter{ new Transition(a2StateCharacterEscChar, new SymbolMatchOne('\\')) };
	Transition * a2TransitCharacterEscCharExit{ new Transition(a2StateCharacter, new SymbolMatchAll()) };
	Transition * a2TransitCharacterExit{ new Transition(a2StateCode, new SymbolMatchAny({ '\'', '\n' })) };

	a2StateCode->addTransition(a2TransitSlashEnter);
	a2StateCode->addTransition(a2TransitStringEnter);
	a2StateCode->addTransition(a2TransitCharacterEnter);

	a2StateSlash->addTransition(a2TransitCStyleCommentEnter);
	a2StateSlash->addTransition(a2TransitCppStyleCommentEnter);
	a2StateSlash->addTransition(a2TransitSlashExit);

	a2StateCStyleComment->addTransition(a2TransitCStyleCommentChar);
	a2StateCStyleComment->addTransition(a2TransitCStyleCommentStarEnter);

	a2StateCStyleCommentStar->addTransition(a2TransitCStyleCommentExit);
	a2StateCStyleCommentStar->addTransition(a2TransitCStyleCommentStarExit);
	a2StateCStyleCommentStar->addTransition(a2TransitCStyleCommentStarAgain);

	a2StateCppStyleComment->addTransition(a2TransitCppStyleCommentChar);
	a2StateCppStyleComment->addTransition(a2TransitCppStyleCommentEscCharEnter);
	a2StateCppStyleComment->addTransition(a2TransitCppStyleCommentExit);

	a2StateCppStyleCommentEscChar->addTransition(a2TransitCppStyleCommentEscCharExit);

	a2StateString->addTransition(a2TransitStringExit);
	a2StateString->addTransition(a2TransitStringEscCharEnter);
	a2StateStringEscChar->addTransition(a2TransitStringEscCharExit);

	a2StateCharacter->addTransition(a2TransitCharacterExit);
	a2StateCharacter->addTransition(a2TransitCharacterEscCharEnter);
	a2StateCharacterEscChar->addTransition(a2TransitCharacterEscCharExit);
	// Ajouter ces états dans CppXtract
	addState(a2StateCode);
	addState(a2StateSlash);
	addState(a2StateCStyleComment);
	addState(a2StateCppStyleComment);
	addState(a2StateCStyleCommentStar);
	addState(a2StateCppStyleCommentEscChar);
	addState(a2StateString);
	addState(a2StateStringEscChar);
	addState(a2StateCharacter);
	addState(a2StateCharacterEscChar);
	// État initial
	addInitialState(a2StateCode);
}

size_t CppXtract::spaceCount() const
{ 
	return mTransducerStartBySpaceCounter->count() + mTransducerSpaceCounter->count(); 
}
size_t CppXtract::lineCount() const
{ 
	return mTransducerStartByLineCounter->count() + mTransducerLineCounter->count() + 1; 
}
size_t CppXtract::charCount() const
{ 
	return mTransducerStartByCharCounter->count() + mTransducerCharCounter->count(); 
}
size_t CppXtract::cStyleCommentCount() const
{ 
	return mTransducerCStyleCommentCounter->count(); 
}
size_t CppXtract::cppStyleCommentCount() const
{ 
	return mTransducerCppStyleCommentCounter->count(); 
}
size_t CppXtract::stringLiteralCount() const
{ 
	return mTransducerLiteralStringCounter->count();
}
size_t CppXtract::charLiteralCount() const
{ 
	return mTransducerLiteralCharCounter->count();
}

void CppXtract::initialize()
{
	mTransducerSpaceCounter->reset();
	mTransducerLineCounter->reset();
	mTransducerCharCounter->reset();
	mTransducerCStyleCommentCounter->reset();
	mTransducerCppStyleCommentCounter->reset();
	mTransducerLiteralStringCounter->reset();
	mTransducerLiteralCharCounter->reset();
}

void CppXtract::writeOptionInfo(Writer & writer)
{
	std::stringstream info;
	info << std::endl << std::endl
		 << "Informations globales" << std::endl
		 << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl
		 << " - Statistiques generales :" << std::endl
		 << "   - espaces : " << spaceCount() << std::endl
		 << "   - lignes  : " << lineCount() << std::endl
		 << "   - autres  : " << charCount() << std::endl
		 << " - Litteraux : " << std::endl
		 << "   - charactere            : " << charLiteralCount() << std::endl
		 << "   - chaînes de caracteres : " << stringLiteralCount() << std::endl
		 << " - Commentaires : " << std::endl
		 << "   - style C   : " << cStyleCommentCount() << std::endl
		 << "   - style C++ : " << cppStyleCommentCount() << std::endl
		 << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

	writer.write(info.str());
}
