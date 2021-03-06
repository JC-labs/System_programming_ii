#include "Lab6_GUI.hpp"
#include <qpushbutton.h>
#include "../MyParser/MyParser.hpp"
Lab6_GUI::Lab6_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() {
		try {
			auto res = parser::parse_syntax(ui.code->toPlainText().toStdString());
			parser::semantics_check(res);
			ui.result->setText("Compilation was successful!");
		} catch (std::exception &e) {
			ui.result->setText(e.what());
		}
	};
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}