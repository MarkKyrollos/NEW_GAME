/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>

class player: public character{
public: 
    bool Invincible;
    QString Name;
    QPixmap pac;
player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, bool Invincible, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, QVector<QVector<bool>> &presence, QGraphicsScene &scene);
    
void In_Enemy(QVector<QVector<QVector<character*>>> &charLoc);

~player();

    
bool Trigger_Invincibility();
public slots:
    void keyPressEvent(QKeyEvent* event);
/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */


};
#endif //_PLAYER_H
