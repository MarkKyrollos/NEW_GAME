/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"
#include<QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class player: public character, QGraphicsPixmapItem {
public: 
    bool Invincible;
    QString Name;
player(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QString NAME, bool Invincible, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live);
    
void In_Enemy(QVector<QVector<QVector<character*>>> &charLoc);

void keyPress(QKeyEvent* event);
    
bool Trigger_Invincibility();
    
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
