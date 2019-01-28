#include "StringReader.h"



StringReader::StringReader(const std::string & text)
{
	setString(text);
}

void StringReader::setString(const std::string & text)
{ 
	mInputString.str(text); 
}

bool StringReader::isAvailable() const
{
	return !mInputString.eof() && !mInputString.fail();
}

symbol_t StringReader::readOneFromSource() 
{ 
	return mInputString.get(); 
}
