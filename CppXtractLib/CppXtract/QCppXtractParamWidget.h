#pragma once

#include <QtWidgets/QWidget>

// D�claration anticip�e
class CppXtract;
class QFileSelectorX;

// Classe qui doit g�rer certains �l�ments d'interface graphique
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