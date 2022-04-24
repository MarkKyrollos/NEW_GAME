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
if(background_music==false){
    music_loop =new QTimer(this);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/JOJO.mp3"));
    music->play();
    connect(music_loop,SIGNAL(timeout()),this,SLOT(timefunction(music)));
      music_loop->start(50000);
}
ui->graphicsView->setScene(this->scene);
ui->graphicsView->show();
}
//play music
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timefunction(QMediaPlayer * music)
{
    music->setPosition(0);
    music->play();

}

void MainWindow::play_sound(bool music){
    if(music==true){
        music_loop =new QTimer(this);

        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/JOJO.mp3"));
        music->play();
        connect(music_loop,SIGNAL(timeout()),this,SLOT(timefunction(music)));
          music_loop->start(50000);

}


}
