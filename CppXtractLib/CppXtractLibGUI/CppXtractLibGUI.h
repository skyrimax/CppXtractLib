#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CppXtractLibGUI.h"

class CppXtractLibGUI : public QMainWindow
{
	Q_OBJECT

public:
	CppXtractLibGUI(QWidget *parent = Q_NULLPTR);

	// slots pour afficher les messages "À propos"
private slots:
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();

private:
	Ui::CppXtractLibGUIClass ui;
};
