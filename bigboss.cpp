#include "bigboss.h"
#include "bigboss_weapon.h"
#include "game.h"
#include <QDebug>
#include "form.h"

extern Form* f;
extern game* g;
extern QVector<enemy1*> botatos;
BigBoss::BigBoss(int dataitem[11][61],int r, int c)
{
    srand(time(NULL));
    totalcost=0;
    health =500;
    row=r;
    column=c;
    boss = new QPixmap("Z:/CSPROJ/GameNew/bigboss.png");
    bossleft = new QPixmap("Z:/CS PROJECT/GAME/bigbossleft.png");
    *boss=boss->scaledToWidth(65);
    *boss=boss->scaledToHeight(65);
    *bossleft=bossleft->scaledToHeight(90);
    *bossleft=bossleft->scaledToWidth(90);
    setPixmap(*boss);
    setPos(70*column,70*row);
    for(int i=0;i<11;i++)
        for (int j=0;j<61;j++)
            data[i][j]=dataitem[i][j];

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    weapontimer = new QTimer(this);
    connect(weapontimer, SIGNAL(timeout()), this, SLOT(shoot()));

    gethardertimer = new QTimer(this);
    connect(gethardertimer, SIGNAL(timeout()), this, SLOT(HARDER()));

    enemyspawntimer = new QTimer(this);
    connect(enemyspawntimer, SIGNAL(timeout()), this, SLOT(enemyspawn()));

    healthregentimer = new QTimer(this);
    connect(healthregentimer, SIGNAL(timeout()), this, SLOT(HEAL()));

}

void BigBoss::move()
{
    if(!g->pause)
    {
        if(!(row == g->p->getRow() && column == g->p->getCol()))
        {
            if(path.isEmpty()){
                findpath(row, column, g->p->getRow(), g->p->getCol());
            }

            if(row == path[0].row-1)
                direction = "down";

            else if(row == path[0].row +1)
                direction = "up";

            else if(column == path[0].col-1)
                direction = "right";

            else
                direction = "left";

            if(direction == "left")
                setPixmap(*bossleft);

            else if(direction == "right")
                setPixmap(*boss);


            row=path[0].row;
            column=path[0].col;
            setPos(70*column,70*row);
            path.pop_front();
        }
        dmg();
    }
}

void BigBoss::shoot()
{
    if(!g->pause)
    {
        if(direction=="up"&&data[row-1][column]>=0){
            bigboss_weapon* eweap = new bigboss_weapon(data, row, column, direction);
            scene()->addItem(eweap);
        }
        if(direction=="down"&&data[row+1][column]>=0){
            bigboss_weapon* eweap = new bigboss_weapon(data, row, column, direction);
            scene()->addItem(eweap);
        }
        if(direction=="left"&&data[row][column-1]>=0){
            bigboss_weapon* eweap = new bigboss_weapon(data, row, column, direction);
            scene()->addItem(eweap);
        }
        if(direction=="right"&&data[row][column+1]>=0){
            bigboss_weapon* eweap = new bigboss_weapon(data, row, column, direction);
            scene()->addItem(eweap);
        }
    }
}

int BigBoss::getrow()
{
    return row;
}

int BigBoss::getcolumn()
{
    return column;
}

