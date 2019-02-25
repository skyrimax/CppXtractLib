#include "QCppXtractParamWidget.h"

#include "CppXtractLibGUI.h"
#include "QFileSelector.h"

#include "QtUtil.h"


QCppXtractParamWidget::QCppXtractParamWidget(CppXtractLibGUI *mainWin)
{
	// Création de l'objet input
	mInputFileSelector = new QFileSelector(nullptr, mainWin->getInputFileButton(),
		mainWin->getInputFilename());

	mInputFileSelector->setButtonText(u8R"(Sélectionner un fichier d'entrée)");
	mInputFileSelector->setOpen(u8R"(Sélectionner un fichier d'entrée)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mInputFileSelector->setComplyFileNameFunction(complyFileName);
	
	// Création de l'objet output
	mOutputFileSelector = new QFileSelector(nullptr, mainWin->getOutputFileButton(),
		mainWin->getOutputFilename());

	mOutputFileSelector->setButtonText(u8R"(Sélectionner un fichier de sortie)");
	mOutputFileSelector->setOpen(u8R"(Sélectionner un fichier de sortie)",
		"Fichiers C++ (*.h *.hpp *.hxx *.cpp *.cc *.c *.cxx *.c++)");
	mOutputFileSelector->setComplyFileNameFunction(complyFileName);

	// Pour le groupe de boutons
	mButtonGroup = mainWin->getButtonGroup();
	mOutputGroupBox = mainWin->getOutputGroupBox();
	mOutputScreenRadioButton = mainWin->getOutputScreenRadioButton();
	mOutputClipboardRadioButton = mainWin->getOutputClipboardRadioButton();
	mOutputFileRadioButton = mainWin->getOutputFileRadioButton();
	// Pour la case à cocher
	mIncludeStatInfoCheckBox = mainWin->getIncludeStatInfoCheckBox();

	// Identifier les boutons dans le groupe par un numéro
	mButtonGroup->setId(mOutputScreenRadioButton, static_cast<int>(OutputType::Screen));
	mButtonGroup->setId(mOutputClipboardRadioButton, static_cast<int>(OutputType::Clipboard));
	mButtonGroup->setId(mOutputFileRadioButton, static_cast<int>(OutputType::File));

	// Pré-sélectionner les options de sortie
	mOutputScreenRadioButton->setChecked(true); // Sortie vers l'écran
	mIncludeStatInfoCheckBox->setChecked(true); // Avec statistique de comptage

	// Ne prendre aucune chance: faire une mise à jour de l'état des éléments
	// d'interface graphique
	updateGui();

	// -------------------------------
	// Connecter les signaux aux slots
	// -------------------------------
	// Pour l'objet mInputFileSelector
	// Signal fileChanged() envoyé lorsque l'utilisateur a utilisé l'objet mInputFileSelector
	// est connecté aux slot updateGui() de QCppXtractParamWidget.
	connect(mInputFileSelector, &QFileSelector::fileChanged, this, &QCppXtractParamWidget::updateGui);

	// Signal fileChanged() envoyé lorsque l'utilisateur a utilisé l'objet mInputFileSelector
	// provoque l'envoie d'un autre signal parameterChanged() de QCppXtractParamWidget.
	// Le signal parameterChanged() sera traité par le slot updateProcessButton() de CppXtractLibGUI
	connect(mInputFileSelector, &QFileSelector::fileChanged, this, &QCppXtractParamWidget::parameterChanged);

	// Pour l'objet mOutputFileSelector
	// Signal fileChanged() envoyé lorsque l'utilisateur a utilisé l'objet mOutputFileSelector
	// est connecté aux slot updateGui() de QCppXtractParamWidget.
	connect(mOutputFileSelector, &QFileSelector::fileChanged, this, &QCppXtractParamWidget::updateGui);

	// Signal fileChanged() envoyé lorsque l'utilisateur a utilisé l'objet mOutputFileSelector
	// provoque l'envoie d'un autre signal parameterChanged() de QCppXtractParamWidget.
	// Le signal parameterChanged() sera traité par le slot updateProcessButton() de CppXtractLibGUI
	connect(mOutputFileSelector, &QFileSelector::fileChanged, this, &QCppXtractParamWidget::parameterChanged);

	// Pour l'objet mButtonGroup (les boutons dans ce groupe)
	// Note: la syntaxe pour la connexion signal - slot est donnée dans la documentation
	// https://doc.qt.io/archives/qt-4.8/qbuttongroup.html#buttonClicked-2

	connect(mButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), 
				this, &QCppXtractParamWidget::updateGui);
	connect(mButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
				this, &QCppXtractParamWidget::parameterChanged);

}

// Slot updateGui
void QCppXtractParamWidget::updateGui() {
	// L'utilisateur a-t-il choisi un fichier d'entrée?
	// Si oui, activer les options de sorties, la sélection du fichier de sortie et la case à cocher.
	// Si non, les désactiver
	mOutputGroupBox->setEnabled(mInputFileSelector->isFileSelected());
	// L'utilisateur a-t-il sélectionné la sortie vers un fichier?
	// Si oui, activer la sélection du fichier de sortie
	// Si non, la désactiver
	mOutputFileSelector->setEnabled(mOutputFileRadioButton->isChecked());


}