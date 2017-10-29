#include "Lab4_GUI.hpp"
#include <qpushbutton.h>
#include "../MyParser/MyParser.hpp"
Lab4_GUI::Lab4_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() {
		//auto res = parser::parse(ui.code->toPlainText().toStdString());
	};
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}