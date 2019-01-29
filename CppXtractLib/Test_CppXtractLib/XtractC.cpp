
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

	// Créer un objet de type CppXtract
	// Les diagrammes d'états-transitions seront créés automatiquement
	// par cet objet
	CppXtract cppXtract;
	//list<bool> acceptingStates{ cppXtract.process(*reader, *writer, true) };
	list<bool> acceptingStates;
	std::string testString;

	// Tests avec fichier d'entrée
	// Tester l'entrée fichier et sortie vers l'écran
	acceptingStates = cppXtract.processFromFileToScreen(fullInputName, true);
	// Tester l'entrée fichier et sortie vers une chaîne de caractères
	acceptingStates = cppXtract.processFromFileToString(fullInputName, testString, true);
	// Tester l'entrée fichier et sortie fichier
	acceptingStates = cppXtract.processFromFileToFile(fullInputName, fullOutputName, true);

	// Tests avec chaîne de caractère en entrée
	// Lire le fichier d'entrée et mettre son contenu dans une chaîne de caractères
	ifstream fileStream(fullInputName);
	stringstream buffer;
	buffer << fileStream.rdbuf();
	// Tester l'entrée chaîne de caractères et sortie vers l'écran
	acceptingStates = cppXtract.processFromStringToScreen(buffer.str(), true);
	// Tester l'entrée chaîne de caractères et sortie vers la chaîne de caractères
	acceptingStates = cppXtract.processFromStringToString(buffer.str(), testString, true);
	// Tester l'entrée chaîne de caractères et sortie vers la chaîne de caractères
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



