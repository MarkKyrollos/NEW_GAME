#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include<QTimer>
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QApplication>
#include <QGraphicsScene>
#include<coin.h>

class character;
class coin;

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
    QGraphicsScene *scene;

    //QVector<QVector<int>> *coinLocation;

projectile(float proj_speed, int Shooter, int direction, QVector<QVector<int>> &map, int& col, int& row, QVector<QVector<bool>> &presence, QGraphicsScene &scene, QVector<QVector<QVector<character*>>> &charLoc); //constructor also row and column are passed by reference because we need a way to know where the character that got hit is

void setCharLoc(QVector<QVector<QVector<character*>>> &charLoc);

bool Location_Check(QVector<QVector<bool>> &presence , QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<int>>&map); //checks if it hit a wall or character
// ^ added the third parameter map in case we were going change the coin location to 10000 on map

public slots:

    void movement(); //projectile movement
};

#endif //_PROJECTILE_H
