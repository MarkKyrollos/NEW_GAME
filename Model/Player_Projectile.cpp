/**
 * Project Untitled
 */


#include "Player_Projectile.h"

/**
 * Player_Projectile implementation
 */


/**
 * @return static int
 */
static int Player_Projectile::Get_Shot_Count() {
    return Shot_count;
}

/**
 * @param dmg
 * @param range
 * @param cool_down
 * @param proj_speed
 * @param Shooter
 */
Player_Projectile::Player_Projectile(int dmg, int range, float cool_down, float proj_speed, int Shooter):projectile(dmg, range, cool_down, proj_speed, Shooter) {
    Shot_count++;
}

void Player_Projectile::Operation1() {

}