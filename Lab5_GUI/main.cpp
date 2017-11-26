#include "Lab5_GUI.hpp"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab5_GUI w;
	w.show();
	return a.exec();
}