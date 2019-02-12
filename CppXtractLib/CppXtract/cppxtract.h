#pragma once

#include <QtWidgets/QWidget>
#include "ui_cppxtract.h"

class CppXtract : public QWidget
{
	Q_OBJECT

public:
	CppXtract(QWidget *parent = Q_NULLPTR);

private:
	Ui::CppXtractClass ui;
};
