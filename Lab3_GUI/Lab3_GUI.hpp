#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab3_GUI.h"
class Lab3_GUI : public QWidget {
	Q_OBJECT

public:
	Lab3_GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab3_GUIClass ui;
};
