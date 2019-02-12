#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CppXtractLibGUI.h"

class CppXtractLibGUI : public QMainWindow
{
	Q_OBJECT

public:
	CppXtractLibGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::CppXtractLibGUIClass ui;
};
