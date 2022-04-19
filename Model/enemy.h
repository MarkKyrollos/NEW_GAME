/**
 * Project Untitled
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "major.h"
#include "character.h"


class enemy: public character {
public:
	
    bool Line_of_sight;
    bool Found_player;
    
bool is_Spotted();
	
int Find_Player();
    
/**
 * @param helth
 * @param mvmt_spd
 * @param Playa
 * @param Loc
 * @param Facer
 * @param Rowd
 * @param Cold
 */
enemy(int helth, float mvmt_spd, bool Playa, int Loc, int Facer, int Rowd, int Cold);
};

#endif //_ENEMY_H
