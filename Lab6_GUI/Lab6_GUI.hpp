#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab6_GUI.h"
class Lab6_GUI : public QWidget {
	Q_OBJECT
public:
	Lab6_GUI(QWidget *parent = Q_NULLPTR);
private:
	Ui::Lab6_GUIClass ui;
};