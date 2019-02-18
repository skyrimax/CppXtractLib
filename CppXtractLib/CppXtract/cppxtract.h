#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cppxtract.h"

class CppXtract : public QMainWindow
{
	Q_OBJECT

public:
	CppXtract(QWidget *parent = Q_NULLPTR);

	//Slots pour afficher les messages "À propos"
private slots:
	void showAboutCppXtract();
	void showAboutCpp();
	void showAboutQt();

private:
	Ui::CppXtractClass ui;
};
