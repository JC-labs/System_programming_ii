#pragma once
#include <QtWidgets/QWidget>
#include "ui_Lab4_GUI.h"
class Lab4_GUI : public QWidget {
	Q_OBJECT

public:
	Lab4_GUI(QWidget *parent = Q_NULLPTR);
private:
	Ui::Lab4_GUIClass ui;
};