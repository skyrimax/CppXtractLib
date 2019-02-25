#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CppXtractLibGUI.h"

class QCppXtractParamWidget; //déclaration anticipée



class CppXtractLibGUI : public QMainWindow
{
	Q_OBJECT

public:
	CppXtractLibGUI(QWidget *parent = Q_NULLPTR);
	// Accesseur
	QPushButton *getInputFileButton() { return ui.mSelectFileButton1; }
	QLabel	*getInputFilename() { return ui.mSelectedFilename1; }

	QPushButton *getOutputFileButton() { return ui.mSelectFileButton2; }
	QLabel	*getOutputFilename() { return ui.mSelectedFilename2; }

	// Ajouts d'accesseurs
	QButtonGroup *getButtonGroup() { return ui.mButtonGroup; }
	QGroupBox *getOutputGroupBox() { return ui.mOutputGroupBox; }
	QRadioButton *getOutputScreenRadioButton() { return ui.mOutputScreenRadioButton; }
	QRadioButton *getOutputClipboardRadioButton() { return ui.mOutputClipboardRadioButton; }
	QRadioButton *getOutputFileRadioButton() { return ui.mOutputFileRadioButton; }
	QCheckBox *getIncludeStatInfoCheckBox() { return ui.mIncludeStatInfoCheckBox; }

	
private slots:
	// slots pour afficher les messages "À propos"
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();
	// slot pour gérer l'état du bouton "process"
	void updateProcessButton();

private:
	Ui::CppXtractLibGUIClass ui; // ne pas envoyer le UI complet aux classes enfants
	QCppXtractParamWidget *mCppXtractParamWidget;
};
