#include "projectile.h"
#include "character.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QGraphicsScene>

projectile::projectile(float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int& col, int& row, QVector<QVector<bool>> &presence, QGraphicsScene &scene, QVector<QVector<QVector<character*>>> &charLoc)
{
    //assigns the data
    this->proj_speed = proj_speed;
    this->Shooter = Shooter;
    this->direction = direction;
    this->map=&map;
    this->presence=&presence;
    this->col=col;
    this->row=row;
    this->charLoc= &charLoc;
    this->scene=&scene;

    //sets projectile image
    QPixmap g("projectile.png");
       g=g.scaledToWidth(50);
       g=g.scaledToHeight(50);
       setPixmap(g);
       setPos(50+50*col,50+50*row);

    if(!Location_Check(presence , charLoc))  // prevents a shot from visually passing through an enemy
    {
    scene.addItem(this);
    }

    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(movement()));//timer makes projectile move
    T->start(proj_speed*1000);
}

void projectile::setCharLoc(QVector<QVector<QVector<character*>>> &charLoc)
{
    this->charLoc=&charLoc;
}

bool projectile::Location_Check(QVector<QVector<bool>> &presence, QVector<QVector<QVector<character*>>> &charLoc)
{
    if (Shooter == 1)
            {

                if (presence[row][col])
                {

                    if (charLoc[row][col][1]!=nullptr)
                    {
                        charLoc[row][col][1]->health -=25;
                        if(charLoc.at(row)[col][1]->health<=0) //kills player if health reaches 0
                        {
                            delete charLoc.at(row)[col][1];
                            charLoc[row][col][1]=nullptr;
                            presence[row][col]=false;
                        }
                    }

                    return true;
                }

            }


            if (Shooter == 2)
            {
                if (presence[row][col])
                {

                    if (charLoc[row][col][0]!=nullptr)
                    {
                        charLoc[row][col][0]->health-=10;
                        if(charLoc.at(row)[col][0]->health<=0) //kills player if health reaches 0
                        {
                            delete charLoc.at(row)[col][0];
                            charLoc[row][col][0]=nullptr;
                            presence[row][col]=false;
                        }
                    }

                    return true;
                }
            }


            if (map->at(row).at(col) < 0 && map->at(row).at(col) != -1) // if projectile hits a wall
            {
                return true;
            }

            return false;
}


void projectile::movement() //make this a function that moves periodically and is called in the character class
{
    Location_Check(*presence, *charLoc);

    if (direction==1)
    {
        if(Location_Check(*presence ,*charLoc))
        {
            delete this;
        }
        else
        {

        setPos(50+50*col,50+50*row); //places projectile image in its new location
        row--;
        }
    }

    else if (direction==2)
    {
        if(Location_Check(*presence ,*charLoc))
        {
            delete this;
        }
        else
        {
        setPos(50+50*col,50+50*row); //places projectile image in its new location
        col++;
        }
    }

    else if (direction==3)
    {
        if(Location_Check(*presence ,*charLoc))
        {
            delete this;
        }
        else
        {
        setPos(50+50*col,50+50*row); //places projectile image in its new location
        col--;
        }
    }

    else if (direction==4)
    {
        if(Location_Check(*presence ,*charLoc))
        {
            delete this;
        }
        else
        {
        setPos(50+50*col,50+50*row); //places projectile image in its new location
        row++;
        }
    }

}
