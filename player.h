#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <string>
#include"player_weapon.h"
#include <QDebug>


class player :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool gender;
    int row;
    QTimer* timer;
    int column;
    int data[11][61];
    bool space;
    int weaponrow;
    int weaponcol;
    QString direction;
    bool collide;
public:
    player(int [11][61], bool );
    int getRow();
    int getCol();
    QString getDirection();
    void setDir(QString);
public slots:
    void move(QKeyEvent*);
};
#endif // PLAYER_H
