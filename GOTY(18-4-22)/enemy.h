/**
 * Project Untitled
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "player.h"

class enemy: public character {
public: 
    bool Line_of_sight;
    bool Found_player;
    int player_location[2];//location of player so enemy can track player_location[0]=row player_location[1]=col

enemy(int helth, float mvmt_spd, bool Playa, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool live, bool los, bool playerFound);
int Find_Player(player p1);
    
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

#endif //_ENEMY_H
