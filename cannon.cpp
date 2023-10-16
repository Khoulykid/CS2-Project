#include "cannon.h"
#include "game.h"

extern game* g;

cannon::cannon(int dataitem[11][61], int r, int c , int n)
{
    row=r;
    column=c;
    number_cannon=n;
    if(number_cannon==1)
    {
        QPixmap cr("Z:/CSPROJ/GameNew/cannonright.png");
        cr=cr.scaledToWidth(90);
        cr=cr.scaledToHeight(90);
        setPixmap(cr);
        setPos(70*column-10,70*row-10);
    }
    else
    {
        QPixmap cl("Z:/CSPROJ/GameNew/cannonleft.png");
        cl=cl.scaledToWidth(90);
        cl=cl.scaledToHeight(90);
        setPixmap(cl);
        setPos(70*column-10,70*row-15);
    }
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //timer->start(1500);
    weapontimer = new QTimer(this);
    connect(weapontimer, SIGNAL(timeout()), this, SLOT(shoot()));
    weapontimer->start(2000);
}
void cannon::shoot()
{
    if(!g->pause)
    {
        if(number_cannon==1){
           bullet* br=new bullet(data,row,column+1,1);
            scene()->addItem(br);
        }
        else if(number_cannon==2){
            bullet* bl=new bullet(data,row,column-1,2);
            scene()->addItem(bl);
        }
    }
}
