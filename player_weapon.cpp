#include "player_weapon.h"
#include "game.h"
#include "win.h"
#include "coinobject.h"
#include <time.h>
#include <stdlib.h>

extern game *g;
extern Win *win;

player_weapon::player_weapon(int dataitem[11][61],int r, int c, QString d )
{
    srand(time(NULL));
    row=r;
    column=c;
    direction = d;
    if(!g->bought[4]){
    QPixmap w("Z:/CSPROJ/GameNew/playerweapon.png");
    w=w.scaledToWidth(70);
    w=w.scaledToHeight(70);
    setPixmap(w);
    setPos(70*column,70*row);
    }
    else
    {
        QPixmap w("Z:/CSPROJ/GameNew/playerweapon2.png");
        w=w.scaledToWidth(50);
        w=w.scaledToHeight(50);
        setPixmap(w);
        setPos(70*column+12,70*row+15);
    }

    stop = false;
    for(int i = 0; i<11; i++)
        for(int j = 0; j<61; j++)
            data[i][j] = dataitem[i][j];
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(300);
}

QString player_weapon::getdirection()
{
    return direction;
}

void player_weapon::move()
{
    if(!g->pause)
    {
        QList<QGraphicsItem *> collidningitem= collidingItems();
        for(int i =0 , n =collidningitem.size(); i<n ; i++){
            if(typeid (*(collidningitem[i]))==typeid (enemy1) || typeid (*(collidningitem[i]))==typeid (enemy2))
            {
                scene()->removeItem(collidningitem[i]);
                scene()->removeItem(this);
                delete collidningitem[i];
                g->counter++;
                delete this;
                return;
            }
            else if ( typeid (*(collidningitem[i]))==typeid(BigBoss))
            {
                if(!g->bought[4])
                    g->boss->health=g->boss->health-25;
                else
                    g->boss->health=g->boss->health-50;
                if(g->boss->health<=0){
                    scene()->removeItem(collidningitem[i]);
                    //scene()->removeItem(this);
                    delete collidningitem[i];
                    win = new Win;
                    win->show();
                    delete g->p;
                    g->close();
                    //return;
                }
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        if(!g->bought[4])
        {
            if((direction == "right") && (data[row][column+1]>0)){
                column++;
                setPos(70*column, 70*row);
            }
            else if((direction == "left") && (data[row][column-1]>0)){
                column--;
                setPos(70*column, 70*row);
            }
            else if((direction == "up") && (data[row-1][column]>0)){
                row--;
                setPos(70*column, 70*row);
            }
            else if((direction == "down") && (data[row+1][column]>0)){
                row++;
                setPos(70*column, 70*row);
            }

            else{

                timer->stop();
                stop = true;
                scene()->removeItem(this);
                delete this;
            }
        }
        else
        {
            if((direction == "right") && (data[row][column+1]>0)){
                column++;
                setPos(70*column+12, 70*row+15);
            }
            else if((direction == "left") && (data[row][column-1]>0)){
                column--;
                setPos(70*column+12, 70*row+15);
            }
            else if((direction == "up") && (data[row-1][column]>0)){
                row--;
                setPos(70*column+12, 70*row+15);
            }
            else if((direction == "down") && (data[row+1][column]>0)){
                row++;
                setPos(70*column+12, 70*row+15);
            }

            else{

                timer->stop();
                stop = true;
                scene()->removeItem(this);
                delete this;
            }
        }
        collidningitem= collidingItems();
        for(int i =0 , n =collidningitem.size(); i<n ; i++){
            if(typeid (*(collidningitem[i]))==typeid (enemy1) || typeid (*(collidningitem[i]))==typeid (enemy2))
            {
                scene()->removeItem(collidningitem[i]);
                spawncoins();
                scene()->removeItem(this);
                delete collidningitem[i];
                g->counter++;
                delete this;
                return;
            }
            else if ( typeid (*(collidningitem[i]))==typeid(BigBoss))
            {
                if(!g->bought[4])
                    g->boss->health=g->boss->health-25;
                else
                    g->boss->health=g->boss->health-50;
                if(g->boss->health<=0){
                    scene()->removeItem(collidningitem[i]);
                    delete collidningitem[i];
                    win = new Win;
                    win->show();
                    delete g->p;
                }
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}

player_weapon::~player_weapon(){

}

bool player_weapon::getstop()
{
    return stop;
}

int player_weapon::getcol()
{
    return column;
}

int player_weapon::getrow()
{
    return row;
}

void player_weapon::setrow(int r)
{
    row = r;
}

void player_weapon::setcol(int c)
{
    column = c;
}

void player_weapon::spawncoins()
{
    int random = rand()%5;
    for(int i = 0; i<random; i++)
    {
        int randoo = rand()%5 + 1;
        if(randoo == 1)
        {
            coinobject* coinz = new coinobject(row, column);
            scene()->addItem(coinz);
        }
        else if(randoo == 2 && data[row-1][column]>0)
        {
            coinobject* coinz = new coinobject(row-1, column);
            scene()->addItem(coinz);
        }
        else if(randoo == 3 && data[row+1][column]>0)
        {
            coinobject* coinz = new coinobject(row+1, column);
            scene()->addItem(coinz);
        }
        else if(randoo == 4 && data[row][column-1]>0)
        {
            coinobject* coinz = new coinobject(row, column-1);
            scene()->addItem(coinz);
        }
        else if(randoo == 5 && data[row][column+1]>0)
        {
            coinobject* coinz = new coinobject(row, column+1);
            scene()->addItem(coinz);
        }
    }
}
