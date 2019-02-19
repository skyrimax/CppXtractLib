#pragma once
#ifndef Q_CPP_XTRACT_PARAM_WIDGET_H
#define Q_CPP_XTRACT_PARAM_WIDGET_H

#include <QWidget>

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

private:
	QFileSelector * mInputFileSelector;
};

#endif	//Q_CPP_XTRACT_PARAM_WIDGET_H
