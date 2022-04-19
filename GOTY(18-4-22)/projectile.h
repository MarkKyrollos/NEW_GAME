/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "character.h"
class projectile {
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
    QVector<QVector<QVector<character*>>> &charLoc;
    
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

projectile(int dmg, int range, float cool_down, float proj_speed, int Shooter, direct direction, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc);
};

#endif //_PROJECTILE_H

