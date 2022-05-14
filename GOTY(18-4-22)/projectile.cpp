#include "projectile.h"
#include "character.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QGraphicsScene>
#include"coin.h"

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
    this->scene = &scene;

    //sets projectile image
    QPixmap g("projectile.png");
       g=g.scaledToWidth(50);
       g=g.scaledToHeight(50);
       setPixmap(g);
       setPos(50+50*col,50+50*row);

  /*  if(!Location_Check(presence , charLoc))
    {
    scene.addItem(this);
    }*/

    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(movement()));//timer makes projectile move
    T->start(proj_speed*1000);
}

void projectile::setCharLoc(QVector<QVector<QVector<character*>>> &charLoc)
{
    this->charLoc=&charLoc;
}


bool projectile::Location_Check(QVector<QVector<bool>> &presence, QVector<QVector<QVector<character*>>> &charLoc , QVector<QVector<int>> &map)
{
    if (Shooter == 1) //player is shooting
            {

                if (presence[row][col] && map[row][col]!=-3)
                {

                    if (charLoc[row][col][1]!=nullptr)
                    {
                        charLoc[row][col][1]->health -=25;
                        if(charLoc.at(row)[col][1]->health<=0) //kills enemy if health reaches 0
                        {
                            delete charLoc.at(row)[col][1];
                            charLoc[row][col][1]=nullptr;
                            presence[row][col]=false;



                            //character *obj= new character(100, 1.0,true,up,row,col, map,charLoc,true,presence, *scene,false);// had to create a character object in order to store the coin position as charLoc[][][2]
                            //obj->coinSetter(row,col);
                            // ^^old version


                            //charLoc[row][col][0]->coinSetter(row,col); // old method that crashes the program, the logic is right tho
                            coin* c= new coin(row,col,*scene); // calling the coin constructor to place a coin at the same position an enemy dies at
                            c->addCoin();
                        }
                    }

                    return true;
                }
            }


            if (Shooter == 2) // enemy is shooting
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


            if (map[row][col] < 0) // && map->at(row).at(col) != -1) // if projectile hits a wall
            {
                return true;
            }

            return false;
}


void projectile::movement() //make this a function that moves periodically and is called by the QTimer
{
    if(!Location_Check(*presence , *charLoc,*map)) // prevents a shot from visually passing through an enemy
    {
    scene->addItem(this);
    }


    if (direction==1)
    {
        if(Location_Check(*presence ,*charLoc,*map))
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
        if(Location_Check(*presence ,*charLoc,*map))
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
        if(Location_Check(*presence ,*charLoc,*map))
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
        if(Location_Check(*presence ,*charLoc,*map))
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
