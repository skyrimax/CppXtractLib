#pragma once
#ifndef Q_CPP_XTRACT_PARAM_WIDGET_H
#define Q_CPP_XTRACT_PARAM_WIDGET_H

#include <QWidget>
#include <CppXtractLibGUI.h>

class CppXtractLibGUI; // déclaration anticipée
class QFileSelector;

class QCppXtractParamWidget : public QWidget
{
	Q_OBJECT

public:
	QCppXtractParamWidget(CppXtractLibGUI *mainWin);

	const QString & inputFilename() const;
	const QString & outputFilename() const;
	bool isStatIncluded() const;
	

	// Validation
	bool isValid() const;

	// Ajout de la classe "Output"
	enum class OutputType {Screen = 0 , Clipboard = 1 ,File = 2 };

	OutputType outputType() const;

private:
	CppXtractLibGUI * mainWin;
	QFileSelector * mInputFileSelector;
	QFileSelector * mOutputFileSelector;
	QButtonGroup * mButtonGroup;
	QGroupBox * mOutputGroupBox;
	QRadioButton * mOutputScreenRadioButton;
	QRadioButton * mOutputClipboardRadioButton;
	QRadioButton * mOutputFileRadioButton;
	QCheckBox * mIncludeStatInfoCheckBox;

private slots:
	void updateGui();

signals:
	void parameterChanged();
};

#endif	//Q_CPP_XTRACT_PARAM_WIDGET_H
