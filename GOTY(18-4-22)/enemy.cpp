#include "enemy.h"
#include "character.h"
#include "player.h"

/* place this function in a do-while loop inside the main,
 *IMPORTANT: and actually we need to place each of the three rooms in separate do-while in order to proceed sequentially in the program, and to call certain functions repetitively like this one below*/
void enemy::Detection_Shooting(player p)
{
    while(abs(row-p.row)<=2)
    {
        shoot(*charLoc);
    }
}


int enemy::killCount=0;

enemy::~enemy()
{
    incrementKillCount();

}

void enemy::incrementKillCount()
{
    killCount++;
}
void enemy::random_movement()
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    QVector<QVector<bool>>* presencePoint=presence;




    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    { // not gonna use the our defined moveUp etc since major enemies CAN go through walls, redefined new movements
        moveUp(*charLocPoint,*presencePoint);
        if (health>0)
        {
            setPos(50+50*col,50+50*row);
            shoot(*charLoc);
        }

    }


     else if(rand()%4==1) //moving downwards
     {

        moveDown(*charLocPoint,*presencePoint);
        if (health>0)
        {
            setPos(50+50*col,50+50*row);
            shoot(*charLoc);
        }
     }


     else if(rand()%4==2) // moving left
     {
        moveLeft(*charLocPoint,*presencePoint);
        if (health>0)
        {
            setPos(50+50*col,50+50*row);
            shoot(*charLoc);
        }
     }

     else if(rand()%4==3) // moving right
     {
        moveRight(*charLocPoint,*presencePoint);
        if (health>0)
        {
            setPos(50+50*col,50+50*row);
            shoot(*charLoc);
        }
     }



}

enemy::enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major):character(helth, mvmt_spd,alive, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene, major)
{
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(random_movement()));
    T->start(mvmt_spd*1000);
}
