#pragma once

#include <QtWidgets/QWidget>

// D�claration anticip�e
class CppXtract;

// Classe qui doit g�rer certains �l�ments d'interface graphique
class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT

public:
	QCppXtractParamWidget(CppXtract* mainWin);

	// Mettre le reste des m�thodes en temps et lieu ici

private :
	CppXtract* mMainWin;
};