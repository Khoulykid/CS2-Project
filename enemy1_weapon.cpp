#include "enemy1_weapon.h"
#include "player.h"
#include "game.h"
#include "form.h"
extern Form *f;
extern game* g;

enemy1_weapon::enemy1_weapon(int dataitem[11][61], int r, int c, QString d)
{
    pass=false;
    row=r;
    column=c;
    direction = d;
    if(direction == "up"){
    QPixmap wp("Z:/CSPROJ/GameNew/enemyweaponup.png");
    wp=wp.scaledToWidth(70);
    wp=wp.scaledToHeight(70);
    setPixmap(wp);
    setPos(70*column+30,70*row-70);
    }
    else if(direction == "down"){
        QPixmap wp("Z:/CSPROJ/GameNew/enemyweapondown.png");
        wp=wp.scaledToWidth(70);
        wp=wp.scaledToHeight(70);
        setPixmap(wp);
        setPos(70*column+30,70*row+70);
    }
    else if(direction == "right"){
        QPixmap wp("Z:/CSPROJ/GameNew/enemyweaponright2.png");
        wp=wp.scaledToWidth(35);
        wp=wp.scaledToHeight(20);
        setPixmap(wp);
        setPos(70*column+70,70*row+30);
    }
    else if(direction == "left"){
        QPixmap wp("Z:/CSPROJ/GameNew/enemyweaponleft3.png");
        wp=wp.scaledToWidth(35);
        wp=wp.scaledToHeight(20);
        setPixmap(wp);
        setPos(70*column-70,70*row+30);
    }
    stop = false;

    for(int i = 0; i<11; i++)
        for(int j = 0; j<61; j++)
            data[i][j] = dataitem[i][j];
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(800);

}

void enemy1_weapon::move()
{
    if(!g->pause)
    {
        dmg();
        if((direction == "right") && (data[row][column+1]>0)){
            column++;
            setPos(70*column, 70*row+30);
            dmg();
        }
        else if((direction == "left") && (data[row][column-1]>0)){
                column--;
                setPos(70*column, 70*row+30);
                dmg();
        }
        else if((direction == "up") && (data[row-1][column]>0)){
               row--;
               setPos(70*column+30, 70*row);
                dmg();
        }
        else if((direction == "down") && (data[row+1][column]>0)){
                row++;
                setPos(70*column+30, 70*row);
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

void enemy1_weapon::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (player)){
            g->health->decrement(10);
            if(g->health->gethp()<=0 && !g->lost){
                g->lost=true;
                f = new Form;
                f->show();
                delete g->p;
                delete this;
                return;
            }
            else
            {
                scene()->removeItem(this);
                delete this;
            }
        }
    }
}
