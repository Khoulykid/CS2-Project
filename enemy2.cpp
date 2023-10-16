#include "enemy2.h"
#include "game.h"
#include "form.h"

extern Form *f;
extern game *g;
extern QVector<enemy1*> botatos;

enemy2::enemy2 (int dataitem[11][61], int r, int c, int n)
{
    srand(time(NULL));
    row=r;
    column=c;
    spawnrow = r;
    spawncol = c;
    number_enemy=n;
    QPixmap e1("Z:/CSPROJ/GameNew/enemy2.png");
    e1=e1.scaledToWidth(65);
    e1=e1.scaledToHeight(65);
    setPixmap(e1);
    setPos(70*column,70*row);
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1500);
    weapontimer = new QTimer(this);
    connect(weapontimer, SIGNAL(timeout()), this, SLOT(shoot()));
    weapontimer->start(1500);
}

void enemy2::move()
{
    if(!g->pause)
    {
        random = rand()%4;
        if(number_enemy==1)
        {
            if(random == 0 && ((data[row-1][column]>=109 && data[row-1][column]<133) || data[row-1][column]==-5)&&(data[row-1][column]!=115)){
                row--;
                direction ="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && ((data[row+1][column]>=109 && data[row+1][column]<133) || data[row+1][column]==-5)&&(data[row+1][column]!=115)){
                row++;
                direction ="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && ((data[row][column+1]>=109&& data[row][column+1] <133) || data[row][column+1] ==-5)&&(data[row][column+1]!=115)){
                column++;
                direction ="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && ((data[row][column-1] >=109 && data[row][column-1] <133) || data[row][column-1] ==-5)&&(data[row][column-1]!=115)){
                column--;
                direction ="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
        else if(number_enemy==2)
        {
            if(random == 0 && ((data[row-1][column]>=133 && data[row-1][column]<=135) || data[row-1][column]==-4)){
                row--;
                direction ="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && ((data[row+1][column]>=133 && data[row+1][column]<=135)  || data[row+1][column]==-4)){
                row++;
                direction ="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && ((data[row][column+1]>=133&& data[row][column+1] <=135) || data[row][column+1]==-4)){
                column++;
                direction ="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && ((data[row][column-1] >=133 && data[row][column-1] <=135) || data[row][column-1]==-4)){
                column--;
                direction ="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
        else if(number_enemy==3)
        {
            if(random == 0 && ((data[row-1][column]>=148 && data[row-1][column]<=165) || data[row-1][column]==-4)){
                row--;
                direction ="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && ((data[row+1][column]>=148 && data[row+1][column]<=165)  || data[row+1][column]==-4)){
                row++;
                direction ="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && ((data[row][column+1]>=148&& data[row][column+1] <=165) || data[row][column+1]==-4)){
                column++;
                direction ="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && ((data[row][column-1] >=148 && data[row][column-1] <=165) || data[row][column-1]==-4)){
                column--;
                direction ="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
        else if(number_enemy==10)
        {
            if(random == 0 && (data[row-1][column]>-2 && data[row-1][column]>-2)){
                row--;
                direction ="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && (data[row+1][column]>-2 && data[row+1][column]>-2)){
                row++;
                direction ="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && (data[row][column+1]>-2 && data[row][column+1]>-2)){
                column++;
                direction ="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && (data[row-1][column-1]>-2 && data[row][column-1]>-2)){
                column--;
                direction ="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
        else
        {
            if(random == 0 && ((data[row-1][column]>=1 && data[row-1][column]<=5) || data[row-1][column]==-5)){
                row--;
                direction ="up";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 1 && ((data[row+1][column]>=1 && data[row+1][column]<=5)  || data[row+1][column]==-5)){
                row++;
                direction ="down";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 2 && ((data[row][column+1]>=1&& data[row][column+1] <=5) || data[row][column+1]==-5)){
                column++;
                direction ="right";
                setPos(70*column, 70*row);
                dmg();
            }
            else if(random == 3 && ((data[row][column-1] >=1 && data[row][column-1] <=5) || data[row][column-1]==-5)){
                column--;
                direction ="left";
                setPos(70*column, 70*row);
                dmg();
            }
        }
    }
}

void enemy2::shoot()
{
    if(!g->pause)
    {
        int random = rand()%3;
        if(random==0&& (number_enemy==1 || number_enemy==3))
        {
            if(direction == "up" && data[row-1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,1);
                scene()->addItem(eweap);
            }
            if(direction == "down" && data[row+1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,1);
                scene()->addItem(eweap);
            }
            if(direction == "left" && data[row][column-1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,1);
                scene()->addItem(eweap);
            }
            if(direction == "right" && data[row][column+1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,1);
                scene()->addItem(eweap);
            }
        }
        if(random==0&& (number_enemy==2 || number_enemy==4))
        {
            if(direction == "up" && data[row-1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,2);
                scene()->addItem(eweap);
            }
            if(direction == "down" && data[row+1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,2);
                scene()->addItem(eweap);
            }
            if(direction == "left" && data[row][column-1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,2);
                scene()->addItem(eweap);
            }
            if(direction == "right" && data[row][column+1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,2);
                scene()->addItem(eweap);
            }
        }
        else if(number_enemy == 10)
        {
            if(direction == "up" && data[row-1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,3);
                scene()->addItem(eweap);
            }
            if(direction == "down" && data[row+1][column]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,3);
                scene()->addItem(eweap);
            }
            if(direction == "left" && data[row][column-1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,3);
                scene()->addItem(eweap);
            }
            if(direction == "right" && data[row][column+1]!=-2)
            {
                enemy2_weapon* eweap = new enemy2_weapon(data, row, column, direction,3);
                scene()->addItem(eweap);
            }
        }
    }
}

void enemy2::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int j =0 , n =collidningitem.size(); j<n ; j++)
    {
        if(typeid (*(collidningitem[j]))==typeid (player))
        {
            g->health->decrement(20);
            if(g->health->gethp()<=0 && !g->lost){
                g->lost=true;
                f = new Form;
                f->show();
                delete g->p;
                delete this;
                return;
            }
        }
    }
}

enemy2::~enemy2()
{
    if(number_enemy != 10)
        g->SPAWN[number_enemy + 3] = false;
}
