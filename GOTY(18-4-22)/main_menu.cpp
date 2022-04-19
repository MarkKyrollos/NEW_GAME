#include "main_menu.h"
#include "ui_main_menu.h"



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
    //main.setname(ui->name->text());
    main.show();
    this->close();
    main.play_sound(music_check);

}


void main_menu::on_exit_clicked()//exit
{
    this->close();
}


void main_menu::on_music_switch_clicked()//this flips the switch on music
{
    if(bool music_check=false){
        music_check=true;



    }
    else {
        music_check=false;
    }
}
