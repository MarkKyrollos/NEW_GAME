#ifndef MAIN_MENU_H
#define MAIN_MENU_H

//
#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_start_clicked();

    void on_exit_clicked();

    void on_music_switch_clicked();

private:
    Ui::main_menu *ui;
    //MainWindow main;
    bool music_check=false;
};

#endif // MAIN_MENU_H
