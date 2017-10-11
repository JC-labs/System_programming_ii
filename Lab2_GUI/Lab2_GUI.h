#pragma once

#include <QtWidgets/QWidget>
#include "ui_Lab2_GUI.h"

class Lab2_GUI : public QWidget
{
	Q_OBJECT

public:
	Lab2_GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab2_GUIClass ui;

protected slots:
	void start();
};
