#include "enemy.h"
#include "character.h"
#include "player.h"


/* place this function in a do-while loop inside the main,
 *IMPORTANT: and actually we need to place each of the three rooms in separate do-while in order to proceed sequentially in the program, and to call certain functions repetitively like this one below*/
void enemy::Detection_Shooting(player p, enemy e)
{
    while(abs(e.row-p.row)<=2)
    {
        e.shoot();
    }
}


int enemy::killCount=0;

enemy::~enemy()
{
    incrementKillCount();
}

void enemy::incrementKillCount()
{
    killCount++;
}
