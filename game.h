#ifndef GAME_H
#define GAME_H
#include"enemy1.h"
#include"enemy2.h"
#include"player.h"
#include"player_weapon.h"
#include <stdio.h>
#include <QTime>
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "healthbar.h"
#include "bigboss.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include"cannon.h"
#include "coinbar.h"

class game: public QGraphicsView
{
private:
    QGraphicsPixmapItem dataimage[11][61];
    QMediaPlayer *sound;
    QAudioOutput *audio;

public:
    int boarddata[11][61];
    game();
    bool SPAWN[9];
    BigBoss* boss;
    int prv;
    bool lost;
    QGraphicsScene *scene;
    int counter;
    player *p;
    enemy2 *e3;
    enemy2*e4;
    enemy1 *e2;
    enemy1 *e1;
    enemy1 *e5;
    enemy1 *e6;
    enemy2*e7;
    enemy2*e8;
    healthbar* health;
    coinbar* currency;
    cannon *c1;
    cannon *c2;
    cannon *c3;
    cannon *c4;
    bool pause;
    bool bought[5];
    ~game();
public slots:
    void keyPressEvent(QKeyEvent*);
    void gamestart();
    void deleteall();
    void displaystartupmenu();
};

#endif // GAME_H
