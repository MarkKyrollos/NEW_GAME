#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "player.h"
#include<QTimer>
#include<time.h>
#include<cstdlib>

class enemy: public character
{
Q_OBJECT
public:

    bool is_enemy;
static int killCount;

static void incrementKillCount();

enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major, bool enem = true);

~enemy();

void DoorCheck(QVector<QVector<int>>& map);


//void Detection_Shooting(player p);

public slots:
    void random_movement();
};

#endif //_ENEMY_H
