#include "QCppXtractParamWidget.h"

#include "CppXtractLibGUI.h"
#include "QFileSelector.h"

#include "QtUtil.h"


QCppXtractParamWidget::QCppXtractParamWidget(CppXtractLibGUI *mainWin)
{
	mInputFileSelector = new QFileSelector(nullptr, mainWin->getInputFileButton(),
		mainWin->getInputFilename());

	mInputFileSelector->setButtonText(u8R"(S�lectionner un fichier d'entr�e)");
	mInputFileSelector->setOpen(u8R"(S�lectionner un fichier d'entr�e)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mInputFileSelector->setComplyFileNameFunction(complyFileName);

}