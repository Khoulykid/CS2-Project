#ifndef BULLET_H
#define BULLET_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>

class bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[11][61];
    int number;
    QTimer *timer;
    QString direction;
    bool stop;
    bool pass;
public:
    bullet(int dataitem[11][61], int, int,int);

public slots:
     void move();
     void dmg();

};

#endif // BULLET_H
