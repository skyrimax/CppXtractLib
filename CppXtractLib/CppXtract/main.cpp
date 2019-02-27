#include "stdafx.h"
#include "cppxtract.h"
#include <QtWidgets/QApplication>

// Icon made by Freepik from www.flaticon.com
// Author : https://www.flaticon.com/authors/freepik
// Icon : https://www.flaticon.com/free-icon/cpp-file-format-symbol_29039#term=cpp&page=1&position=1
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CppXtract w;
	w.show();
	return a.exec();
}
