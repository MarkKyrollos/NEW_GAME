#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMediaPlayer>
#include <QTimer>
#include<QGraphicsScene>
#include <QMainWindow>
#include "ui_main_menu.h"
#include <QtMultimedia>
#include "character.h"
#include "player.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QGraphicsScene* scene = nullptr,player *P1=nullptr);
    ~MainWindow();
    void play_sound(bool music);
    void openmenu();
    QGraphicsScene* scene;
    player* PlayerPoint;

public slots:
    void update_health();

private:
    Ui::MainWindow *ui;
    bool background_music= true;
    QTimer *music_loop;
};
#endif // MAINWINDOW_H
