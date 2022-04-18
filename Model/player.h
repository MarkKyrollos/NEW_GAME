/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"


class player: public character {
public: 
    bool Invincible;
    String Name;
    
void In_Enemy();
    
void Operation1();
    
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
void player(int helth, float mvmt_spd, bool Playa, int Loc, int Facer, int Rowd, int Cold);
};

#endif //_PLAYER_H