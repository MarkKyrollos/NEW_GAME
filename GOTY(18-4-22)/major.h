#ifndef _MAJOR_H
#define _MAJOR_H

#include "enemy.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>
#include <time.h>
#include<cstdlib>

//

class major: public enemy
{
public: 

major(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major);

// major enemies also use Detection_Shooting function

};

#endif //_MAJOR_H
