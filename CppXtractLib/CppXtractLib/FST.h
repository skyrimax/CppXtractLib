#ifndef FST_H
#define FST_H


#include "Symbol.h"
#include <list>

class State;
class Reader;
class Writer;


//! \brief 
class FST
{
public:
	FST() = default;
	virtual ~FST();
	FST(const FST & fst) = delete;
	FST& operator=(const FST & fst) = delete;

	void addState(State * state);
	void addInitialState(State * state);

	std::list<bool> processFromFileToScreen(const std::string & inputFileName, \
		                                    bool optionInfo = false);
	std::list<bool> processFromFileToString(const std::string & inputFileName, \
		                                    std::string & outputString, bool optionInfo = false);
	std::list<bool> processFromFileToFile(const std::string & inputFileName, \
		                                  const std::string & outputFileName, bool optionInfo = false);
	
	std::list<bool> processFromStringToScreen(const std::string & inputString, bool optionInfo = false);
	std::list<bool> processFromStringToString(const std::string & inputString, \
		                                      std::string & outputString, bool optionInfo = false);
	std::list<bool> processFromStringToFile(const std::string & inputString, \
		                                    const std::string & outputFileName, bool optionInfo = false);

protected:
	std::list<State*> mStates;
	std::list<State*> mInitialStates;
	std::list<State*> mCurrentStates;

	virtual void initialize() {}
	virtual void writeOptionInfo(Writer & writer) {}

	std::list<bool> process(Reader & reader, Writer & writer, bool optionInfo = false);
	void processSymbol(Reader & reader, Writer & writer);
};


#endif // FST_H