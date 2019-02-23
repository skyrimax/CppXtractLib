#pragma once

#include <QtWidgets/QWidget>
#include "ui_cppxtract.h"

class QCppXtractParamWidget; // Déclaration anticipée

class CppXtract : public QWidget
{
	Q_OBJECT

public:
	CppXtract(QWidget *parent = Q_NULLPTR);

	// Accesseurs
	QPushButton* getImputFileButton() { return ui.fileSelectorButtonImput; }
	QLabel* getInputFilename() { return ui.inputFilePathLabel; }

private:
	Ui::CppXtractClass ui;
	QCppXtractParamWidget* mCppXtractParamWidget;

private slots:
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();
};
