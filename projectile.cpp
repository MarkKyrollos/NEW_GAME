#include "projectile.h"


bool projectile::Location_Check() // got it, this func is used to check if projectile reached the exact location for player/enemy to reduce health
{
        if (Shooter == 1)
        {
            if (charLoc[row][col][1] != NULL)
            {
                character* target;
                target = characterLoc[row][col][1];
                Pain(target);
                return true;
            }
        }


        if (Shooter == 2)
        {
            const int r=1,c=2,z=4;

            character charLoc[r][c][z];
            charLoc[1][1][1].health=100;

            if (charLoc[1][1][1].health==100)
            {
                character* target;
               // characterLoc[row]
                target = &charLoc[r][c][z];
                Pain(target);
                return true;
            }
        }


        if (map[row][col] < 0) // if projectile hits a wall
        {
            return true;
        }
        return;
    }
}



void projectile:: Pain(character& target)
{
    //shooter being 1 means player shot it and it checks if it hit an enemy
    target->health -= damage; //a canned damage value

    if (target->health <= 0)
    {
        delete target;
    }
    return;
}


void projectile::movement() //make this a function that moves periodically and is called in the character class
{
    switch (direction)
    {
    case up:
        row--;
        Location_Check();
        break;

    case down:
        row++;
        Location_Check;
        break;

    case right:
        col++;
        Location_Check();
        break;

    case left:
        col--;
        Location_Check();
        break;
    }
}



projectile::projectile(int dmg, int range, float cool_down, float proj_speed, int Shooter, direct direction) {
    damage = dmg;
    this->range = range;
    this->cool_down = cool_down;
    this->proj_speed = proj_speed;
    this->Shooter = Shooter;
    this->direction = direction;
}
