#include "Lab3_GUI.hpp"
#include "../MyParser/MyParser.hpp"
Lab3_GUI::Lab3_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() { parser::parse(ui.code->toPlainText().toStdString()); };
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}
