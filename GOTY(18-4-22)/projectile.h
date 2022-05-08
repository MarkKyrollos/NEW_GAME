/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>
#include <QTimer>
#include <QGraphicsScene>
//
class character;
class projectile: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    float proj_speed; //how often projectile moves
    int Shooter; //who shot the projectile (player or enemy) 1 for player, 2 for enemy
    int col; //col of projectile
    int row; //row of projectile
    int direction; //this is a variable of type enum I'm thinking of making, hmu if you want an explanation
    QVector<QVector<int>>* map;
    QVector<QVector<bool>>* presence;
    QVector<QVector<QVector<character*>>>* charLoc;
    QGraphicsScene* scene;
    QTimer T; //timer for projectile movement

projectile(float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int& col, int& row, QVector<QVector<bool>> &presence, QGraphicsScene &scene, QVector<QVector<QVector<character*>>> &charLoc); //constructor also row and column are passed by reference because we need a way to know where the character that got hit is

void setCharLoc(QVector<QVector<QVector<character*>>> &charLoc);

bool Location_Check(QVector<QVector<bool>> &presence, QVector<QVector<QVector<character*>>> &charLoc); //checks if it hit a wall or character

/**
 * @param &character target
 */

//void Pain (character* target);


public slots:

    void movement(); //projectile movement

/**
 * @param dmg
 * @param range
 * @param cool_down
 * @param proj_speed
 * @param Shooter
 */


};

#endif //_PROJECTILE_H

