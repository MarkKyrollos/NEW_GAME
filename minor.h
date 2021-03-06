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
    
minor(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene) : enemy(helth,mvmt_spd,alive,Facer,Rowd,Cold,map,charLoc,Playa,presence,scene)
{   QPixmap minorE("minor.png");
    minorE=minorE.scaledToWidth(50);
    minorE=minorE.scaledToHeight(50);
    setPixmap(minorE);
    setPos(50+50*col,50+50*row); // modify the 2 minor's position according to Mahmoud's map
}

// minor enemies only inherit the Detection_Shooting function from enemy

};

#endif //_MINOR_H
