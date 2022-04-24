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

void DoorTimer::Open_door(QVector<QVector<int>>& map)
{
    QPixmap grassImage("Grass(1).png");

    grassImage=grassImage.scaledToHeight(55);
    grassImage=grassImage.scaledToWidth(55);
    if(map[7][3]==-2)
    {
        map[7][3]=1000;
    }
    if(enemy::killCount>=2)
    {
        if(map[3][8]==-2)
        {
            map[3][8]=1000;
            //boardItems[3][8].setPixmap(grassImage);
            map[8][25]=1000;
            //boardItems[8][25].setPixmap(grassImage);
        }
        if(enemy::killCount>=4)
        {
            if(map[9][15]==-2)
            {
                map[9][15]=1000;
                //boardItems[9][15].setPixmap(grassImage);
                map[26][9]=1000;
                //boardItems[26][9].setPixmap(grassImage);
            }
            if (enemy::killCount>=8)
            {
                if(map[14][5]==-2)
                {
                    map[14][5]=1000;
                    //boardItems[14][5].setPixmap(grassImage);
                }
            }
        }
    }
}
