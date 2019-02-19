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

	// slots pour afficher les messages "À propos"
private slots:
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();

private:
	Ui::CppXtractLibGUIClass ui; // ne pas envoyer le UI complet aux classes enfants
	QCppXtractParamWidget *mCppXtractParamWidget;
};
