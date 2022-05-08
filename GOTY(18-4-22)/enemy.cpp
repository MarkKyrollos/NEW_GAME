#include "enemy.h"
#include "character.h"
#include "player.h"

/*
void enemy::Detection_Shooting(player p)
{
    if(abs(row-p.row)<=2)
    {
        shoot();
    }
}
*/

int enemy::killCount=0;

enemy::~enemy()
{
    incrementKillCount();

    if(killCount==8)
    {
        DoorTime(*MAP);
    }
}


void enemy::incrementKillCount()
{
    ++killCount;
}


void enemy::DoorTime(QVector<QVector<int>> &MAP)
{

    if(MAP[7][3]==-2)
    {
        MAP[7][3] = 1000; // opening the entrance door for room 1
    }


if(killCount==2)
{
    if(MAP[3][6]==-2)
    {
        MAP[3][6]=1000; // opening the exit door for room 1
      //  boardItems[3][6].setPixmap(grassImage);
        //boardItems[3][6].setPos(50+6*50,50+3*50);
        //scene->addItem(&boardItems[3][6]);

        MAP[9][24]=1000; // opening the entrance door for room 2
       // boardItems[9][25].setPixmap(grassImage);
        //boardItems[9][25].setPos(50+25*50,50+9*50);
        //scene->addItem(&boardItems[9][25]);
    }
}

   else if(killCount==4)
    {
        if(MAP[9][14]==-2)
        {
            MAP[9][14]=1000;
        /*    boardItems[9][14].setPixmap(grassImage);
            boardItems[9][14].setPos(50+14*50,50+9*50);
            scene->addItem(&boardItems[9][14]);*/



            MAP[26][9]=1000;
        /*    boardItems[26][9].setPixmap(grassImage);
            boardItems[26][9].setPos(50+9*50,50+26*50);
            scene->addItem(&boardItems[26][9]);*/
        }
    }
        else if (killCount==8)
        {
            if(MAP[14][5]== -2)
            {
            MAP[14][5]= 1000;

         /*       boardItems[14][5].setPixmap(grassImage);
                boardItems[14][5].setPos(50+5*50,50+14*50);
                scene->addItem(&boardItems[14][5]);*/
            }
        }
}


void enemy::random_movement()
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    QVector<QVector<bool>>* presencePoint=presence;



    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    {

        if (health>0)
        {
            moveUp(*charLocPoint,*presencePoint);
            setPos(50+50*col,50+50*row);
            shoot(*charLoc, *presence);
        }
        else if(health<=0)
        {
            incrementKillCount();
        }
    }


     else if(rand()%4==1) //moving downwards
     {
        if (health>0)
        {
            moveDown(*charLocPoint,*presencePoint);
            setPos(50+50*col,50+50*row);
            shoot(*charLoc, *presence);
        }
        else if(health<=0)
        {
            incrementKillCount();
        }
     }


     else if(rand()%4==2) // moving left
     {

        if (health>0)
        {
            moveLeft(*charLocPoint,*presencePoint);
            setPos(50+50*col,50+50*row);
            shoot(*charLoc, *presence);
        }
        else if(health<=0)
        {
            incrementKillCount();
        }
     }

     else if(rand()%4==3) // moving right
     {

        if(health>0)
        {
            moveRight(*charLocPoint,*presencePoint);
            setPos(50+50*col,50+50*row);
            shoot(*charLoc, *presence);
        }
        else if(health<=0)
        {
            incrementKillCount();
        }
     }

    DoorTime(*MAP);
}


enemy::enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major) : character(helth, mvmt_spd,alive, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene, major)
{
    //is_enemy=enem;
    MAP=&map;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(random_movement()));
    T->start(mvmt_spd*1000);
}
