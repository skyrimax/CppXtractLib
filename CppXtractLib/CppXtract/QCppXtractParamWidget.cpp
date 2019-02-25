#include "QCppXtractParamWidget.h"
#include "stdafx.h"

#include "cppxtract.h"
#include "QFileSelector.h"
#include "QtUtil.h"

class CppXtract; //D�claration anticip�e
class QFileSelectorX;

QCppXtractParamWidget::QCppXtractParamWidget(CppXtract *mainWin)
{
	//Fichiers d'entr�e
	mInputFileSelector = new QFileSelectorX(nullptr, mainWin->getInputFileButton(), mainWin->getInputFilename());
	mInputFileSelector->setButtonText(u8R"(S�lectionner un fichier d'entr�e)");
	mInputFileSelector->setOpen(u8R"(S�lectionner un fichier d'entr�e)",
		"fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mInputFileSelector->setComplyFileNameFunction(complyFileName);

	//Fichier de sortie
	mOutputFileSelector = new QFileSelectorX(nullptr, mainWin->getOutputFileButton(), mainWin->getOutputFilename());
	mOutputFileSelector->setButtonText(u8R"(S�lectionner un fichier d'entr�e)");
	mOutputFileSelector->setOpen(u8R"(S�lectionner un fichier d'entr�e)",
		"fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mOutputFileSelector->setComplyFileNameFunction(complyFileName);

	//Pour le groupe de boutons
	mButtonGroup = mainWin->getButtonGroup();
	mOutputGroupBox = mainWin->getOutputGroupBox();
	mOutputScreenRadioButton = mainWin->getOutputScreenRadioButton();
	mOutputClipboardRadioButton = mainWin->getOutputClipboardRadioButton();
	mOutputFileRadioButton = mainWin->getOutputFileRadioButton();
	//Pour la case � cocher
	mIncludeStatInfoCheckBox = mainWin->getIncludeStatInfoCheckBox();

	//Identifier les boutons dans le groupe par un num�ro
	mButtonGroup->setId(mOutputScreenRadioButton, static_cast<int>(OutputType::Screen));
	mButtonGroup->setId(mOutputClipboardRadioButton, static_cast<int>(OutputType::Clipboard));
	mButtonGroup->setId(mOutputFileRadioButton, static_cast<int>(OutputType::File));

	//Pr�-s�lectionner les options de sortie
	mOutputScreenRadioButton->setChecked(true); //Sortie vers l'�cran
	mIncludeStatInfoCheckBox->setChecked(true); //Avec statistiques de comptage

	//Mise � jour de l'�tat des �l�ments d'interface graphique
	updateGui();

	//------Connecttion des signaux aux slots-----
	//Signal filechange() envoy� au slot updateGui
	connect(mInputFileSelector, &QFileSelectorX::fileChanged, this, &QCppXtractParamWidget::updateGui);
	//Provoque l'envoi d'un signal parameterchanged qui sera trait� par le slot updateProcessButton()
	connect(mInputFileSelector, &QFileSelectorX::fileChanged, this, &QCppXtractParamWidget::parameterChanged);

	connect(mOutputFileSelector, &QFileSelectorX::fileChanged, this, &QCppXtractParamWidget::updateGui);

	connect(mOutputFileSelector, &QFileSelectorX::fileChanged, this, &QCppXtractParamWidget::parameterChanged);

	//Pour l'objet mButtonGroup
	connect(mButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &QCppXtractParamWidget::updateGui);

	connect(mButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &QCppXtractParamWidget::parameterChanged);

}

//Slot updateGui
void QCppXtractParamWidget::updateGui()
{
	//Activation des options de sortie si un fichier d'entr� est choisi
	mOutputGroupBox->setEnabled(mInputFileSelector->isFileSelected());
	
	//Activation la s�lection de fichier de sortie si le choix a �t� fait
	mOutputFileSelector->setEnabled(mOutputFileRadioButton->isChecked());
}


bool QCppXtractParamWidget::isValid() const
{
	//Pas de fichier d'entr�e?
	if (!mInputFileSelector->isFileSelected())
	{
		return false;
	}
	//Quel bouton a �t� s�lectionn�?
	switch (static_cast<OutputType>(mButtonGroup->checkedId()))
	{
	case OutputType::Screen:
		return true;
	case OutputType::Clipboard:
		return true;
	case OutputType::File:
		return mOutputFileSelector->isFileSelected();
	}
	return false;
}


int QCppXtractParamWidget::outputType()
{
	return static_cast<OutputType>(mButtonGroup->checkedId());
}