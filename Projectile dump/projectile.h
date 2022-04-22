/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "character.h"
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
class projectile: public QObject {
public: 
    int damage;
    float cool_down;
    float proj_speed;
    int Shooter;
    int col;
    int row;
    direct direction; //this is a variable of type enum I'm thinking of making, hmu if you want an explanation
    QVector<QVector<int>>* map;
    QVector<QVector<QVector<character*>>> *charLoc;
    
projectile(int dmg, float cool_down, float proj_speed, int Shooter, direct direction, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc);

bool Location_Check(QVector<QVector<QVector<character*>>> &charLoc);
    
/**
 * @param &character target
 */

void Pain (character* target);

void movement();
    
/**
 * @param dmg
 * @param range
 * @param cool_down
 * @param proj_speed
 * @param Shooter
 */


};

#endif //_PROJECTILE_H

