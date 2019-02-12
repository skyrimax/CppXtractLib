#include "FileReader.h"


FileReader::FileReader(const std::string & inputFileName)
{
	open(inputFileName);
}

bool FileReader::open(const std::string & inputFileName)
{ 
	if (mInputFile.is_open()) {
		mInputFile.close();
	}

	mInputFile.open(inputFileName, std::ios::in); 
	return mInputFile.is_open(); 
}

void FileReader::close() 
{ 
	mInputFile.close(); 
}

bool FileReader::isAvailable() const 
{ 
	return mInputFile.is_open() && !mInputFile.eof() && !mInputFile.fail(); 
}

symbol_t FileReader::readOneFromSource()
{ 
	return mInputFile.get();
}
