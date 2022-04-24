/********************************************************************************
** Form generated from reading UI file 'main_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_menu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *start;
    QPushButton *exit;
    QLabel *god;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QRadioButton *on;
    QRadioButton *off;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QPushButton *registor;
    QPushButton *login;
    QLineEdit *pass;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *main_menu)
    {
        if (main_menu->objectName().isEmpty())
            main_menu->setObjectName(QString::fromUtf8("main_menu"));
        main_menu->resize(611, 448);
        verticalLayoutWidget = new QWidget(main_menu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(430, 360, 171, 86));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        start = new QPushButton(verticalLayoutWidget);
        start->setObjectName(QString::fromUtf8("start"));

        verticalLayout->addWidget(start);

        exit = new QPushButton(verticalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));

        verticalLayout->addWidget(exit);

        god = new QLabel(main_menu);
        god->setObjectName(QString::fromUtf8("god"));
        god->setGeometry(QRect(10, 180, 201, 131));
        verticalLayoutWidget_2 = new QWidget(main_menu);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(430, 290, 171, 74));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        on = new QRadioButton(verticalLayoutWidget_2);
        on->setObjectName(QString::fromUtf8("on"));

        verticalLayout_2->addWidget(on);

        off = new QRadioButton(verticalLayoutWidget_2);
        off->setObjectName(QString::fromUtf8("off"));

        verticalLayout_2->addWidget(off);

        gridLayoutWidget = new QWidget(main_menu);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 330, 321, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(gridLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 1, 0, 1, 1);

        registor = new QPushButton(gridLayoutWidget);
        registor->setObjectName(QString::fromUtf8("registor"));

        gridLayout->addWidget(registor, 2, 1, 1, 1);

        login = new QPushButton(gridLayoutWidget);
        login->setObjectName(QString::fromUtf8("login"));

        gridLayout->addWidget(login, 2, 0, 1, 1);

        pass = new QLineEdit(gridLayoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));

        gridLayout->addWidget(pass, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);


        retranslateUi(main_menu);

        QMetaObject::connectSlotsByName(main_menu);
    } // setupUi

    void retranslateUi(QDialog *main_menu)
    {
        main_menu->setWindowTitle(QCoreApplication::translate("main_menu", "Dialog", nullptr));
        start->setText(QCoreApplication::translate("main_menu", "start", nullptr));
        exit->setText(QCoreApplication::translate("main_menu", "exit", nullptr));
        god->setText(QCoreApplication::translate("main_menu", "// escape from hell", nullptr));
        label->setText(QCoreApplication::translate("main_menu", "music", nullptr));
        on->setText(QCoreApplication::translate("main_menu", "on", nullptr));
        off->setText(QCoreApplication::translate("main_menu", "off", nullptr));
        registor->setText(QCoreApplication::translate("main_menu", "registor", nullptr));
        login->setText(QCoreApplication::translate("main_menu", "login", nullptr));
        label_2->setText(QCoreApplication::translate("main_menu", "username", nullptr));
        label_3->setText(QCoreApplication::translate("main_menu", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_menu: public Ui_main_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
