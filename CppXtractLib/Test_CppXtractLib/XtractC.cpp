
#include <CppXtract.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
//#include "FileReader.h"
//#include "StringReader.h"
//#include "FileWriter.h"
//#include "StringWriter.h"
//#include "ScreenWriter.h"


using namespace std;


// Fonctions tests
//Reader* testFileReader(const string & fileName);
//Reader* testStringReaderFromFile(const string & fileName);
//Writer* testFileWriter(const string & fileName);
//Writer* testStringWriter();
//Writer* testScreeWriter();


int main(int argc, char **argv)
{
	// Indiquer le chemin du fichier de test
	const string filePath("C:\\Users\\GUI\\Desktop\\GPA434\\Laboratoires\\GitHub\\skyrimax\\CppXtractLib\\CppXtractLib\\tests\\");
	// Nom du fichier de test
	const string inputFileName("Test_CppComments2");
	// Extension du fichier de test
	const string inputFileExt("cpp");
	// Extension du fichier de sortie
	const string outputFileExt("txt");
	// Nom du fichier de sortie sera Test_CppComments_out.cpp
	const string outputFileSuffixe("_out");

	const string fullInputName{ filePath + inputFileName + "." + inputFileExt };
	const string fullOutputName{ filePath + inputFileName + outputFileSuffixe + "." + outputFileExt };

	////Reader * reader{ testFileReader(fullInputName) };
	//Reader * reader{ testStringReaderFromFile(fullInputName) };
	////Writer * writer{ testFileWriter(fullOutputName) };
	////Writer * writer{ testStringWriter() };
	//Writer * writer{ testScreeWriter() };

	// Cr�er un objet de type CppXtract
	// Les diagrammes d'�tats-transitions seront cr��s automatiquement
	// par cet objet
	CppXtract cppXtract;
	//list<bool> acceptingStates{ cppXtract.process(*reader, *writer, true) };
	list<bool> acceptingStates;
	std::string testString;

	// Tests avec fichier d'entr�e
	// Tester l'entr�e fichier et sortie vers l'�cran
	acceptingStates = cppXtract.processFromFileToScreen(fullInputName, true);
	// Tester l'entr�e fichier et sortie vers une cha�ne de caract�res
	acceptingStates = cppXtract.processFromFileToString(fullInputName, testString, true);
	// Tester l'entr�e fichier et sortie fichier
	acceptingStates = cppXtract.processFromFileToFile(fullInputName, fullOutputName, true);

	// Tests avec cha�ne de caract�re en entr�e
	// Lire le fichier d'entr�e et mettre son contenu dans une cha�ne de caract�res
	ifstream fileStream(fullInputName);
	stringstream buffer;
	buffer << fileStream.rdbuf();
	// Tester l'entr�e cha�ne de caract�res et sortie vers l'�cran
	acceptingStates = cppXtract.processFromStringToScreen(buffer.str(), true);
	// Tester l'entr�e cha�ne de caract�res et sortie vers la cha�ne de caract�res
	acceptingStates = cppXtract.processFromStringToString(buffer.str(), testString, true);
	// Tester l'entr�e cha�ne de caract�res et sortie vers la cha�ne de caract�res
	acceptingStates = cppXtract.processFromStringToFile(buffer.str(), fullOutputName, true);


	//StringWriter * w{ dynamic_cast<StringWriter*>(writer) };
	//if (w) {
	//	cout << w->string();
	//}

	//delete reader;
	//delete writer;

	// Attendre une touche du clavier
	cin.get();

	return 0;
}

//Reader* testFileReader(const string & fileName)
//{
//	return new FileReader(fileName);
//}
//
//Reader* testStringReaderFromFile(const string & fileName)
//{
//	ifstream fileStream(fileName);
//	stringstream buffer;
//	buffer << fileStream.rdbuf();
//
//	return new StringReader(buffer.str());
//}
//
//Writer* testFileWriter(const string & fileName)
//{
//	return new FileWriter(fileName);
//}
//
//Writer* testStringWriter()
//{
//	return new StringWriter();
//}
//
//Writer* testScreeWriter()
//{
//	return new ScreenWriter();
//}



