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

  /*  if(map[7][3]==-2)
    {
        map[7][3]=1000; // opening the entrance door for room 1
    }*/
    DoorCheck(*map);

}


void enemy::incrementKillCount()
{
    ++killCount;
}


void enemy::random_movement()
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    QVector<QVector<bool>>* presencePoint=presence;

    srand(time(NULL));

    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    {
        moveUp(*charLocPoint,*presencePoint);
        if (health>0)
        {
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

        moveDown(*charLocPoint,*presencePoint);
        if (health>0)
        {
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
        moveLeft(*charLocPoint,*presencePoint);
        if (health>0)
        {
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
        moveRight(*charLocPoint,*presencePoint);
        if (health>0)
        {
            setPos(50+50*col,50+50*row);
            shoot(*charLoc, *presence);
        }
        else if(health<=0)
        {
            incrementKillCount();
        }
     }

}

void enemy::DoorCheck(QVector<QVector<int>>& map)
{


    if(enemy::killCount==2)
    {
        if(map[3][6]==-2)
        {
            map[3][6]=1000; // opening the exit door for room 1

            // TODO: check the locations of each door again thoroughly from Board.txt
            map[9][24]=1000; // opening the entrance door for room 2
        }
    }

       else if(enemy::killCount==4)
        {
            if(map[9][14]==-2)
            {
                map[9][14]=1000;



                map[26][9]=1000;
            }
        }
            else if (enemy::killCount==8)
            {
                if(map[14][5]==-2)
                {
                    map[14][5]=1000;
                }
            }


}

enemy::enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major, bool enem):character(helth, mvmt_spd,alive, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene, major)
{
    is_enemy=enem;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(random_movement()));
    T->start(mvmt_spd*1000);
}
