#include "Lab1_GUI.hpp"
#include "tables.h"
#include <qpushbutton.h>
#include <qtablewidget.h>

Lab1_GUI::Lab1_GUI(QWidget *parent)	: QWidget(parent), nTbStud(2), 
									  lnTbStud(100), last_found_index(0) 
{
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(3);

	tb = new struct recrd[lnTbStud];
	tb[0] = {{"Diatlov", 88}, FunctionalField::value_1, 0};
	tb[1] = {{"Kutsar", 89}, FunctionalField::value_2, 0};
	updateTable();

	connect(ui.ins, &QPushButton::clicked, this, &Lab1_GUI::binaryInsert);
	connect(ui.del, &QPushButton::clicked, this, &Lab1_GUI::binaryDelete);
	connect(ui.upd, &QPushButton::clicked, this, &Lab1_GUI::binaryUpdate);
	connect(ui.def, &QPushButton::clicked, this, &Lab1_GUI::insertDefaultValue);
	connect(ui.find, &QPushButton::clicked, this, &Lab1_GUI::findBinary);
	connect(ui.cfind, &QPushButton::clicked, this, &Lab1_GUI::findCustom);
	connect(ui.sort, &QPushButton::clicked, this, &Lab1_GUI::sort);
}

void Lab1_GUI::updateTable() {
	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(nTbStud);
	for (int i = 0; i < nTbStud; i++) {
		auto item = new QTableWidgetItem(tr(tb[i].key.str));
		ui.tableWidget->setItem(i, 0, item);
		auto t = QString("%1").arg(tb[i].key.nMod).toStdString();
		item = new QTableWidgetItem(tr(t.c_str()));
		ui.tableWidget->setItem(i, 1, item);
		switch (tb[i].func._f) {
			case FunctionalField::no_value:
				item = new QTableWidgetItem(tr("No Value"));
				break;
			case FunctionalField::value_1:
				item = new QTableWidgetItem(tr("Value #1"));
				break;
			case FunctionalField::value_2:
				item = new QTableWidgetItem(tr("Value #2"));
				break;
			case FunctionalField::value_3:
				item = new QTableWidgetItem(tr("Value #3"));
				break;
		}
		ui.tableWidget->setItem(i, 2, item);
	}
}

void Lab1_GUI::insertDefaultValue() {
	struct recrd t;
	t = {{"Diatlov", 89ul}, FunctionalField::value_1, 0};
	insLin(&t, tb, &nTbStud);
	t = {{"Gazizov", 89ul}, FunctionalField::value_3, 0};
	insLin(&t, tb, &nTbStud);
	t = {{"Gazizov", 55ul}, FunctionalField::value_1, 0};
	insLin(&t, tb, &nTbStud);
	t = {{"Bilyk", 8ul}, FunctionalField::value_2, 0};
	insLin(&t, tb, &nTbStud);
	t = {{"Dudko", 80ul}, FunctionalField::value_1, 0};
	insLin(&t, tb, &nTbStud);
	updateTable();
}

void Lab1_GUI::sort() {
	srtBin(tb, nTbStud);
	updateTable();
}

void Lab1_GUI::findCustom() {
	auto temp = ui.cfindStr->text().toStdString();
	auto res = ui.cfindNmb->value();
	int t = 0;
	int max_t = 0;
	for (int i = 0; i < nTbStud; i++) {
		t = coincSymbs(temp.c_str(), tb[i].key.str);
		if (t > max_t)
			max_t = t;
	}
	res = max_t;
	t = 0;

	for (; last_found_index < nTbStud && t < res; last_found_index++) 
		t = coincSymbs(temp.c_str(), tb[last_found_index].key.str);

	if (last_found_index != nTbStud) {
		ui.cfindResStr->setText(tb[last_found_index - 1].key.str);
		ui.cfindResNmb->setValue(tb[last_found_index - 1].key.nMod);
		ui.cfindResFunc->setText("Value #" + QString::number((int) tb[last_found_index - 1].func._f));
	} else {
		ui.cfindResStr->setText("");
		ui.cfindResNmb->setValue(0);
		ui.cfindResFunc->setText("The key wasn't found");

		last_found_index = 0;
	}
	updateTable();
}

#include <string.h>
void Lab1_GUI::findBinary() {
	auto temp = ui.findStr->text().toStdString();
	struct keyStr t = {_strdup(temp.c_str()), (unsigned long) ui.findNmb->value()};
	auto res = selLin(t, tb, nTbStud);
	if (res)
		ui.findResult->setText("Value #" + QString::number((int) res->func._f));
	else
		ui.findResult->setText("The key wasn't found");
	updateTable();
}

void Lab1_GUI::binaryInsert() {
	auto temp = ui.key_1->text().toStdString();
	struct recrd t = {{_strdup(temp.c_str()), (unsigned long) ui.key_2->value()},
		(FunctionalField) ui.func_f->currentIndex(), 0};
	insLin(&t, tb, &nTbStud);
	updateTable();
}

void Lab1_GUI::binaryDelete() {
	auto temp = ui.key_1->text().toStdString();
	struct recrd t = {{_strdup(temp.c_str()), (unsigned long) ui.key_2->value()},
		(FunctionalField) ui.func_f->currentIndex(), 0};
	delLin(&t, tb, &nTbStud);
	updateTable();
}

void Lab1_GUI::binaryUpdate() {
	auto temp = ui.key_1->text().toStdString();
	struct recrd t = {{_strdup(temp.c_str()), (unsigned long) ui.key_2->value()},
		(FunctionalField) ui.func_f->currentIndex(), 0};
	updLin(t.key, &t, tb, &nTbStud);
	updateTable();
}
