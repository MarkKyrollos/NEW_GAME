#include "major.h"


major::major(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene):enemy(helth,mvmt_spd,alive,Facer,Rowd,Cold,map,charLoc,Playa,presence,scene)
{
    QPixmap majorE("major.png");
       majorE=majorE.scaledToWidth(50);
       majorE=majorE.scaledToHeight(50);
       setPixmap(majorE);
       setPos(50+50*col,50+50*row); // modify 2 major enemies' placement on the map
       QTimer* T=new QTimer(this);
       connect(T,SIGNAL(timeout()),this,SLOT(random_movement()));
       T->start(mvmt_spd*1000);
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
       *///
}


// this random movement function should be called repetitively (Magd Note: We have the movement as a character function, use it)
void major::random_movement()
{
    //QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    //QVector<QVector<bool>>* presencePoint=presence;

    while(health>=0)
    {

    srand(time(NULL));


    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    { // not gonna use the our defined moveUp etc since major enemies CAN go through walls, redefined new movements

        moveUp(*charLoc,*presence);
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
        moveDown(*charLoc,*presence);
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
        moveLeft(*charLoc,*presence);
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
        moveRight(*charLoc,*presence);
    }

setPos(50+50*col,50+50*row);

    }

}
