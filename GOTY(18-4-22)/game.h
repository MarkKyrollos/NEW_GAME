#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView> //sets window title and set fixed width
#include <QGraphicsScene>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"
#include "character.h"
#include "projectile.h"
#include "enemy.h"
#include "major.h"
#include "minor.h"
#include "boss.h"
#include <QVector>
#include "doortimer.h"
class game
{
public:
    game();
};

#endif // GAME_H
