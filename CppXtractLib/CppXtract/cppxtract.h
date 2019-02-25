#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cppxtract.h"
#include "QCppXtractParamWidget.h"


class QCppXtractParamWidget; //D�claration anticip�e

class CppXtract : public QMainWindow
{
	Q_OBJECT

public:
	CppXtract(QWidget *parent = Q_NULLPTR);
	//Accesseur
	QPushButton *getInputFileButton() { return ui.mSelectFileButton1; };
	QLabel *getInputFilename() { return ui.mSelectedFilename1; };
	QPushButton *getOutputFileButton() { return ui.mSelectFileButton2; };
	QLabel *getOutputFilename() { return ui.mSelectedFilename2; };
	QButtonGroup *getButtonGroup() { return ui.mButtonGroup; };
	QGroupBox *getOutputGroupBox() { return ui.mOutputGroupBox; };
	QRadioButton *getOutputScreenRadioButton() { return ui.mOutputScreenRadioButton; };
	QRadioButton *getOutputClipboardRadioButton() { return ui.mOutputClipboardRadioButton; };
	QRadioButton *getOutputFileRadioButton() { return ui.mOutputFileRadioButton; };
	QCheckBox *getIncludeStatInfoCheckBox() { return ui.mIncludeStatInfoCheckBox; };
	bool fileOk(const QFileInfo &xFile, QString &errMsg, bool checkRead);

private slots:
	//Slots pour afficher les messages "� propos"
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();
	//Slot pour g�rer l'�tat du bouton "process"
	void updateProcessButton();
	//Slot pour ex�cuter l'extraction
	void process();

private:
	Ui::CppXtractClass ui;
	QCppXtractParamWidget *mCppXtractParamWidget;
	
};

