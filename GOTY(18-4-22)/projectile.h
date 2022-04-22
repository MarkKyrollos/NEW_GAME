#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "character.h"
#include <QGraphicsPixmapItem>


class projectile :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int damage;
    int range;
    float cool_down;
    float proj_speed;
    int Shooter;
    int col;
    int row;
    direct direction; //this is a variable of type enum I'm thinking of making, hmu if you want an explanation
    QVector<QVector<int>>* map;
    QVector<QVector<QVector<character*>>> *charLoc;

bool Location_Check(QVector<QVector<QVector<character*>>> &charLoc);

void Pain (character* target);

void movement();

projectile(int dmg, int range, float cool_down, float proj_speed, int Shooter, direct direction, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc);

};

#endif //_PROJECTILE_H
