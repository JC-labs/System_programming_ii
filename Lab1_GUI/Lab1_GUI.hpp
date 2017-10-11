#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab1_GUI.h"

class Lab1_GUI : public QWidget
{
	Q_OBJECT

public:
	Lab1_GUI(QWidget *parent = Q_NULLPTR);

protected slots:
	void updateTable();
	void binaryInsert();
	void binaryDelete();
	void binaryUpdate();
	void insertDefaultValue();
	void sort();
	void findBinary();
	void findCustom();

private:
	Ui::Lab1_GUIClass ui;
	int nTbStud, lnTbStud;
	struct recrd *tb;

	unsigned long last_found_index;
};
