#ifndef _CHARACTER_H
#define _CHARACTER_H

#include<QObject>
#include<QKeyEvent>  // for utilizing key presses
#include <QGraphicsPixmapItem> // for using the QPixmap class that would map our character onto the screen
#include <QMainWindow>
#include "projectile.h"


class character : public QObject //, public QGraphicsPixmapItem (include this class in inherited classes like player and enemy since each one would have its own jpeg)
{
    Q_OBJECT
public:
    int health;
    QString name;
    float movement_speed;
    bool is_alive; // if character exists (may die)
    int face;
    int row;
    int col;


    // create an integer 2d array that will store the map text file (which would be converted to int in main) according to different maps in different rooms
    // then later on in derived classes we will decide the starting position of enemy/player using setPixMap using this
    // also make sure tha tthe constructors of derived classes would take an integer 2D array in its parameter (in an initializer list fashion?)


    character(int helth, QString NAME, float mvmt_spd, bool alive, int Facer, int Rowd, int Cold);

    void shoot(); // i set this shooting function to be a pure virtual one since player shots are manually done using spacebar while enemy shots are random


public slots:   // added this, i can push everything onto github once im done instead of modifying each step i make
    virtual void keyPressEvent(QKeyEvent* event);

    // add another function for keyboard movement

};

#endif //_CHARACTER_H