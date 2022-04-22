#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include<QTimer>

//#include "projectile.h" /****** when proj library is included it messed up the whole build *******/

enum direct {up=1, right, left, down};

class character : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    int health;
    float movement_speed;
    bool is_alive; // if character exists (may die)
    direct face;
    int row;
    int col;
    QVector<QVector<int>>* map;
    QVector<QVector<QVector<character*>>>* charLoc;
    bool Player;

    character(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa=true);

    void shoot(); // i set this shooting function to be a pure virtual one since player shots are manually done using spacebar while enemy shots are random


public slots:   // added this, i can push everything onto github once im done instead of modifying each step i make

    //dont think keyPressEvent would work properly as long as we overload it with charLoc
    void keyPressEvent(QKeyEvent* event , QVector<QVector<QVector<character*>>> &charLoc);

  /*  void moveUp(QKeyEvent* event, QVector<QVector<QVector<character*>>> &charLoc);
    void moveDown(QKeyEvent* event, QVector<QVector<QVector<character*>>> &charLoc);
    void moveRight(QKeyEvent* event, QVector<QVector<QVector<character*>>> &charLoc);
    void moveLeft(QKeyEvent* event, QVector<QVector<QVector<character*>>> &charLoc); */

};

#endif //_CHARACTER_H
