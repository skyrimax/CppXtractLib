#include "stdafx.h"
#include "qtplaintextdialog.h"

QtPlainTextDialog::QtPlainTextDialog(QWidget *parent, QString results)
	: QDialog(parent)
{
	setupUi(this);
	//Insérer les résultats dans l'objet QPlainTextEdit
	resultOutput->setPlainText(results);
	//Rendre le contenu en lecture seulement
	resultOutput->setReadOnly(true);
}

QtPlainTextDialog::~QtPlainTextDialog()
{
}
