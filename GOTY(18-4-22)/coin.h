#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include <QPixmap>
#include <QApplication>
#include<QTimer>
//#include"character.h"

class character;

class coin: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int row;
    int col;
    QGraphicsScene *scene;
    //QGraphicsItem *item;
    coin(int row, int col, QGraphicsScene &scene);

public slots:
void remove();
void addCoin();

};

#endif // COIN_H
