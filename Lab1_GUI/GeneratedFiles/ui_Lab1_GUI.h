/********************************************************************************
** Form generated from reading UI file 'Lab1_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1_GUI_H
#define UI_LAB1_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1_GUIClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *key_1;
    QSpinBox *key_2;
    QComboBox *func_f;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ins;
    QPushButton *del;
    QPushButton *upd;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *findStr;
    QSpinBox *findNmb;
    QVBoxLayout *verticalLayout_3;
    QPushButton *find;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *findResult;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *cfindStr;
    QSpinBox *cfindNmb;
    QPushButton *cfind;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *cfindResStr;
    QSpinBox *cfindResNmb;
    QLineEdit *cfindResFunc;
    QSpacerItem *verticalSpacer_3;
    QPushButton *def;
    QPushButton *sort;

    void setupUi(QWidget *Lab1_GUIClass)
    {
        if (Lab1_GUIClass->objectName().isEmpty())
            Lab1_GUIClass->setObjectName(QStringLiteral("Lab1_GUIClass"));
        Lab1_GUIClass->resize(692, 392);
        horizontalLayout_2 = new QHBoxLayout(Lab1_GUIClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(Lab1_GUIClass);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        key_1 = new QLineEdit(Lab1_GUIClass);
        key_1->setObjectName(QStringLiteral("key_1"));

        horizontalLayout->addWidget(key_1);

        key_2 = new QSpinBox(Lab1_GUIClass);
        key_2->setObjectName(QStringLiteral("key_2"));

        horizontalLayout->addWidget(key_2);

        func_f = new QComboBox(Lab1_GUIClass);
        func_f->setObjectName(QStringLiteral("func_f"));

        horizontalLayout->addWidget(func_f);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        ins = new QPushButton(Lab1_GUIClass);
        ins->setObjectName(QStringLiteral("ins"));

        verticalLayout_2->addWidget(ins);

        del = new QPushButton(Lab1_GUIClass);
        del->setObjectName(QStringLiteral("del"));

        verticalLayout_2->addWidget(del);

        upd = new QPushButton(Lab1_GUIClass);
        upd->setObjectName(QStringLiteral("upd"));

        verticalLayout_2->addWidget(upd);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        findStr = new QLineEdit(Lab1_GUIClass);
        findStr->setObjectName(QStringLiteral("findStr"));

        horizontalLayout_3->addWidget(findStr);

        findNmb = new QSpinBox(Lab1_GUIClass);
        findNmb->setObjectName(QStringLiteral("findNmb"));

        horizontalLayout_3->addWidget(findNmb);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        find = new QPushButton(Lab1_GUIClass);
        find->setObjectName(QStringLiteral("find"));

        verticalLayout_3->addWidget(find);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(Lab1_GUIClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        findResult = new QLineEdit(Lab1_GUIClass);
        findResult->setObjectName(QStringLiteral("findResult"));
        findResult->setFrame(true);
        findResult->setReadOnly(true);

        horizontalLayout_6->addWidget(findResult);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cfindStr = new QLineEdit(Lab1_GUIClass);
        cfindStr->setObjectName(QStringLiteral("cfindStr"));

        horizontalLayout_4->addWidget(cfindStr);

        cfindNmb = new QSpinBox(Lab1_GUIClass);
        cfindNmb->setObjectName(QStringLiteral("cfindNmb"));

        horizontalLayout_4->addWidget(cfindNmb);

        cfind = new QPushButton(Lab1_GUIClass);
        cfind->setObjectName(QStringLiteral("cfind"));

        horizontalLayout_4->addWidget(cfind);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(Lab1_GUIClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        cfindResStr = new QLineEdit(Lab1_GUIClass);
        cfindResStr->setObjectName(QStringLiteral("cfindResStr"));
        cfindResStr->setReadOnly(true);

        horizontalLayout_5->addWidget(cfindResStr);

        cfindResNmb = new QSpinBox(Lab1_GUIClass);
        cfindResNmb->setObjectName(QStringLiteral("cfindResNmb"));
        cfindResNmb->setReadOnly(true);

        horizontalLayout_5->addWidget(cfindResNmb);

        cfindResFunc = new QLineEdit(Lab1_GUIClass);
        cfindResFunc->setObjectName(QStringLiteral("cfindResFunc"));

        horizontalLayout_5->addWidget(cfindResFunc);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        def = new QPushButton(Lab1_GUIClass);
        def->setObjectName(QStringLiteral("def"));

        verticalLayout->addWidget(def);

        sort = new QPushButton(Lab1_GUIClass);
        sort->setObjectName(QStringLiteral("sort"));

        verticalLayout->addWidget(sort);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Lab1_GUIClass);

        QMetaObject::connectSlotsByName(Lab1_GUIClass);
    } // setupUi

    void retranslateUi(QWidget *Lab1_GUIClass)
    {
        Lab1_GUIClass->setWindowTitle(QApplication::translate("Lab1_GUIClass", "Lab1_GUI", Q_NULLPTR));
        func_f->clear();
        func_f->insertItems(0, QStringList()
         << QApplication::translate("Lab1_GUIClass", "No_Value", Q_NULLPTR)
         << QApplication::translate("Lab1_GUIClass", "Value_1", Q_NULLPTR)
         << QApplication::translate("Lab1_GUIClass", "Value_2", Q_NULLPTR)
         << QApplication::translate("Lab1_GUIClass", "Value_3", Q_NULLPTR)
        );
        ins->setText(QApplication::translate("Lab1_GUIClass", "Insert", Q_NULLPTR));
        del->setText(QApplication::translate("Lab1_GUIClass", "Delete", Q_NULLPTR));
        upd->setText(QApplication::translate("Lab1_GUIClass", "Update", Q_NULLPTR));
        find->setText(QApplication::translate("Lab1_GUIClass", "Find", Q_NULLPTR));
        label_2->setText(QApplication::translate("Lab1_GUIClass", "Result:", Q_NULLPTR));
        cfind->setText(QApplication::translate("Lab1_GUIClass", "Find Next", Q_NULLPTR));
        label->setText(QApplication::translate("Lab1_GUIClass", "Result:", Q_NULLPTR));
        def->setText(QApplication::translate("Lab1_GUIClass", "Insert Default", Q_NULLPTR));
        sort->setText(QApplication::translate("Lab1_GUIClass", "Sort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab1_GUIClass: public Ui_Lab1_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1_GUI_H
