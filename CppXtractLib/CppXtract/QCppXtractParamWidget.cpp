#include "stdafx.h"

#include "QCppXtractParamWidget.h"
#include "cppxtract.h"
#include "QFileSelector.h"
#include "QtUtil.h"

QCppXtractParamWidget::QCppXtractParamWidget(CppXtract* mainWin)
{
	// Ajouts du Input file selector
	mInputFileSelector = new QFileSelectorX(nullptr, mainWin->getImputFileButton(),
		mainWin->getInputFilename());

	// Ajout du Output file selector
	mOutputFileSelector = new QFileSelectorX(nullptr, mainWin->getOutputFileButton(),
		mainWin->getOutputFilename());

	// Power les textes affich�s ans les boites de dialogue File Explorer
	mInputFileSelector->setButtonText(u8R"(S�lectionner un fichier d'entr�e)");
	mInputFileSelector->setOpen(u8R"(S�lectionner une fichier d'entr�e)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mInputFileSelector->setComplyFileNameFunction(complyFileName);

	mOutputFileSelector->setButtonText(u8R"(S�lectionner un fichier de sortie)");
	mOutputFileSelector->setOpen(u8R"(S�lectionner une fichier de sortie)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mOutputFileSelector->setComplyFileNameFunction(complyFileName);
}