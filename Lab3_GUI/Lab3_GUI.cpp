#include "Lab3_GUI.hpp"
#include <QListWidget>
#include "../MyParser/MyParser.hpp"
Lab3_GUI::Lab3_GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	auto temp = [this]() { 
		auto res = parser::parse(ui.code->toPlainText().toStdString());
		ui.result->clear();
		for (auto it : res)
			ui.result->addItem(QString::fromStdString(it.text()));
	};
	connect(ui.parse, &QPushButton::clicked, temp);
	temp();
}