#include "mainwindow.h"
#include "main_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    main_menu w;
    w.show();
    return a.exec();
}

