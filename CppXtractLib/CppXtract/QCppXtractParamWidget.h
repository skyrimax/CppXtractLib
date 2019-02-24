#pragma once

#include <QtWidgets/QWidget>

// Déclaration anticipée
class CppXtract;
class QFileSelectorX;

// Classe qui doit gérer certains éléments d'interface graphique
class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT

public:
	QCppXtractParamWidget(CppXtract* mainWin);

	const QString & inputFilename() const;
	const QString & outputFilename() const;
	bool isStatIncluded() const;

private :
	CppXtract* mMainWin;
	QFileSelectorX* mInputFileSelector;
	QFileSelectorX* mOutputFileSelector;
};