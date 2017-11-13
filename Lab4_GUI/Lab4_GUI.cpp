#include "Lab4_GUI.hpp"
#include <qpushbutton.h>
#include "../MyParser/MyParser.hpp"
Lab4_GUI::Lab4_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() {
		try {
			auto res = parser::parse_syntax(ui.code->toPlainText().toStdString());
			std::string temp;
			for (auto it : res)
				temp += it.to_string() + ";\t";
			ui.result->setText(QString::fromStdString(temp));
		} catch (std::exception &e) {
			ui.result->setText(e.what());
		}
	};
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}