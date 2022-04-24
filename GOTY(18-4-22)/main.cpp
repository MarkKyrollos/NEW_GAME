#include "mainwindow.h"
#include "main_menu.h"
#include <QApplication>
#include <QGraphicsView> //sets window title and set fixed width
#include <QGraphicsScene>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"
#include "character.h"
#include "projectile.h"
#include "enemy.h"
#include "major.h"
#include "minor.h"
#include <QVector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
   // main_menu w;
    //w.show();
    //creating the view obj
    QVector<QVector<QVector<character*>>> charLoc(30, QVector<QVector<character*>>(30,QVector<character*>(2,NULL)));
    QVector<QVector<bool>> presence(30,QVector<bool>(30,false));
    QVector<QVector<int>> map(30);
        QGraphicsView view;
        QBrush Brush(Qt::black);
        QGraphicsScene scene;
        view.setFixedSize(1500,1000);
        view.setWindowTitle("Maze Game");
        view.setBackgroundBrush(Brush);
        QFile file("Board.txt");
        file.open(QIODevice::ReadOnly);
        //connects file to stream
        QTextStream stream(&file);
        //create a 10x10 map
        QString temp;
        for (int i=0; i<30; i++)
        {
            map[i].resize(30);
            for (int j=0; j<30; j++)
            {
                //when reading from a text file. its a string
                stream>>temp;
                //convert the received data from string to integer
                map[i][j]=temp.toInt();
            }
        }
        player* P1;
        P1=new player(100,5,true,up,1,1,"Placeholder",false,map, charLoc,true, presence, scene);
        minor* E1=new minor(100,0,true,down,5,5,map,charLoc,false,presence,scene);
        minor* E2=new minor(100,0,true,down,5,8,map,charLoc,false,presence,scene);
        minor* E3=new minor(100,0,true,down,1,9,map,charLoc,false,presence,scene);
        charLoc[1][1][0]=P1;
        //start drawing on the map
        QPixmap grassImage("Grass(1).png");

        grassImage=grassImage.scaledToHeight(55);
        grassImage=grassImage.scaledToWidth(55);
        QPixmap bricksImage("Bricks(1).png");
        bricksImage=bricksImage.scaledToHeight(50);
        bricksImage=bricksImage.scaledToWidth(50);
        QPixmap enemy_wall("enemy_wall.png");
        enemy_wall=enemy_wall.scaledToHeight(50);
        enemy_wall=enemy_wall.scaledToWidth(50);
        QPixmap hole_image("lava.png");
        hole_image=hole_image.scaledToHeight(55);
        hole_image=hole_image.scaledToWidth(55);
        QPixmap door_image("door.png");
        door_image=door_image.scaledToHeight(25);
        door_image=door_image.scaledToWidth(50);

        //scaling the images
        //creating object of set pix map 1.grass 2. bricks
        QGraphicsPixmapItem boardItems[30][30];
        for (int row=0; row<30; row++)
        {
            for (int col=0; col<30; col++)
            {
                //setting image to corresponding number
                if (map[row][col]==-2)
                {
                    boardItems[row][col].setPixmap(door_image);
                }

                else if(map[row][col]==-1)
                {
                    boardItems[row][col].setPixmap(hole_image);
                }
                else if(map[row][col]==-3){

                    boardItems[row][col].setPixmap(  enemy_wall);}
                else if(map[row][col]==-4){

                    boardItems[row][col].setPixmap(bricksImage);
                }
                else{

                    boardItems[row][col].setPixmap(grassImage);
                }
                //set position
                boardItems[row][col].setPos(50+col*50,50+row*50);
                //add to the scene
                scene.addItem(&boardItems[row][col]);
            }
        }
        scene.addItem(P1);
        scene.addItem(E1);
        scene.addItem(E2);
        scene.addItem(E3);
        P1->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
        P1->setFocus();
        P1->grabKeyboard();
        view.setScene(&scene);
        view.show();

    return a.exec();
}

