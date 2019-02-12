#include "CppXtractLibGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CppXtractLibGUI w;
	w.show();
	return a.exec();
}
