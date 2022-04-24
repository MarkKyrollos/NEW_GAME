#include "main_menu.h"
#include "ui_main_menu.h"
#include <QtMultimedia>



main_menu::main_menu(QWidget *parent) ://opens the main menu
    QDialog(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
}

main_menu::~main_menu()
{
    delete ui;
}

void main_menu::on_start_clicked()
{
    if (ui->on->isChecked()){
    QMediaPlaylist *background = new QMediaPlaylist();
    background->addMedia(QUrl("qrc:/new/prefix1/JOJO.mp3"));
    background->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(background);
    music->play();
}
    //main.show();
    this->close();
    //main.play_sound(music_check);

}
//

void main_menu::on_exit_clicked()//exit
{
    this->close();
}


