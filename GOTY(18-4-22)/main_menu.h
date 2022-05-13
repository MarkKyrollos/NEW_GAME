#ifndef MAIN_MENU_H
#define MAIN_MENU_H

//
#include <QDialog>
#include "mainwindow.h"
#include <QtMultimedia>
#include <QVector>
#include "game.h"
namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();
    QVector<QString> usernames;
    QVector<QString> passwords;
    bool entry=false;
    bool exit=false;

public slots:
    void on_start_clicked();

    void on_exit_clicked();

    //void on_music_switch_clicked();

private slots:
    void on_registor_clicked();

    void on_login_clicked();

private:
    Ui::main_menu *ui;
    //MainWindow main;
    bool check_user();
};

#endif // MAIN_MENU_H
