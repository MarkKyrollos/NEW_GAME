#include "character.h"
character::character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major)
{
    //assigning data to attributes
    health=helth;
    /*name=NAME;*/
    movement_speed=mvmt_spd;
    is_alive=alive;
    face=Facer;
    row=Rowd;
    col=Cold;
    Player=Playa;
    this->map =&map;
    this->charLoc= &charLoc;
    this->charLoc->detach();
    this->map->detach();
    //places location in charLoc depending on whether or not its a player
    if (Player)
    {
        charLoc[row][col][0]=this;

    }
    else
    {
        charLoc[row][col][1]=this;
    }
    this->presence=&presence;
    this->scene=&scene;
    presence[row][col]=true;
    this->maj=major;

}


void character::shoot(QVector<QVector<QVector<character*>>> &charLoc , QVector<QVector<bool>> &presence) // automatic shooting
{
    if (Player) //checks who is shooting
    {
        //character* nullifier = NULL; //You'll see this a lot because NULL on its own is read as type int
        projectile* proj; //projectile pointer
        //int dmg=25; //damage
        float proj_speed=0.25; //projectile speed
        int shooter=1; //determines if shooter is player or enemy, 1 is player, 2 is enemy
        int direct=4; //determines direction, 1 is up, 2 is right, 3 is left, 4 is down
        int coltar=col; //column of projectile
        int rowtar=row; //row of projectile
        if (face==up) //shoot up
        {
            direct=1;
            if (map->at(row-1)[col]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,coltar,--rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        else if (face==right) //shoot right
        {
            direct=2;
            if (map->at(row)[col+1]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,++coltar,rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }//
        else if (face==left) //shoot left
        {
            direct=3;
            if (map->at(row)[col-1]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,--coltar,rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        else if(face==down) //shoot down
        {
            direct=4;
            if (map->at(row+1)[col]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,coltar,++rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        /*
        if (charLoc.at(rowtar)[coltar][1]!= nullifier) //checks if enemy is hit and deals damage
        {
            charLoc.at(rowtar)[coltar][1]->health-=dmg; //deducts health
            if(charLoc.at(rowtar)[coltar][1]->health<=0) //kills enemy;
            {
                delete charLoc.at(rowtar)[coltar][1];
                charLoc[rowtar][coltar][1]=nullptr;
                presence[rowtar][coltar]=false;
            }
            delete proj; //deletes projectile on enemy contact
        }
        */



    }
    else
    {
        //character* nullifier = NULL;
        projectile* proj;
        //int dmg=10; //less damage than player
        float proj_speed=0.5;
        int shooter=2;
        int direct=4;
        int coltar=col;
        int rowtar=row;
        if (face==up)
        {
            direct=1;
            if (map->at(row-1)[col]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,coltar,--rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        else if (face==right)
        {
            direct=2;
            if (map->at(row)[col+1]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,++coltar,rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        else if (face==left)
        {
            direct=3;
            if (map->at(row)[col-1]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,--coltar,rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        else if(face==down)
        {
            direct=4;
            if (map->at(row+1)[col]>=0)
            {
                proj=new projectile(proj_speed,shooter,direct,*map,coltar,++rowtar,presence, *scene, charLoc); //it wouldn't construct unless we did the terribleness above
                //proj->setCharLoc(charLoc);
                //scene->addItem(proj);
            }

        }
        /*
        if (charLoc.at(rowtar)[coltar][0]!= nullifier)
        {
            charLoc.at(rowtar)[coltar][0]->health-=dmg;
            if(charLoc.at(rowtar)[coltar][0]->health<=0) //kills player if health reaches 0
            {
                delete charLoc.at(rowtar)[coltar][0];
                charLoc[rowtar][coltar][0]=nullptr;
                presence[rowtar][coltar]=false;
            }
        }
        */
    }
}

void character::moveUp(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence) //move up
{
    character* nullifier=NULL;

    if (map->at(row-1).at(col)>=0||map->at(row-1).at(col)==-1||map->at(row-1).at(col)==-3) //checks if player is moving in lava or regular walkways
    {
        if (Player)
        {
            if(map->at(row-1).at(col)==-1||map->at(row-1).at(col)>=0)
            {
                charLoc[row][col][0] = nullifier; //makes previous location null
                if (charLoc[row][col][1]==nullifier) //checks if enemy is in that location
                {
                    presence[row][col]=false; //removes presence if no enemy is present
                }
                row--; //changes row/column
                charLoc[row][col][0]=this; //moves player to new location
                if (map->at(row).at(col)==-1) //kills player if they step in lava
                {
                    health=0;
                }
            }

        }
        else if (charLoc[row-1][col][1] == nullifier && map->at(row-1).at(col)!=1000) //enemy movement
        {
            if ((map->at(row-1).at(col)==-3 && maj) || map->at(row-1).at(col)>=0)
            {
                charLoc[row][col][1] = nullifier;
                if (charLoc[row][col][0]==nullifier)
                {
                    presence[row][col]=false;
                }
                row--;
                charLoc[row][col][1]=this;
            }

        }
        presence[row][col]=true;
    }

    face=up; //changes direction character is facing
//just a secondary check to kill off a character in case they survive a lethal attack
    if (health<=0)
    {
        if (Player)
        {
            charLoc[row][col][0]=nullptr;
            if (charLoc[row][col][1]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        else
        {
            charLoc[row][col][1]=nullptr;
            if (charLoc[row][col][0]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        delete this;
    }
}



void character::moveDown(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence) //move down
{
    character* nullifier=NULL;

    if (map->at(row+1).at(col)>=0||map->at(row+1).at(col)==-1||map->at(row+1).at(col)==-3) //checks if player is moving in lava or regular walkways
    {
        if (Player)
        {
            if(map->at(row+1).at(col)==-1||map->at(row+1).at(col)>=0)
            {
                charLoc[row][col][0] = nullifier; //makes previous location null
                if (charLoc[row][col][1]==nullifier) //checks if enemy is in that location
                {
                    presence[row][col]=false; //removes presence if no enemy is present
                }
                row++; //changes row/column
                charLoc[row][col][0]=this; //moves player to new location
                if (map->at(row).at(col)==-1) //kills player if they step in lava
                {
                    health=0;
                }
            }

        }
        else if (charLoc[row+1][col][1] == nullifier && map->at(row+1).at(col)!=1000) //enemy movement
        {
            if ((map->at(row+1).at(col)==-3 && maj) || map->at(row+1).at(col)>=0)
            {
                charLoc[row][col][1] = nullifier;
                if (charLoc[row][col][0]==nullifier)
                {
                    presence[row][col]=false;
                }
                row++;
                charLoc[row][col][1]=this;
            }

        }
        presence[row][col]=true;
    }
    face=down;
    if (health<=0)
    {
        if (Player)
        {
            charLoc[row][col][0]=nullptr;
            if (charLoc[row][col][1]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        else
        {
            charLoc[row][col][1]=nullptr;
            if (charLoc[row][col][0]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        delete this;
    }
}

void character::moveRight(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence) //move right
{
    character* nullifier=NULL;
    if (map->at(row).at(col+1)>=0||map->at(row).at(col+1)==-1||map->at(row).at(col+1)==-3) //checks if player is moving in lava or regular walkways
    {
        if (Player)
        {
            if(map->at(row).at(col+1)==-1||map->at(row).at(col+1)>=0)
            {
                charLoc[row][col][0] = nullifier; //makes previous location null
                if (charLoc[row][col][1]==nullifier) //checks if enemy is in that location
                {
                    presence[row][col]=false; //removes presence if no enemy is present
                }
                col++; //changes row/column
                charLoc[row][col][0]=this; //moves player to new location
                if (map->at(row).at(col)==-1) //kills player if they step in lava
                {
                    health=0;
                }
            }

        }
        else if (charLoc[row][col+1][1] == nullifier && map->at(row).at(col+1)!=1000) //enemy movement
        {
            if ((map->at(row).at(col+1)==-3 && maj) || map->at(row).at(col+1)>=0)
            {
                charLoc[row][col][1] = nullifier;
                if (charLoc[row][col][0]==nullifier)
                {
                    presence[row][col]=false;
                }
                col++;
                charLoc[row][col][1]=this;
            }

        }
        presence[row][col]=true;
    }
    face=right;
    if (health<=0)
    {
        if (Player)
        {
            charLoc[row][col][0]=nullptr;
            if (charLoc[row][col][1]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        else
        {
            charLoc[row][col][1]=nullptr;
            if (charLoc[row][col][0]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        delete this;
    }

}

void character::moveLeft(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence) // move left
{
    character* nullifier=NULL;
    if (map->at(row).at(col-1)>=0||map->at(row).at(col-1)==-1||map->at(row).at(col-1)==-3) //checks if player is moving in lava or regular walkways
    {
        if (Player)
        {
            if(map->at(row).at(col-1)==-1||map->at(row).at(col-1)>=0)
            {
                charLoc[row][col][0] = nullifier; //makes previous location null
                if (charLoc[row][col][1]==nullifier) //checks if enemy is in that location
                {
                    presence[row][col]=false; //removes presence if no enemy is present
                }
                col--; //changes row/column
                charLoc[row][col][0]=this; //moves player to new location
                if (map->at(row).at(col)==-1) //kills player if they step in lava
                {
                    health=0;
                }
            }

        }
        else if (charLoc[row][col-1][1] == nullifier && map->at(row).at(col-1)!=1000) //enemy movement
        {
            if ((map->at(row).at(col-1)==-3 && maj) || map->at(row).at(col-1)>=0)
            {
                charLoc[row][col][1] = nullifier;
                if (charLoc[row][col][0]==nullifier)
                {
                    presence[row][col]=false;
                }
                col--;
                charLoc[row][col][1]=this;
            }

        }
        presence[row][col]=true;
    }
    face=left;
    if (health<=0)
    {
        if (Player)
        {
            charLoc[row][col][0]=nullptr;
            if (charLoc[row][col][1]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        else
        {
            charLoc[row][col][1]=nullptr;
            if (charLoc[row][col][0]==nullptr)
            {
                presence[row][col]=false;
            }
        }
        delete this;
    }
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
