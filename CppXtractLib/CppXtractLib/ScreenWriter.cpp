#include "ScreenWriter.h"


void ScreenWriter::write(symbol_t symbol) 
{ 
	std::cout << symbol; 
}

void ScreenWriter::write(const std::string & text) 
{ 
	std::cout << text;
}

bool ScreenWriter::isAvailable() const 
{ 
	return true; 
}
