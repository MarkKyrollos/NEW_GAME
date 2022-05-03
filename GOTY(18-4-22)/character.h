#ifndef _CHARACTER_H
#define _CHARACTER_H

#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QTimer>
#include "projectile.h"

class projectile;

enum direct {up=1, right, left, down};


class character : public QObject, public QGraphicsPixmapItem //, public QGraphicsPixmapItem (include this class in inherited classes like player and enemy since each one would have its own jpeg)
{
    Q_OBJECT
public:
    int health;
    float movement_speed; //how often an NPC moves
    bool is_alive; // if character exists (may die)
    direct face; //where a character is facing
    int row; //current row
    int col; //current column

    //I explain these 3 in main, I had to move them here like this to get them to work and modify the arrays
    QVector<QVector<int>>* map;
    QVector<QVector<QVector<character*>>>* charLoc;
    QVector<QVector<bool>>* presence;
    //a boolean to determine if the character is a player

    bool Player;
    QGraphicsScene* scene; //ports the scene to make the character move in it freely
    bool major;

    character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major); //constructor
public slots:

    void shoot(); // creates a projectile to shoot
    void moveUp(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence); //makes the character move up
    void moveDown(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence);//down
    void moveRight(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence);//right
    void moveLeft(QVector<QVector<QVector<character*>>> &charLoc, QVector<QVector<bool>> &presence);//and left
};

#endif //_CHARACTER_H
