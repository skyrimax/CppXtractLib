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

	enum class OutputType { Screen = 0, Clipboard = 1, File = 2 };

	QCppXtractParamWidget(CppXtract* mainWin);

	const QString & inputFilename() const;
	const QString & outputFilename() const;
	bool isStatIncluded() const;

	// Fonction membre vérfiant la validité des options de sortie
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