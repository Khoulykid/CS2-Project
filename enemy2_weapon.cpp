#include "enemy2_weapon.h"
#include "player.h"
#include "game.h"
#include "form.h"
extern Form *f;
extern game* g;

enemy2_weapon::enemy2_weapon(int dataitem[11][61], int r, int c, QString d,int n){
    pass=false;
    number_weapon=n;
    row=r;
    column=c;
    direction = d;
    if(direction == "up"){
        QPixmap w("Z:/CSPROJ/GameNew/weapon2 up.png");
        w=w.scaledToWidth(70);
        w=w.scaledToHeight(70);
        setPixmap(w);
        setPos(70*column+20,70*row-70);
    }
    else if(direction == "down"){
        QPixmap w("Z:/CSPROJ/GameNew/weapon2 down.png");
        w=w.scaledToWidth(70);
        w=w.scaledToHeight(70);
        setPixmap(w);
        setPos(70*column+20,70*row+70);
    }
    else if(direction == "right"){
        QPixmap w("Z:/CSPROJ/GameNew/weapon2 right.png");
        w=w.scaledToWidth(50);
        w=w.scaledToHeight(30);
        setPixmap(w);
        setPos(70*column+70,70*row+20);
    }
    else if(direction == "left"){
        QPixmap w("Z:/CSPROJ/GameNew/weapon2 left.png");
        w=w.scaledToWidth(50);
        w=w.scaledToHeight(30);
        setPixmap(w);
        setPos(70*column-70,70*row+20);
    }
    stop = false;

    for(int i = 0; i<11; i++)
        for(int j = 0; j<49; j++)
            data[i][j] = dataitem[i][j];
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(800);

}

void enemy2_weapon::move()
{
    if(!g->pause)
    {
        dmg();
        if(number_weapon==1){
            if((direction == "right") && (data[row][column+1]!=-2)&&(data[row][column+1]==-5||data[row][column+1]>0)){
                column++;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "left") && (data[row][column-1]!=-2) &&(data[row][column-1]==-5||data[row][column-1]>0)){
                column--;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "up") && (data[row-1][column]!=-2)&&(data[row-1][column]==-5||data[row-1][column]>0)){
                row--;
                setPos(70*column+20, 70*row);
                dmg();
            }
            else if((direction == "down") && (data[row+1][column]!=-2)&&(data[row+1][column]==-5||data[row+1][column]>0)){
                row++;
                setPos(70*column+20, 70*row);
                dmg();
            }

            else{

                timer->stop();
                stop = true;
                scene()->removeItem(this);
                delete this;

            }
        }
        else if(number_weapon==2)
        {

            if((direction == "right") && (data[row][column+1]!=-2)&&(data[row][column+1]==-4||data[row][column+1]>0)){
                column++;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "left") && (data[row][column-1]!=-2) &&(data[row][column-1]==-4||data[row][column-1]>0)){
                column--;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "up") && (data[row-1][column]!=-2)&&(data[row-1][column]==-4||data[row-1][column]>0)){
                row--;
                setPos(70*column+20, 70*row);
                dmg();
            }
            else if((direction == "down") && (data[row+1][column]!=-2)&&(data[row+1][column]==-4||data[row+1][column]>0)){
                row++;
                setPos(70*column+20, 70*row);
                dmg();
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
            if((direction == "right") && (data[row][column+1]!=-2)){
                column++;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "left") && (data[row][column-1]!=-2)){
                column--;
                setPos(70*column, 70*row+20);
                dmg();
            }
            else if((direction == "up") && (data[row-1][column]!=-2)){
                row--;
                setPos(70*column+20, 70*row);
                dmg();
            }
            else if((direction == "down") && (data[row+1][column]!=-2)){
                row++;
                setPos(70*column+20, 70*row);
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
}

void enemy2_weapon::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++){
        if(typeid (*(collidningitem[i]))==typeid (player)){
            g->health->decrement(20);
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
