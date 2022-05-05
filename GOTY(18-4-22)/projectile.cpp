#include "projectile.h"
#include "character.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>

projectile::projectile(float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int& col, int& row, QVector<QVector<bool>> &presence, QGraphicsScene &scene, QVector<QVector<QVector<character*>>> &charLoc) {
    //assigns the data
    this->proj_speed = proj_speed;
    this->Shooter = Shooter;
    this->direction = direction;
    this->map=&map;
    this->presence=&presence;
    this->col=col;
    this->row=row;
    this->charLoc=&charLoc;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(movement()));//timer makes projectile move
    T->start(proj_speed*1000);
    //sets projectile image
    QPixmap g("projectile.png");
       g=g.scaledToWidth(50);
       g=g.scaledToHeight(50);
       setPixmap(g);
       setPos(50+50*col,50+50*row);//
    scene.addItem(this);
}

void projectile::setCharLoc(QVector<QVector<QVector<character*>>> &charLoc)
{
    this->charLoc=&charLoc;
}

bool projectile::Location_Check(QVector<QVector<bool>> &presence, QVector<QVector<QVector<character*>>> &charLoc) // got it, this func is used to check if projectile reached the exact location for player/enemy to reduce health
{
    if (Shooter == 1)
        {

            if (presence[row][col])
            {

                if (charLoc[row][col][1]!=nullptr)
                {
                    charLoc[row][col][1]->health-=25;
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



/*void projectile:: Pain(character* target)
{
    //shooter being 1 means player shot it and it checks if it hit an enemy
    target->health -= damage; //a canned damage value

    if (target->health <= 0)
    {
        delete target;
    }
    return;
}
*/

void projectile::movement() //make this a function that moves periodically and is called in the character class
{
    if (direction==1)
    {
        row--;
        Location_Check(*presence ,*charLoc);
    }
    else if (direction==2)
    {
        col++;
        Location_Check(*presence ,*charLoc);
    }
    else if (direction==3)
    {
        col--;
        Location_Check(*presence ,*charLoc);
    }
    else if (direction==4)
    {
        row++;
        Location_Check(*presence ,*charLoc);

    }
    if (Location_Check(*presence ,*charLoc))
    {
        delete this;
    }
    setPos(50+50*col,50+50*row); //places projectile image in its new location
}




