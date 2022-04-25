#include "minor.h"

minor::minor(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major):enemy(helth,mvmt_spd,alive,Facer,Rowd,Cold,map,charLoc,Playa,presence,scene, major)
{
    QPixmap minorE("minor.png");
       minorE=minorE.scaledToWidth(50);
       minorE=minorE.scaledToHeight(50);
       setPixmap(minorE);
       setPos(50+50*col,50+50*row); // modify the 2 minor's position according to Mahmoud's map

}
void minor::random_movement()
{
    //QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    //QVector<QVector<bool>>* presencePoint=presence;

    while(health>=0)
    {
//
    srand(time(NULL));


    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    { // not gonna use the our defined moveUp etc since major enemies CAN go through walls, redefined new movements

        face=up;
        shoot(*charLoc);
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
        face=down;
        shoot(*charLoc);
    }


    else if(rand()%4==2) // moving left
    {
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
        face=left;
        shoot(*charLoc);
    }

    else if(rand()%4==3) // moving right
    {
        /*
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
                */
        face=right;
        shoot(*charLoc);
    }


    }

}