void BigBoss::findpath(int startingRow, int startingCol, int finalRow, int finalCol)
{
    if( (finalRow == startingRow + 1 && finalCol == startingCol) || (finalRow == startingRow - 1 && finalCol == startingCol) || (finalRow == startingRow && finalCol == startingCol-1) || (finalRow == startingRow && finalCol == startingCol+1) )
    {
        Node point(finalRow, finalCol, -1, -1, 0, 0);
        path.push_front(point);
    }
    else
    {

        Node allNodes[11][61];
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 61; j++)
                updateAllNodes(allNodes, i, j, -1, -1, 1000, 1000);
        QVector<Node> openNodes;
        QVector<Node> closedNodes;
        Node currentNode(startingRow, startingCol, -1, -1, 0, getDistance(startingRow, startingCol, finalRow, finalCol));   //initializes starting Node that starts from the place of the boss
        updateAllNodes(allNodes, currentNode.row, currentNode.col, currentNode.parentRow, currentNode.parentCol, currentNode.gCost, currentNode.hCost); // updates the starting Node in allNodes with its new parents and such
        openNodes.push_back(currentNode);   // pushes it as the first step for the boss to take (idk if this is useful or not but it was in the main code)

        while (!openNodes.empty())  // works until openNodes is empty (idk where this exactly functions im very sleepy and its 5:47 am)
        {
            sort(openNodes);
            currentNode = openNodes[0];
            openNodes.pop_front();

            if ((currentNode.row == finalRow) && (currentNode.col == finalCol)) //checks if we entered the final target
            {
                while (currentNode.parentRow != -1) // as long as it is not the starting point with -ve parents
                {
                    path.insert(path.begin(), currentNode); // haydakhal el current fi el path
                    currentNode = allNodes[currentNode.parentRow][currentNode.parentCol];   // makes the current node equals to its parents so it could follow the path from target to boss loc
                }
                path.insert(path.begin(), currentNode);
            }

            // Process the 4 adjacent nodes of currentNode where currentNode is at x and y:
            // 1. North         (row, column - 1)
            // 2. East         (row + 1, column)
            // 3. West         (row - 1, column)
            // 4. South         (row, column + 1)

    //        bool exists = false;
    //        int neighbourRow = currentNode.row - 1, neighbourCol = currentNode.col + 1;
    //        if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
    //        {
    //            float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
    //            Node northEast(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
    //            for (int i = 0; i < closedNodes.size(); i++)
    //                if (closedNodes[i] == northEast)
    //                {
    //                    exists = true;
    //                    break;
    //                }
    //            for (int i = 0; i < openNodes.size(); i++)
    //                if (openNodes[i] == northEast)
    //                {
    //                    exists = true;
    //                    if (openNodes[i].fCost <= northEast.fCost)
    //                        break;
    //                    else
    //                    {
    //                        openNodes[i].fCost = northEast.fCost;
    //                        updateAllNodes(allNodes, northEast.row, northEast.col, northEast.parentRow, northEast.parentCol, northEast.gCost, northEast.hCost);
    //                    }
    //                }
    //            if (!exists)
    //            {
    //                openNodes.push_back(northEast);
    //                updateAllNodes(allNodes, northEast.row, northEast.col, northEast.parentRow, northEast.parentCol, northEast.gCost, northEast.hCost);
    //            }
    //        }

            bool exists = false;    //to check if it already exists in the closedNodes and/or openNodes
            bool flag = false;      //instead of break for sarah
            int neighbourRow = currentNode.row - 1, neighbourCol = currentNode.col;
            if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
                //checks if next step is acceptable or not
            {
                float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
                Node north(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
                for (int i = 0; i < closedNodes.size() && !exists; i++)
                    if (closedNodes[i] == north)
                    {
                        exists = true;
                        //if it exists in closed then we dont want it.
                    }
                for (int i = 0; i < openNodes.size() && !flag; i++)
                    if (openNodes[i] == north)
                    {
                        exists = true;
                        if (openNodes[i].fCost <= north.fCost)
                            flag = true;    //if it already exists in openNodes with a lower value then we dont want it
                        else
                        {
                            openNodes[i].fCost = north.fCost;
                            updateAllNodes(allNodes, north.row, north.col, north.parentRow, north.parentCol, north.gCost, north.hCost); // if this has a less value than the previous we update it
                        }
                    }
                if (!exists)
                {
                    openNodes.push_back(north);
                    updateAllNodes(allNodes, north.row, north.col, north.parentRow, north.parentCol, north.gCost, north.hCost);
                    //if it doesnt exist in either, we add it to the OpenNodes
                }
            }

    //        exists = false;
    //        neighbourRow = currentNode.row - 1, neighbourCol = currentNode.col - 1;
    //        if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
    //        {
    //            float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
    //            Node northWest(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
    //            for (int i = 0; i < closedNodes.size(); i++)
    //                if (closedNodes[i] == northWest)
    //                {
    //                    exists = true;
    //                    break;
    //                }
    //            for (int i = 0; i < openNodes.size(); i++)
    //                if (openNodes[i] == northWest)
    //                {
    //                    exists = true;
    //                    if (openNodes[i].fCost <= northWest.fCost)
    //                        break;
    //                    else
    //                    {
    //                        openNodes[i].fCost = northWest.fCost;
    //                        updateAllNodes(allNodes, northWest.row, northWest.col, northWest.parentRow, northWest.parentCol, northWest.gCost, northWest.hCost);
    //                    }
    //                }
    //            if (!exists)
    //            {
    //                openNodes.push_back(northWest);
    //                updateAllNodes(allNodes, northWest.row, northWest.col, northWest.parentRow, northWest.parentCol, northWest.gCost, northWest.hCost);
    //            }
    //        }

            exists = false;
            flag = false;
            neighbourRow = currentNode.row, neighbourCol = currentNode.col + 1;
            if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
            {
                float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
                Node east(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
                for (int i = 0; i < closedNodes.size() && !exists; i++)
                    if (closedNodes[i] == east)
                    {
                        exists = true;
                    }
                for (int i = 0; i < openNodes.size() && !flag; i++)
                    if (openNodes[i] == east)
                    {
                        exists = true;
                        if (openNodes[i].fCost <= east.fCost)
                            flag = true;
                        else
                        {
                            openNodes[i].fCost = east.fCost;
                            updateAllNodes(allNodes, east.row, east.col, east.parentRow, east.parentCol, east.gCost, east.hCost);
                        }
                    }
                if (!exists)
                {
                    openNodes.push_back(east);
                    updateAllNodes(allNodes, east.row, east.col, east.parentRow, east.parentCol, east.gCost, east.hCost);
                }
            }

            exists = false;
            flag = false;
            neighbourRow = currentNode.row, neighbourCol = currentNode.col - 1;
            if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
            {
                float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
                Node west(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
                for (int i = 0; i < closedNodes.size() && !exists; i++)
                    if (closedNodes[i] == west)
                    {
                        exists = true;
                    }
                for (int i = 0; i < openNodes.size() && !flag; i++)
                    if (openNodes[i] == west)
                    {
                        exists = true;
                        if (openNodes[i].fCost <= west.fCost)
                            flag = true;
                        else
                        {
                            openNodes[i].fCost = west.fCost;
                            updateAllNodes(allNodes, west.row, west.col, west.parentRow, west.parentCol, west.gCost, west.hCost);
                        }
                    }
                if (!exists)
                {
                    openNodes.push_back(west);
                    updateAllNodes(allNodes, west.row, west.col, west.parentRow, west.parentCol, west.gCost, west.hCost);
                }
            }

    //        exists = false;
    //        neighbourRow = currentNode.row + 1, neighbourCol = currentNode.col + 1;
    //        if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
    //        {
    //            float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
    //            Node southEast(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
    //            for (int i = 0; i < closedNodes.size(); i++)
    //                if (closedNodes[i] == southEast)
    //                {
    //                    exists = true;
    //                    break;
    //                }
    //            for (int i = 0; i < openNodes.size(); i++)
    //                if (openNodes[i] == southEast)
    //                {
    //                    exists = true;
    //                    if (openNodes[i].fCost <= southEast.fCost)
    //                        break;
    //                    else
    //                    {
    //                        openNodes[i].fCost = southEast.fCost;
    //                        updateAllNodes(allNodes, southEast.row, southEast.col, southEast.parentRow, southEast.parentCol, southEast.gCost, southEast.hCost);
    //                    }
    //                }
    //            if (!exists)
    //            {
    //                openNodes.push_back(southEast);
    //                updateAllNodes(allNodes, southEast.row, southEast.col, southEast.parentRow, southEast.parentCol, southEast.gCost, southEast.hCost);
    //            }
    //        }

            exists = false;
            flag = false;
            neighbourRow = currentNode.row + 1, neighbourCol = currentNode.col;
            if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
            {
                float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
                Node south(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
                for (int i = 0; i < closedNodes.size() && !exists; i++)
                    if (closedNodes[i] == south)
                    {
                        exists = true;
                    }
                for (int i = 0; i < openNodes.size() && !flag; i++)
                    if (openNodes[i] == south)
                    {
                        exists = true;
                        if (openNodes[i].fCost <= south.fCost)
                            flag = true;
                        else
                        {
                            openNodes[i].fCost = south.fCost;
                            updateAllNodes(allNodes, south.row, south.col, south.parentRow, south.parentCol, south.gCost, south.hCost);
                        }
                    }
                if (!exists)
                {
                    openNodes.push_back(south);
                    updateAllNodes(allNodes, south.row, south.col, south.parentRow, south.parentCol, south.gCost, south.hCost);
                }
            }

    //        exists = false;
    //        neighbourRow = currentNode.row + 1, neighbourCol = currentNode.col - 1;
    //        if (data[neighbourRow][neighbourCol] >= 0 || data[neighbourRow][neighbourCol] == -91 || data[neighbourRow][neighbourCol] == -92 || data[neighbourRow][neighbourCol] == -93 || data[neighbourRow][neighbourCol] == -94)
    //        {
    //            float gCost = getDistance(startingRow, startingCol, currentNode.row, currentNode.col) + getDistance(currentNode.row, currentNode.col, neighbourRow, neighbourCol);
    //            Node southWest(neighbourRow, neighbourCol, currentNode.row, currentNode.col, gCost, getDistance(neighbourRow, neighbourCol, finalRow, finalCol));
    //            for (int i = 0; i < closedNodes.size(); i++)
    //                if (closedNodes[i] == southWest)
    //                {
    //                    exists = true;
    //                    break;
    //                }
    //            for (int i = 0; i < openNodes.size(); i++)
    //                if (openNodes[i] == southWest)
    //                {
    //                    exists = true;
    //                    if (openNodes[i].fCost <= southWest.fCost)
    //                        break;
    //                    else
    //                    {
    //                        openNodes[i].fCost = southWest.fCost;
    //                        updateAllNodes(allNodes, southWest.row, southWest.col, southWest.parentRow, southWest.parentCol, southWest.gCost, southWest.hCost);
    //                    }
    //                }
    //            if (!exists)
    //            {
    //                openNodes.push_back(southWest);
    //                updateAllNodes(allNodes, southWest.row, southWest.col, southWest.parentRow, southWest.parentCol, southWest.gCost, southWest.hCost);
    //            }
    //        }

            closedNodes.push_back(currentNode); //since we already used the currentNode and inputted it, we add it to the closedNodes
        }
    }
}

float BigBoss:: getDistance(int x1, int y1, int x2, int y2)
{
    float deltaX = x1 - x2;
    float deltaY = y1 - y2;
    return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

void BigBoss::sort(QVector<Node> nodes)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        for (int j = i + 1; j < nodes.size(); j++)
        {
            if (nodes[j].fCost < nodes[i].fCost){
               Node temp;
               temp= nodes[i];
               nodes[i]=nodes[j];
               nodes[j]=temp;
            }
        }
    }
}

void BigBoss::updateAllNodes(Node allNodes[11][61], int row, int col, int pRow, int pCol, float gCost, float hCost)
{
    allNodes[row][col].row = row;
    allNodes[row][col].col = col;
    allNodes[row][col].parentRow = pRow;
    allNodes[row][col].parentCol = pCol;
    allNodes[row][col].gCost = gCost;
    allNodes[row][col].hCost = hCost;
    allNodes[row][col].fCost = gCost + hCost;
}

BigBoss ::~BigBoss()
{
    g->SPAWN[8] = false;
    timer->stop();
    weapontimer->stop();
    delete timer;
    delete weapontimer;
}

void BigBoss::dmg()
{
    QList<QGraphicsItem *> collidningitem= collidingItems();
    for(int j =0 , n =collidningitem.size(); j<n ; j++)
    {
        if(typeid (*(collidningitem[j]))==typeid (player))
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
        }
    }
}

void BigBoss::enemyspawn()
{
    if(!g->pause)
    {
        int random = rand()%2;
        if(random == 1)
        {
            enemy1* potato = new enemy1(data, row, column, 10);
            scene()->addItem(potato);
        }
        else
        {
            enemy1* potato = new enemy2(data, row, column, 10);
            scene()->addItem(potato);
        }
    }
}

void BigBoss::HARDER()
{
    enemyspawntimer->start(8000);
    healthregentimer->start(10000);
    gethardertimer->stop();
}

void BigBoss::HEAL()
{
    if(!g->pause)
        health+=100;
}

