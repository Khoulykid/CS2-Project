#include "bigboss_weapon.h"
#include "enemy1_weapon.h"
#include "player.h"
#include "game.h"
#include "form.h"
extern Form *f;
extern game* g;
bigboss_weapon::bigboss_weapon(int dataitem[11][61], int r, int c, QString d)
{
    row=r;
    column=c;
    direction = d;
    stop = false;
    if(direction == "up"){
        QPixmap wp("Z:/CSPROJ/GameNew/fireup.png");
        wp=wp.scaledToWidth(70);
        wp=wp.scaledToHeight(70);
        setPixmap(wp);
        setPos(70*column+21,70*row-70);
    }
    else if(direction == "down"){
        QPixmap wp("Z:/CSPROJ/GameNew/firedown.png");
        wp=wp.scaledToWidth(70);
        wp=wp.scaledToHeight(70);
        setPixmap(wp);
        setPos(70*column+21,70*row+70);
    }
    else if(direction == "right"){
        QPixmap wp("Z:/CSPROJ/GameNew/fireright.png");
        wp=wp.scaledToWidth(42);
        wp=wp.scaledToHeight(42);
        setPixmap(wp);
        setPos(70*column+70,70*row+23);
    }
    else if(direction == "left"){
        QPixmap wp("Z:/CSPROJ/GameNew/fireleft.png");
        wp=wp.scaledToWidth(42);
        wp=wp.scaledToHeight(42);
        setPixmap(wp);
        setPos(70*column-70,70*row+23);
    }
    for(int i = 0; i<11; i++)
        for(int j = 0; j<61; j++)
            data[i][j] = dataitem[i][j];
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(800);
}

void bigboss_weapon:: move()
{
    if(!g->pause)
    {
        dmg();

        if((direction == "right") && (data[row][column+1]>0)){
            column++;
            setPos(70*column, 70*row+23);
            dmg();
        }
        else if((direction == "left") && (data[row][column-1]>0)){
            column--;
            setPos(70*column, 70*row+23);
            dmg();
            }
        else if((direction == "up") && (data[row-1][column]>0)){
            row--;
            setPos(70*column+21, 70*row);
            dmg();
           }
        else if((direction == "down") && (data[row+1][column]>0)){
            row++;
            setPos(70*column+21, 70*row);
            dmg();
        }

        else{
            timer->stop();
            stop = true;
            scene()->removeItem(this);
            delete this;

        }
    }
}

void bigboss_weapon::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (player)){
            g->health->decrement(30);
            if(g->health->gethp()<=0 && !g->lost){
               g->lost=true;
               f = new Form;
               f->show();
               delete this;
               return;
            }
        }
    }
}
