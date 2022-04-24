#include "enemy.h"
#include "character.h"
#include "player.h"


/* place this function in a do-while loop inside the main,
 *IMPORTANT: and actually we need to place each of the three rooms in separate do-while in order to proceed sequentially in the program, and to call certain functions repetitively like this one below*/
void enemy::Detection_Shooting(player p, enemy e)
{
    while(abs(e.row-p.row)<=2)
    {
        p.shoot();
    }
}




enemy::enemy(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene)
{
    health=helth;
    movement_speed=mvmt_spd;
    is_alive=alive;
    face=Facer;
    row=Rowd;
    col=Cold;
    this->map =&map;
    this->charLoc= &charLoc;
    this->presence=&presence;
    this->scene()=&scene;
    Player=Playa;
}
