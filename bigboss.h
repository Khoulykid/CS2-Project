#ifndef BIGBOSS_H
#define BIGBOSS_H
#include <QVector>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QVector>
#include "enemy2.h"
#include <time.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int parentRow;
    int parentCol;
    float gCost; // cost of moving from the starting node to this node
    float hCost; // estimated cost of moving from this node to the final node
    float fCost; // gCost + hCost
    Node() {}
    Node(int _row, int _col, int _parentRow, int _parentCol, float _gCost, float _hCost)
    {
        row = _row;
        col = _col;
        parentRow = _parentRow;
        parentCol = _parentCol;
        gCost = _gCost;
        hCost = _hCost;
        fCost = gCost + hCost;
    }
    bool operator==(const Node& rhs)
    {
        if (row == rhs.row && col == rhs.col)
            return true;
        return false;
    }
};
class BigBoss: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[11][61];
    //int adjm[11][61];
    float totalcost;
    QString direction;
    QPixmap* boss;
    QPixmap* bossleft;

public:
    BigBoss(int[11][61], int, int);
    int getrow();
    int health;
    int getcolumn();
    QVector<Node> path;
    void updateAllNodes(Node[11][61], int, int, int, int, float, float);
    void sort(QVector<Node> nodes);
    float getDistance(int x1, int y1, int x2, int y2);
    QTimer *timer, *weapontimer, *gethardertimer, *enemyspawntimer, *healthregentimer;
    ~BigBoss();
public slots:
    void move();
    void shoot();
    void findpath(int, int, int, int);
    void dmg();
    void enemyspawn();
    void HARDER();
    void HEAL();
};

#endif // BIGBOSS_H
