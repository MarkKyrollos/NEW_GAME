#include "coin.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include <QPixmap>
#include <QApplication>
#include<QTimer>
#include"character.h"

coin::coin(int row, int col, QGraphicsScene &scene)
{
this->row=row;
this->col=col;
this->scene= &scene;
//item=NULL;

        /*QPixmap coin("coin.png");
        coin=coin.scaledToHeight(50);
        coin=coin.scaledToWidth(50);
        setPixmap(coin);
        setPos(50+50*col,50+50*row);

        scene.addItem(this);*/

        //item= new QGraphicsPixmapItem(coin);

    /*QTimer* t=new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(remove(map)));
    t->start(10000); */  // 10 seconds till the coin disappears if it doesnt receive any interaction from player
}


void coin::addCoin()
{
    QPixmap coin("coin.png");
    coin=coin.scaledToHeight(50);
    coin=coin.scaledToWidth(50);
    setPixmap(coin);
    setPos(50+50*col,50+50*row);
    scene->addItem(this);

    QTimer* t=new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(remove()) );
    t->start(4500); // 10 seconds till the coin disappears if it doesnt receive any interaction from player, changed it to 4.5s temporarily
}


void coin::remove()
{
    //scene->removeItem(item);
    delete this;
}
