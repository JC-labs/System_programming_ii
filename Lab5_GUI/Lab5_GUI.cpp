#include "Lab5_GUI.hpp"
#include <qpushbutton.h>
#include "../MyParser/MyParser.hpp"
Lab5_GUI::Lab5_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() {
		try {
			auto res = parser::parse_syntax_pascal(ui.code->toPlainText().toStdString());
			ui.result->setText("Compilation was successful!");
		} catch (std::exception &e) {
			ui.result->setText(e.what());
		}
	};
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}