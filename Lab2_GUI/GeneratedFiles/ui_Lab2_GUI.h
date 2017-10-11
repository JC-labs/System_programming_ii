/********************************************************************************
** Form generated from reading UI file 'Lab2_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB2_GUI_H
#define UI_LAB2_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab2_GUIClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *code;
    QVBoxLayout *verticalLayout;
    QLineEdit *input;
    QTextBrowser *output;
    QPushButton *start;

    void setupUi(QWidget *Lab2_GUIClass)
    {
        if (Lab2_GUIClass->objectName().isEmpty())
            Lab2_GUIClass->setObjectName(QStringLiteral("Lab2_GUIClass"));
        Lab2_GUIClass->resize(668, 455);
        horizontalLayout_2 = new QHBoxLayout(Lab2_GUIClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        code = new QTextBrowser(Lab2_GUIClass);
        code->setObjectName(QStringLiteral("code"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(12);
        code->setFont(font);

        horizontalLayout_2->addWidget(code);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        input = new QLineEdit(Lab2_GUIClass);
        input->setObjectName(QStringLiteral("input"));
        input->setFont(font);

        verticalLayout->addWidget(input);

        output = new QTextBrowser(Lab2_GUIClass);
        output->setObjectName(QStringLiteral("output"));
        output->setFont(font);

        verticalLayout->addWidget(output);

        start = new QPushButton(Lab2_GUIClass);
        start->setObjectName(QStringLiteral("start"));
        start->setFont(font);

        verticalLayout->addWidget(start);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Lab2_GUIClass);

        QMetaObject::connectSlotsByName(Lab2_GUIClass);
    } // setupUi

    void retranslateUi(QWidget *Lab2_GUIClass)
    {
        Lab2_GUIClass->setWindowTitle(QApplication::translate("Lab2_GUIClass", "Lab2_GUI", Q_NULLPTR));
        input->setText(QApplication::translate("Lab2_GUIClass", "dlcccclldlcldllc", Q_NULLPTR));
        start->setText(QApplication::translate("Lab2_GUIClass", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab2_GUIClass: public Ui_Lab2_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB2_GUI_H
