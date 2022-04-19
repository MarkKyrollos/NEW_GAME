#include "character.h"

character::character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa)
{
    health=helth;
    /*name=NAME;*/
    movement_speed=mvmt_spd;
    is_alive=alive;
    face=Facer;
    row=Rowd;
    col=Cold;
    this->map =&map;
    this->charLoc= &charLoc;
    Player=Playa;
}


void character::shoot() // automatic shooting
{

}

void character::moveUp(QVector<QVector<QVector<character*>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row-1).at(col)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            row--;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            row--;
            charLoc[row][col][1]=this;
        }
    }
    face=up;
}

void character::moveDown(QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row+1).at(col)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            row++;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            row++;
            charLoc[row][col][1]=this;
        }
    }
    face=down;
}

void character::moveRight(QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row).at(col+1)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            col++;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            col++;
            charLoc[row][col][1]=this;
        }
    }
    face=right;
}

void character::moveLeft(QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row).at(col-1)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            col--;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            col--;
            charLoc[row][col][1]=this;
        }
    }
    face=left;
}
//*** I will do another public slots in derived classes for up down left right buttons, which will relocate the player using its array and pixmap
void character::keyPressEvent(QKeyEvent* event)  // if character manually shoots
{
    if(event->key()==Qt::Key_Space)
    {
        /*projectile proj(25, 50, 0.1, 0.5, 1, face);
        while(!proj.Location_Check(map, charLoc)) // projectile keeps moving until it reaches the location of a character/wall
        {
            proj.movement(); //needs to be done with QTimer
        }
        */
    }
}
