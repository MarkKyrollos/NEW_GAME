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
   if (entry==true){
       QMediaPlayer * startup=new QMediaPlayer();
       startup->setMedia(QUrl("qrc:/new/prefix1/RELOAD.mp3"));
       startup->play();
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
}else{
       ui->god->setText("invaild must enter a vaild username and password or sign up");
   }
}
//

void main_menu::on_exit_clicked()//exit
{
    exit=true;
    this->close();
}



void main_menu::on_registor_clicked()
{
    usernames.push_back(ui->name->text());
    passwords.push_back(ui->pass->text());

}


void main_menu::on_login_clicked()
{
    int i =0;
   while(i<usernames.size()&&entry==false){
       if (ui->name->text()==usernames.at(i)&&passwords.at(i)==ui->pass->text()){
           entry=true;
       }
   }

}

