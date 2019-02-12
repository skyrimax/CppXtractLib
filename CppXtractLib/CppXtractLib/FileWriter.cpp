#include "FileWriter.h"


FileWriter::FileWriter(const std::string & outputFileName)
{
	open(outputFileName);
}

bool FileWriter::open(const std::string & outputFileName)
{ 
	mOutputFile.open(outputFileName, std::ios::out);
	return mOutputFile.is_open(); 
}

void FileWriter::close() 
{ 
	mOutputFile.close(); 
}

void FileWriter::write(symbol_t symbol) 
{ 
	mOutputFile << symbol; 
}

void FileWriter::write(const std::string & text) 
{ 
	mOutputFile << text; 
}

bool FileWriter::isAvailable() const { 
	return mOutputFile.is_open() && !mOutputFile.eof() && !mOutputFile.fail(); 
}
