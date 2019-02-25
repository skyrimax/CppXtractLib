#pragma once

#ifndef Q_CPP_XTRACT_PARAM_WIDGET_H
#define Q_CPP_XTRACT_PARAM_WIDGET_H

#include <QWidget>

class CppXtract; //Déclaration anticipée
class QFileSelectorX;

class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT

public:
	QCppXtractParamWidget(CppXtract *mainWin);

	enum class OutputType {Screen=0, Clipboard=1, File=2};

	const QString & inputFilename() const;
	const QString & outputFilename() const;
	bool isStatIncluded() const;
	bool isValid() const;
	int outputType();


private :
	CppXtract *mMainWin;
	QFileSelectorX *mInputFileSelector;
	QFileSelectorX *mOutputFileSelector;

	QButtonGroup *mButtonGroup;
	QGroupBox *mOutputGroupBox;
	QRadioButton *mOutputScreenRadioButton;
	QRadioButton *mOutputClipboardRadioButton;
	QRadioButton *mOutputFileRadioButton;
	QCheckBox *mIncludeStatInfoCheckBox;

private slots:
	void updateGui();

signals:
	void parameterChanged();
};

#endif // Q_CPP_XTRACT_PARAM_WIDGET_H