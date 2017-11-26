#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab5_GUI.h"
class Lab5_GUI : public QWidget {
	Q_OBJECT
public:
	Lab5_GUI(QWidget *parent = Q_NULLPTR);
private:
	Ui::Lab5_GUIClass ui;
};