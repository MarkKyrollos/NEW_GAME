#include "character.h"
character::character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene)
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
    this->presence=&presence;
    this->scene=&scene;
    Player=Playa;
}


void character::shoot() // automatic shooting
{
    if (Player)
    {
        projectile* proj;
        int dmg=25;
        float cool_down=0.5;
        float proj_speed=0.5;
        int shooter=1;
        int direct=4;
        if (face==up)
        {
            direct=1;
            if (map->at(row-1)[col]>=0)
            {
                proj=new projectile(dmg,cool_down,proj_speed,shooter,direct,*map,col,row-1,*presence);
                scene->addItem(proj);
            }

        }
        else if (face==right)
        {
            direct=2;
            if (map->at(row)[col+1]>=0)
            {
                proj=new projectile(dmg,cool_down,proj_speed,shooter,direct,*map,col+1,row,*presence);
                scene->addItem(proj);
            }

        }
        else if (face==left)
        {
            direct=3;
            if (map->at(row)[col-1]>=0)
            {
                proj=new projectile(dmg,cool_down,proj_speed,shooter,direct,*map,col-1,row,*presence);
                scene->addItem(proj);
            }

        }
        else if(face==down)
        {
            direct=4;
            if (map->at(row+1)[col]>=0)
            {
                proj=new projectile(dmg,cool_down,proj_speed,shooter,direct,*map,col,row+1,*presence);
                scene->addItem(proj);
            }

        }



        /*
        QTimer T;

        while(!proj->Location_Check(*presence))
        {
            T.singleShot(500, this , SLOT(proj.movement())); // i set the projectile to move at a speed each .5 seconds, void singleShot(int msec, const projectile *receiver, const char *member)
        }
        */
        /*
        if (proj->Location_Check(*presence))
        {
            delete proj;
        }
        */

    }
    else
    {
        projectile* proj;
        int dmg=10;
        float cool_down=0.5;
        float proj_speed=0.5;
        int shooter=2;
        int direct=face;
        proj=new projectile(dmg,cool_down,proj_speed,shooter,direct,*map,col,row,*presence);
        QTimer T;
        while(!proj->Location_Check(*presence))
        {
            T.singleShot(500, this , SLOT(proj.movement())); // i set the projectile to move at a speed each .5 seconds, void singleShot(int msec, const projectile *receiver, const char *member)
        }

        delete proj;
    }
}

void character::moveUp(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence)
{
    character* nullifier=NULL;

    if (map->at(row-1).at(col)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            if (charLoc[row][col][1]==nullifier)
            {
                presence[row][col]=false;
            }
            row--;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            if (charLoc[row][col][0]==nullifier)
            {
                presence[row][col]=false;
            }
            row--;
            charLoc[row][col][1]=this;
        }
        presence[row][col]=true;
    }
    face=up;
}



void character::moveDown(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence)
{
    character* nullifier=NULL;
    if (map->at(row+1).at(col)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            if (charLoc[row][col][1]==nullifier)
            {
                presence[row][col]=false;
            }
            row++;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            if (charLoc[row][col][0]==nullifier)
            {
                presence[row][col]=false;
            }
            row++;
            charLoc[row][col][1]=this;
        }
        presence[row][col]=true;

    }
    face=down;
}

void character::moveRight(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence)
{
    character* nullifier=NULL;
    if (map->at(row).at(col+1)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            if (charLoc[row][col][1]==nullifier)
            {
                presence[row][col]=false;
            }
            col++;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            if (charLoc[row][col][0]==nullifier)
            {
                presence[row][col]=false;
            }
            col++;
            charLoc[row][col][1]=this;
        }
        presence[row][col]=true;
    }
    face=right;
}

void character::moveLeft(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence)
{
    character* nullifier=NULL;
    if (map->at(row).at(col-1)>=0)
    {
        if (Player)
        {
            charLoc[row][col][0] = nullifier;
            if (charLoc[row][col][1]==nullifier)
            {
                presence[row][col]=false;
            }
            col--;
            charLoc[row][col][0]=this;
        }
        else
        {
            charLoc[row][col][1] = nullifier;
            if (charLoc[row][col][0]==nullifier)
            {
                presence[row][col]=false;
            }
            col--;
            charLoc[row][col][1]=this;
        }
        presence[row][col]=true;
    }
    face=left;
}



//*** I will do another public slots in derived classes for up down left right buttons, which will relocate the player using its array and pixmap
//void character::keyPressEvent(QKeyEvent* event)  // if character manually shoots
//{
    //if(event->key()==Qt::Key_Space)
    //{
        /*projectile proj(25, 50, 0.1, 0.5, 1, face);
        while(!proj.Location_Check(map, charLoc)) // projectile keeps moving until it reaches the location of a character/wall
        {
            proj.movement(); //needs to be done with QTimer
        }
        */
    //}
//}
