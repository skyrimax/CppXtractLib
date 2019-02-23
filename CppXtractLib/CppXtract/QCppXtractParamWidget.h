#pragma once

#include <QtWidgets/QWidget>

// Déclaration anticipée
class CppXtract;

// Classe qui doit gérer certains éléments d'interface graphique
class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT

public:
	QCppXtractParamWidget(CppXtract* mainWin);

	// Mettre le reste des méthodes en temps et lieu ici

private :
	CppXtract* mMainWin;
};