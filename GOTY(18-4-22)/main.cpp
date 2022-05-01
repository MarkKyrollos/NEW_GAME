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
#include "doortimer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
   // main_menu w;
    //w.show();
    //creating the view obj
    QVector<QVector<QVector<character*>>> charLoc(30, QVector<QVector<character*>>(30,QVector<character*>(2,NULL))); //A 3D vector that stores character addresses, the third dimension is to allow both player and enemy to be in the same space
    //The vector is in charge of collision detection
    QVector<QVector<bool>> presence(30,QVector<bool>(30,false)); //this one was entirely created because projectiles couldn't read charLoc, so we needed another way of determining if the projectile collided with something
    QVector<QVector<int>> map(30); //map vector
    srand(time(NULL));
        //QGraphicsView view; //trying to port this from the lab led to the main menu breaking beyond repair, we were unaware this was a widget
        QBrush Brush(Qt::black); //brush for background (if you see the background for whatever reason)
        QGraphicsScene scene; //the scene where everything is displayed
        //view.setFixedSize(1500,1000); //changes size of window
        //view.setWindowTitle("Maze Game"); //renames the window
        //view.setBackgroundBrush(Brush); //sets the background color
        QFile file("Board.txt"); //opens the board file to read from it
        file.open(QIODevice::ReadOnly);
        //connects file to stream
        QTextStream stream(&file);
        //create a 30x30 map
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

        player* P1; //creates a player

        P1=new player(100,5,true,up,1,1,"Placeholder",map, charLoc,true, presence, scene, false);
        minor* E1=new minor(100,1,true,down,5,5,map,charLoc,false,presence,scene, false); //creates an enemy
        minor* E2=new minor(100,1,true,down,5,8,map,charLoc,false,presence,scene, false);
        minor* E3=new minor(100,1,true,down,17,3,map,charLoc,false,presence,scene, false);
        minor* E4=new minor(100,1,true,down,26,1,map,charLoc,false,presence,scene, false);
        major* E5=new major(100,0.5,true,down,24,3,map,charLoc,false,presence,scene, true);
        major* E6=new major(100,0.5,true,down,6,17,map,charLoc,false,presence,scene, true);
        major* E7=new major(100,0.5,true,down,13,20,map,charLoc,false,presence,scene, true);
        major* E8=new major(100,0.5,true,down,20,8,map,charLoc,false,presence,scene, true);

        //program will crash whe an enemy dies
        //start drawing on the map
        QPixmap grassImage("Netherrack.png");

        grassImage=grassImage.scaledToHeight(55);
        grassImage=grassImage.scaledToWidth(55);
        QPixmap bricksImage("soul_sand.png");
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
                }//
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
        scene.addItem(P1);//adds elements to the scene
        scene.addItem(E1);
        scene.addItem(E2);
        scene.addItem(E3);
        scene.addItem(E4);
        scene.addItem(E5);
        scene.addItem(E6);
        scene.addItem(E7);
        scene.addItem(E8);

        P1->setFlag(QGraphicsPixmapItem::ItemIsFocusable); //makes the focus on the character
        P1->setFocus();
        P1->grabKeyboard(); //brute forces the character into accepting keyboard input
        //view.setScene(&scene); //sets the scene in the Graphics View
        //view.show(); //displays the GraphicsView


        MainWindow w(nullptr,&scene,P1);
        w.show();


    return a.exec();
}

