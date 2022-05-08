/**
 * Project Untitled
 */


#include "boss.h"
#include "major.h"
/**
 * boss implementation
 */

boss::boss(int helth, float mvmt_spd, bool alive, direct Facer, int Rowd, int Cold, QVector<QVector<int>> &map, QVector<QVector<QVector<character*>>> &charLoc, bool Playa, QVector<QVector<bool>> &presence, QGraphicsScene &scene, bool major,player* P1):enemy(helth, mvmt_spd, alive, Facer, Rowd, Cold, map, charLoc, Playa, presence, scene, major)
{
    this->P1=P1;
    QPixmap boss("player.png"); //sets the image
       boss=boss.scaledToWidth(50);
       boss=boss.scaledToHeight(50);
       setPixmap(boss);
       setPos(50+50*col,50+50*row);
       QTimer* T=new QTimer(this);
       connect(T,SIGNAL(timeout()),this,SLOT(spawnEnemies(charLoc)));
       T->start(5000);
}

boss::~boss()
{
    //QMediaPlayer* victory_screen=new QMediaPlayer();
    //victory_screen->setMedia(QUrl("qrc:/new/prefix1/magnum.mp3"));
    //Mahmoud, hlp pls, I don't know how to deal with multimedia, the file is called VictoryScreen.mp4
}

void boss::spawnEnemies(QVector<QVector<QVector<character*>>> &charLoc)
{
    // generating random numbers from 0-3, 0 1 2 3 correspond to up down left right respectively
    if(rand()%4==0) // moving UPWARDS
    {
        if (charLoc[row-1][col][1]==nullptr && map->at(row-1).at(col)>0)
        {
            if (rand()%2==0) //spawn minor enemy
            {
                minor* Enenmi=new minor(100,1,true,down,row-1,col,*map,charLoc,false,*presence,*scene, false);
            }
            else //spawn major enemy
            {
                major* Enenmi=new major(100,1,true,down,row-1,col,*map,charLoc,false,*presence,*scene, false);
            }
        }

    }


     else if(rand()%4==1) //moving downwards
     {
        if (charLoc[row+1][col][1]==nullptr && map->at(row+1).at(col)>0)
        {
            if (rand()%2==0) //spawn minor enemy
            {
                minor* Enenmi=new minor(100,1,true,down,row+1,col,*map,charLoc,false,*presence,*scene, false);
            }
            else //spawn major enemy
            {
                major* Enenmi=new major(100,1,true,down,row+1,col,*map,charLoc,false,*presence,*scene, false);
            }
        }
     }


     else if(rand()%4==2) // moving left
     {
        if (charLoc[row][col-1][1]==nullptr && map->at(row).at(col-1)>0)
        {
            if (rand()%2==0) //spawn minor enemy
            {
                minor* Enenmi=new minor(100,1,true,down,row,col-1,*map,charLoc,false,*presence,*scene, false);
            }
            else //spawn major enemy
            {
                major* Enenmi=new major(100,1,true,down,row,col-1,*map,charLoc,false,*presence,*scene, false);
            }
        }

     }

     else if(rand()%4==3) // moving right
     {
        if (charLoc[row][col+1][1]==nullptr && map->at(row).at(col+1)>0)
        {
            if (rand()%2==0) //spawn minor enemy
            {
                minor* Enenmi=new minor(100,1,true,down,row,col+1,*map,charLoc,false,*presence,*scene, false);
            }
            else //spawn major enemy
            {
                major* Enenmi=new major(100,0.5,true,down,row,col+1,*map,charLoc,false,*presence,*scene, true);
            }
        }

     }
}
