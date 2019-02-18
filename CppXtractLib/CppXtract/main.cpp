#include "stdafx.h"
#include "cppxtract.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CppXtract w;
	w.show();
	return a.exec();
}
