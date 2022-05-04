#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "main_menu.h"
#include "ui_main_menu.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent, QGraphicsScene* scene,player *P1)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    PlayerPoint=P1;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(update_health()));
    this->scene=scene;
    ui->setupUi(this);
    //to play music on a loop
    openmenu();

ui->graphicsView->setScene(this->scene);
T->start(150);
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
    if (main_menu.exit==true){
        this->close();
    };

}

void MainWindow::update_health()
{
    ui->label->setText("<font color='green'>Health:"+ QString::number(PlayerPoint->health)+"</font>");
}

void MainWindow(){}

