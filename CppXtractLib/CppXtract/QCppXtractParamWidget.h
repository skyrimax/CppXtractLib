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

	enum class OutputType { Screen = 0, Clipboard = 1, File = 2 };

	QCppXtractParamWidget(CppXtract* mainWin);

	const QString & inputFilename() const;
	const QString & outputFilename() const;
	bool isStatIncluded() const;

	// Fonction membre v�rfiant la validit� des options de sortie
	bool isValid() const;

private :
	CppXtract* mMainWin;
	QFileSelectorX* mInputFileSelector;
	QFileSelectorX* mOutputFileSelector;

	QButtonGroup* mButtonGroup;
	QGroupBox* mOutputGroupBox;
	QRadioButton* mOutputScreenRadioButton;
	QRadioButton* mOutputClipboardRadioButton;
	QRadioButton* mOutputFileRadioButton;
	QCheckBox* mIncludeStatInfoCheckBox;

signals:
	void parameterChanged();

private slots:
	void updateGui();
};