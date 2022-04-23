#include "projectile.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>

projectile::projectile(int dmg, float cool_down, float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int col, int row, QVector<QVector<bool>> &presence) {
    damage = dmg;
    this->cool_down = cool_down;
    this->proj_speed = proj_speed;
    this->Shooter = Shooter;
    this->direction = direction;
    this->map=&map;
    this->presence=&presence;
    this->col=col;
    this->row=row;
    QTimer* T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(movement()));
    T->start(250);
    //T->singleShot(1000, this , SLOT(movement()));
    QPixmap g("projectile.png");
       g=g.scaledToWidth(50);
       g=g.scaledToHeight(50);
       setPixmap(g);
       setPos(50+50*col,50+50*row);
}

bool projectile::Location_Check(QVector<QVector<bool>> &presence) // got it, this func is used to check if projectile reached the exact location for player/enemy to reduce health
{
    if (Shooter == 1)
        {
            if (presence[row][col])
            {
                return true;
            }
        }


        if (Shooter == 2)
        {
            if (presence[row][col])
            {
                return true;
            }
        }


        if (map->at(row).at(col) < 0) // if projectile hits a wall
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
void projectile::timedMovement()
{
      T.start(1000); // i set the projectile to move at a speed each .5 seconds, void singleShot(int msec, const projectile *receiver, const char *member)
}

void projectile::movement() //make this a function that moves periodically and is called in the character class
{
    QVector<QVector<bool>>* presencePoint=presence;
    if (direction==1)
    {
        row--;
        Location_Check(*presencePoint);
        setPos(50+50*col,50+50*row);
    }
    else if (direction==2)
    {
        col++;
        Location_Check(*presencePoint);
        setPos(50+50*col,50+50*row);
    }
    else if (direction==3)
    {
        col--;
        Location_Check(*presencePoint);
        setPos(50+50*col,50+50*row);
    }
    else if (direction==4)
    {
        row++;
        Location_Check(*presencePoint);
        setPos(50+50*col,50+50*row);
    }
    if (Location_Check(*presence))
    {
        delete this;
    }
}




