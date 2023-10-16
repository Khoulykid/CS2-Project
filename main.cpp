#include <QGraphicsView>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "enemy1.h"
#include"player_weapon.h"
#include"enemy2.h"
#include"game.h"
#include "form.h"
#include "mainwindow.h"
#include "win.h"
#include <QVector>
#include "coinobject.h"
#include "player_weapon.h"
#include "store.h"

MainWindow *w;
game *g;
Form* f;
Win *win;
store* s;
QVector<enemy1*> botatos;   //Courtesy of khouly (please don't fail us :D)//
QVector<coinobject*> COINZ;
QVector<player_weapon*> PWEAPONS;
QVector<enemy1_weapon*> E1WEAPONS;
QVector<enemy2_weapon*> E2WEAPONS;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g = new game;
    w= new MainWindow ;
    w->show();
    return a.exec();
}
