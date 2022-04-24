#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "main_menu.h"
#include "ui_main_menu.h"


MainWindow::MainWindow(QWidget *parent, QGraphicsScene* scene)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->scene=scene;
    ui->setupUi(this);
    //to play music on a loop
    openmenu();

ui->graphicsView->setScene(this->scene);
ui->graphicsView->show();
}
//play music
MainWindow::~MainWindow()
{
    delete ui;
}//

void MainWindow::openmenu()
{
    main_menu main_menu;
    main_menu.setModal(true);
    main_menu.exec();

}

