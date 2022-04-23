/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "character.h"
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>

class projectile: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    int damage;
    float cool_down;
    float proj_speed;
    int Shooter;
    int col;
    int row;
    int direction; //this is a variable of type enum I'm thinking of making, hmu if you want an explanation
    QVector<QVector<int>>* map;
    QVector<QVector<bool>>* presence;
    QTimer T;

projectile(int dmg, float cool_down, float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int& col, int& row, QVector<QVector<bool>> &presence);

bool Location_Check(QVector<QVector<bool>> &presence);

/**
 * @param &character target
 */

//void Pain (character* target);


public slots:

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

