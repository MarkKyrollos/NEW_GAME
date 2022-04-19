#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMediaPlayer>
#include <QTimer>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void play_sound(bool music);
    void timefunction(QMediaPlayer* music);
public slots:


private:
    Ui::MainWindow *ui;
    bool background_music= true;
    QTimer *music_loop;
};
#endif // MAINWINDOW_H
