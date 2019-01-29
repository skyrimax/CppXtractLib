#include "StringWriter.h"


void StringWriter::reset() 
{ 
	mOutputString.clear(); 
}

std::string StringWriter::string() const 
{ 
	return mOutputString.str(); 
}

void StringWriter::write(symbol_t symbol) 
{ 
	mOutputString << symbol; 
}

void StringWriter::write(const std::string & text) 
{ 
	mOutputString << text; 
}

bool StringWriter::isAvailable() const 
{ 
	return !mOutputString.eof() && !mOutputString.fail();
}
