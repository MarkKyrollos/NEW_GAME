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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QLineEdit *name;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *music_switch;
    QLabel *music_c;

    void setupUi(QDialog *main_menu)
    {
        if (main_menu->objectName().isEmpty())
            main_menu->setObjectName(QString::fromUtf8("main_menu"));
        main_menu->resize(400, 300);
        verticalLayoutWidget = new QWidget(main_menu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(230, 200, 171, 86));
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
        god->setGeometry(QRect(30, 10, 201, 131));
        name = new QLineEdit(main_menu);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(20, 210, 161, 21));
        verticalLayoutWidget_2 = new QWidget(main_menu);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(240, 50, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        music_switch = new QPushButton(verticalLayoutWidget_2);
        music_switch->setObjectName(QString::fromUtf8("music_switch"));

        verticalLayout_2->addWidget(music_switch);

        music_c = new QLabel(verticalLayoutWidget_2);
        music_c->setObjectName(QString::fromUtf8("music_c"));

        verticalLayout_2->addWidget(music_c);


        retranslateUi(main_menu);

        QMetaObject::connectSlotsByName(main_menu);
    } // setupUi

    void retranslateUi(QDialog *main_menu)
    {
        main_menu->setWindowTitle(QCoreApplication::translate("main_menu", "Dialog", nullptr));
        start->setText(QCoreApplication::translate("main_menu", "start", nullptr));
        exit->setText(QCoreApplication::translate("main_menu", "exit", nullptr));
        god->setText(QCoreApplication::translate("main_menu", "//", nullptr));
        music_switch->setText(QCoreApplication::translate("main_menu", "music", nullptr));
        music_c->setText(QCoreApplication::translate("main_menu", "music:off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_menu: public Ui_main_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
