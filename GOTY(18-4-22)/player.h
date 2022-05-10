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
#include<QMediaPlayer>
//
class player: public character{
public: 
    QString Name;
    QPixmap pac;
    QMediaPlayer * shots_fired;
player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major); //constructor
    
void In_Enemy(QVector<QVector<QVector<character*>>> &charLoc);//checks if player is in an enemy to deal damage

~player();



public slots:
    void keyPressEvent(QKeyEvent* event); //handles key presses
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
