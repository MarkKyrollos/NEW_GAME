#include "doortimer.h"
#include <QTimer>

DoorTimer::DoorTimer(QVector<QVector<int>>& map,QGraphicsScene& scene)
{
    // create a timer

    this->map=&map;
    this->scene=&scene;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(Open_Door(map)));
    T->start(1000);
}


void DoorTimer::Open_door(QVector<QVector<int>>& map, QGraphicsPixmapItem boardItems[30][30])
{
    QPixmap grassImage("Grass(1).png");

    grassImage=grassImage.scaledToHeight(55);
    grassImage=grassImage.scaledToWidth(55);

  /*  if(map[7][3]==-2)
    {
        map[7][3]=1000; // opening the entrance door for room 1
    }*/

    if(enemy::killCount==0)
    {
        if(map[3][6]==-2)
        {
            map[3][6]=1000; // opening the exit door for room 1
            boardItems[3][6].setPixmap(grassImage);
            boardItems[3][6].setPos(50+6*50,50+3*50);
            scene->addItem(&boardItems[3][6]);

            // TODO: check the locations of each door again thoroughly from Board.txt
            map[9][25]=1000; // opening the entrance door for room 2
            boardItems[9][25].setPixmap(grassImage);
            boardItems[9][25].setPos(50+25*50,50+9*50);
            scene->addItem(&boardItems[9][25]);
        }
    }

       else if(enemy::killCount==0)
        {
            if(map[9][14]==-2)
            {
                map[9][14]=1000;
                boardItems[9][14].setPixmap(grassImage);
                boardItems[9][14].setPos(50+14*50,50+9*50);
                scene->addItem(&boardItems[9][14]);



                map[26][9]=1000;
                boardItems[26][9].setPixmap(grassImage);
                boardItems[26][9].setPos(50+9*50,50+26*50);
                scene->addItem(&boardItems[26][9]);
            }
        }
            else if (enemy::killCount==0)
            {
                if(map[14][5]==-2)
                {
                    map[14][5]=1000;
                    boardItems[14][5].setPixmap(grassImage);
                    boardItems[14][5].setPos(50+5*50,50+14*50);
                    scene->addItem(&boardItems[14][5]);
                }
            }

}
