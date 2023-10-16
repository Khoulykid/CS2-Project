#include "bullet.h"
#include "player.h"
#include "game.h"
#include "form.h"

extern Form *f;
extern game* g;

bullet::bullet(int dataitem[11][61], int r, int c, int n)
{
    pass=false;
    row=r;
    column=c;
    number=n;
    if(number==1)
    {
        QPixmap br("Z:/CSPROJ/GameNew/newfireright.png");
        br=br.scaledToWidth(42);
        br=br.scaledToHeight(42);
        setPixmap(br);
        setPos(70*column-28,70*row+6);
    }
    else
    {
        QPixmap bl("Z:/CSPROJ/GameNew/newfireleft.png");
        bl=bl.scaledToWidth(42);
        bl=bl.scaledToHeight(42);
        setPixmap(bl);
        setPos(70*column+28,70*row+6);
    }

     stop = false;
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(800);
}

void bullet::move()
{
    if(!g->pause)
    {
        if(number==1&&data[row][column+1]!=-1){
            column++;
            setPos(70*column-28, 70*row+6);
            dmg();
        }
        else if(number==2&&data[row][column-1]!=-1){
            column--;
            setPos(70*column+28, 70*row+6);
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

void bullet::dmg(){
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int i =0 , n =collidningitem.size(); i<n ; i++)
    {
        if(typeid (*(collidningitem[i]))==typeid (player))
        {
            g->health->decrement(30);
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
