#include "character.h"

character::character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa)
{
    health=helth;
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
// call the same projectile functions as called in the keyPressEvent function
}


void character::keyPressEvent(QKeyEvent* event , QVector<QVector<QVector<character*>>> &charLoc)  // if character manually shoots
{

    // manual shooting
    if(event->key()==Qt::Key_Space)
    {
        projectile proj(25, 50, 0.1, 0.5, 1, face); // I hid the projectile.h as a comment since Qt doesnt recognize it and throws over 130 errors casually
        QTimer T;
while(!proj.Location_Check(charLoc[row][col][0]))
{
    T.singleShot(500, this , SLOT(proj.movement())); // i set the projectile to move at a speed each .5 seconds, void singleShot(int msec, const projectile *receiver, const char *member)
}

    }


    character* nullifier=NULL;

    // moving UP
    if (map->at(row-1).at(col)>=0 &&  event->key()==Qt::Key_Up)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            row--;
            charLoc[row][col][0] = this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            row--;
            charLoc[row][col][1]=this;
        }

    face=up;
    setPos(50+50*col,50+50*row);
    }

    // moving DOWN
    if (map->at(row+1).at(col)>=0 && event->key()==Qt::Key_Down)
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
    face=down;
    setPos(50+50*col,50+50*row);
    }


    // moving RIGHT
    if (map->at(row).at(col+1)>=0 && event->key()==Qt::Key_Right)
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

        face =right;
        setPos(50+50*col,50+50*row);
    }


    //moving LEFT
    if (map->at(row).at(col-1)>=0 && event->key()==Qt::Key_Left)
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
        face=left;
    setPos(50+50*col,50+50*row);
    }

}



/*
void character::moveUp(QKeyEvent* event, QVector<QVector<QVector<character*>>> &charLoc)
{
    character* nullifier=NULL;

    if (map->at(row-1).at(col)>=0 &&  event->key()==Qt::Key_Up)
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
    setPos(50+50*col,50+50*row);
    face=up;
}



void character::moveDown(QKeyEvent* event, QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row+1).at(col)>=0 && event->key()==Qt::Key_Down)
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
   setPos(50+50*col,50+50*row);
    face=down;
}


void character::moveRight(QKeyEvent* event, QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row).at(col+1)>=0 && event->key()==Qt::Key_Right)
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
    setPos(50+50*col,50+50*row);
    face=right;
}

void character::moveLeft(QKeyEvent* event, QVector<QVector<QVector<character *>>> &charLoc)
{
    character* nullifier=NULL;
    if (map->at(row).at(col-1)>=0 && event->key()==Qt::Key_Left)
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
    setPos(50+50*col,50+50*row);
    face=left;
}

*/
