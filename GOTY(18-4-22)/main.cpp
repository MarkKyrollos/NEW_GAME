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
#include <QVector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    main_menu w;
    w.show();
    //creating the view obj
    QVector<QVector<QVector<character*>>> charLoc(10, QVector<QVector<character*>>(10,QVector<character*>(2,NULL)));
    QVector<QVector<int>> map(10);
        QGraphicsView view;
        QBrush Brush(Qt::black);
        QGraphicsScene scene;
        view.setFixedSize(600,600);
        view.setWindowTitle("Maze Game");
        view.setBackgroundBrush(Brush);
        QFile file("Board.txt");
        file.open(QIODevice::ReadOnly);
        //connects file to stream
        QTextStream stream(&file);
        //create a 10x10 map
        QString temp;
        for (int i=0; i<10; i++)
        {
            map[i].resize(10);
            for (int j=0; j<10; j++)
            {
                //when reading from a text file. its a string
                stream>>temp;
                //convert the received data from string to integer
                map[i][j]=temp.toInt();
            }
        }
        player P1(100,5,true,up,1,1,"Placeholder",false,map, charLoc,true);
        charLoc[1][1][0]=&P1;
        //start drawing on the map
        QPixmap grassImage("Grass(1).png");
        grassImage=grassImage.scaledToHeight(55);
        grassImage=grassImage.scaledToWidth(55);
        QPixmap bricksImage("Bricks(1).png");
        bricksImage=bricksImage.scaledToHeight(50);
        bricksImage=bricksImage.scaledToWidth(50);
        //scaling the images
        //creating object of set pix map 1.grass 2. bricks
        QGraphicsPixmapItem boardItems[10][10];
        for (int row=0; row<10; row++)
        {
            for (int col=0; col<10; col++)
            {
                //setting image to corresponding number
                if (map[row][col]<0)
                {
                    boardItems[row][col].setPixmap(bricksImage);
                }
                else
                {
                    boardItems[row][col].setPixmap(grassImage);
                }
                //set position
                boardItems[row][col].setPos(50+col*50,50+row*50);
                //add to the scene
                scene.addItem(&boardItems[row][col]);
            }
        }
        scene.addItem(&P1);
        P1.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
        P1.setFocus();
        P1.grabKeyboard();
        view.setScene(&scene);
        view.show();
    return a.exec();
}

