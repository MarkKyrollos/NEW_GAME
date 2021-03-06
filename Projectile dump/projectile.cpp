#include "projectile.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>

bool projectile::Location_Check(QVector<QVector<QVector<character*>>> &charLoc) // got it, this func is used to check if projectile reached the exact location for player/enemy to reduce health
{
        if (Shooter == 1)
        {
            if (charLoc[row][col][1] != NULL)
            {
                character* target;
                target = charLoc[row][col][1];
                Pain(target);
                return true;
            }
        }


        if (Shooter == 2)
        {
            if (charLoc[row][col][0] != NULL)
            {
                character* target;
                target = charLoc[row][col][0];
                Pain(target);
                return true;
            }
        }


        if (map->at(row).at(col) < 0) // if projectile hits a wall
        {
            return true;
        }
        return false;
}



void projectile:: Pain(character* target)
{
    //shooter being 1 means player shot it and it checks if it hit an enemy
    target->health -= damage; //a canned damage value

    if (target->health <= 0)
    {
        delete target;
    }
    return;
}


void projectile::movement() //make this a function that moves periodically and is called in the character class
{
    QVector<QVector<QVector<character*>>>* charLocPoint=charLoc;
    switch (direction)
    {
    case up:
        row--;
        Location_Check(*charLocPoint);
        break;

    case down:
        row++;
        Location_Check(*charLocPoint);
        break;

    case right:
        col++;
        Location_Check(*charLocPoint);
        break;

    case left:
        col--;
        Location_Check(*charLocPoint);
        break;
    }
}



projectile::projectile(int dmg, float cool_down, float proj_speed, int Shooter, direct direction, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc) {
    damage = dmg;
    this->cool_down = cool_down;
    this->proj_speed = proj_speed;
    this->Shooter = Shooter;
    this->direction = direction;
    this->map=&map;
    this->charLoc=&charLoc;
    /*QPixmap g("Tweety.png");
       g=g.scaledToWidth(50);
       g=g.scaledToHeight(50);
       setPixmap(g);
       setPos(50+50*col,50+50*row);
       */
}
