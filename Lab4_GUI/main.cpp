#include "Lab4_GUI.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab4_GUI w;
	w.show();
	return a.exec();
}
