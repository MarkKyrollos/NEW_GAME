#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "player.h"
#include<QTimer>

class enemy: public character
{
Q_OBJECT
public:

enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene);

void Detection_Shooting(player p, enemy e);


};

#endif //_ENEMY_H
