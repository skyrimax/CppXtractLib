#pragma once

#include <QDialog>
#include "ui_qtplaintextdialog.h"

class QtPlainTextDialog : public QDialog, public Ui::QtPlainTextDialog
{
	Q_OBJECT

public:
	QtPlainTextDialog(QWidget *parent = Q_NULLPTR,QString results= "");
	~QtPlainTextDialog();
};
