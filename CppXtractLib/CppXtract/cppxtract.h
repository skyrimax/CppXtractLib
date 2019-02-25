#pragma once

#include <QtWidgets/QWidget>
#include "ui_cppxtract.h"

class QCppXtractParamWidget; // D�claration anticip�e

class CppXtract : public QWidget
{
	Q_OBJECT

public:
	CppXtract(QWidget *parent = Q_NULLPTR);

	// Accesseurs Input file
	QPushButton* getImputFileButton() { return ui.fileSelectorButtonImput; }
	QLabel* getInputFilename() { return ui.inputFilePathLabel; }

	// Accesseurs Output file
	QPushButton* getOutputFileButton() { return ui.fileSlectorButtonOutput; }
	QLabel* getOutputFilename() { return ui.outputFilePathLabel; }

	// Accesseurs boutons ratio
	QButtonGroup* getButtonGroup() { return ui.outputOptionButtonGroup; }
	QRadioButton* getOutputScreenRadioButton() { return ui.screenRadioButton; }
	QRadioButton* getOutputClipboardRadioButton() { return ui.clipboardRadioButton; }
	QRadioButton* getOutputFileRadioButton() { return ui.fileRadioButton; }

	// Accesseur Group Box
	QGroupBox* getOutputGroupBox() { return ui.outputOptions;  }

	// Accesseur checkbox stats
	QCheckBox* getIncludeStatInfoCheckBox() { return ui.statisticsCheckBox;  }

private:
	Ui::CppXtractClass ui;
	QCppXtractParamWidget* mCppXtractParamWidget;

private slots:
	// Slots d'affichage des message "� propos"
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();

	// slot pour g�rer l'�tat du bouton "process"
	void updadeProcessButton();

	// Slot pour ex�cuter l'extraction
	void process();
};
