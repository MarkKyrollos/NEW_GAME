#include "major.h"


major::major(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major):enemy(helth,mvmt_spd,alive,Facer,Rowd,Cold,map,charLoc,Playa,presence,scene, major)
{
    QPixmap majorE("major.png");
       majorE=majorE.scaledToWidth(50);
       majorE=majorE.scaledToHeight(50);
       setPixmap(majorE);
       setPos(50+50*col,50+50*row); // modify 2 major enemies' placement on the map
        /* Mark, this stuff is done in the base class constructor
       health=helth;
       movement_speed=mvmt_spd;
       is_alive=alive;
       face=Facer;
       row=Rowd;
       col=Cold;
       this->map =&map;
       this->charLoc= &charLoc;
       this->presence=&presence;
       this->scene()=&scene;
       Player=Playa;
       */
}


// this random movement function should be called repetitively
/*
void major::random_movement()
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    QVector<QVector<bool>>* presencePoint=presence;

    while(health>=0)
    {

    srand(time(NULL));


    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    { // not gonna use the our defined moveUp etc since major enemies CAN go through walls, redefined new movements

        moveUp(*charLocPoint,*presence);
    }


    else if(rand()%4==1) //moving downwards
    {
        /*
        character* nullifier=NULL;
        charLocPoint[row][col][1] = nullifier;

                if (charLocPoint[row][col][0] == nullifier)
                {
                    presencePoint[row][col]=false;
                }
                row++;
                charLocPoint[row][col][1]=this;

                presencePoint[row][col]=true;
                face=down*/
        //moveDown(*charLocPoint,*presence);
    //}


    //else if(rand()%4==2) // moving left
    //{
        /*
        character* nullifier=NULL;
        charLocPoint[row][col][1] = nullifier;

                if (charLocPoint[row][col][0] == nullifier)
                {
                    presencePoint[row][col]=false;
                }
                col--;
                charLocPoint[row][col][1]=this;

                presencePoint[row][col]=true;
                face=left;
                */
/*        move
    }

    else if(rand()%4==3) // moving right
    {
        character* nullifier=NULL;
        charLocPoint[row][col][1] = nullifier;

                if (charLocPoint[row][col][0] == nullifier)
                {
                    presencePoint[row][col]=false;
                }
                col++;
                charLocPoint[row][col][1]=this;

                presencePoint[row][col]=true;
                face=right;
    }

setPos(50+50*col,50+50*row);

    }
*/
//}
