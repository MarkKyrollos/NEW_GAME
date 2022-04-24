#ifndef _MINOR_H
#define _MINOR_H

#include "enemy.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>

class minor: public enemy
{

public: 
    
minor(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene);

// minor enemies only inherit the Detection_Shooting function from enemy

};

#endif //_MINOR_H
