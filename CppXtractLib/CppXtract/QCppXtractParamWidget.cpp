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

	// Poser les textes affich�s dans les boites de dialogue File Explorer
	mInputFileSelector->setButtonText(u8R"(S�lectionner un fichier d'entr�e)");
	mInputFileSelector->setOpen(u8R"(S�lectionner une fichier d'entr�e)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mInputFileSelector->setComplyFileNameFunction(complyFileName);

	// Poser les textes affich�s dans les bo�tes de dialogue File Explorer
	mOutputFileSelector->setButtonText(u8R"(S�lectionner un fichier de sortie)");
	mOutputFileSelector->setOpen(u8R"(S�lectionner une fichier de sortie)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mOutputFileSelector->setComplyFileNameFunction(complyFileName);

	// Assigner les pointeurs pour les boutons radio
	mButtonGroup = mainWin->getButtonGroup();
	mOutputScreenRadioButton = mainWin->getOutputScreenRadioButton();
	mOutputClipboardRadioButton = mainWin->getOutputClipboardRadioButton();
	mOutputFileRadioButton = mainWin->getOutputFileRadioButton();

	// Assigner le pointeur pour le Group Box
	mOutputGroupBox = mainWin->getOutputGroupBox();

	// Assigner le pointeur pour la checkbox des stats
	mIncludeStatInfoCheckBox = mainWin->getIncludeStatInfoCheckBox();

	// Identifier les boutons dans le groupe par un num�ro
	mButtonGroup->setId(mOutputScreenRadioButton, static_cast<int>(OutputType::Screen));
	mButtonGroup->setId(mOutputClipboardRadioButton, static_cast<int>(OutputType::Clipboard));
	mButtonGroup->setId(mOutputFileRadioButton, static_cast<int>(OutputType::File));

	// Pr�-s�lectionner les options de sortie
	mOutputScreenRadioButton->setChecked(true);
	mIncludeStatInfoCheckBox->setChecked(true);

	//Update des �l�ments graphiques
	updateGui();

	//-------------------------------
	// Connecter les signaux au slots
	//-------------------------------

	// Provoquer updateGui() quand fileChanged() est triggered par mInputFileSelector
	connect(mInputFileSelector, &QFileSelectorX::fileChanged, this,
		&QCppXtractParamWidget::updateGui);
	//Envoyer le signal parameterChanged quand fileChanged() est triggered par mInputFileSelector
	connect(mInputFileSelector, &QFileSelectorX::fileChanged, this,
		&QCppXtractParamWidget::parameterChanged);

	// Provoquer updateGui() quand fileChanged() est triggered par mOutputFileSelector
	connect(mOutputFileSelector, &QFileSelectorX::fileChanged, this,
		&QCppXtractParamWidget::updateGui);
	//Envoyer le signal parameterChanged quand fileChanged() est triggered par mOutputFileSelector
	connect(mOutputFileSelector, &QFileSelectorX::fileChanged, this,
		&QCppXtractParamWidget::parameterChanged);

	// Provoque updateGui quand un bouton radio est s�lectionn�
	connect(mButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
		this, &QCppXtractParamWidget::updateGui);
	connect(mButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
		this, &QCppXtractParamWidget::parameterChanged);
}

bool QCppXtractParamWidget::isValid() const
{
	// Pas de fichier s�lectionner, retourner faux
	if (!mInputFileSelector->isFileSelected())
	{
		return false;
	}
	
	//Si fichier s�lectionner, d�pend de l'option s�lectionn�e
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

void QCppXtractParamWidget::updateGui()
{
	// Activer les options de sortie si un fichier d'entr� est s�lectionn�
	mOutputGroupBox->setEnabled(mInputFileSelector->isFileSelected());

	// Activer la s�lection d'un fichier de sortie si cette option est s�lectionn�e
	mOutputFileSelector->setEnabled(mOutputFileRadioButton->isChecked());
}