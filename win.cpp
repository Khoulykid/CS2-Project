#include "win.h"
#include "ui_win.h"
#include "mainwindow.h"
#include "game.h"
extern MainWindow *w;
extern game *g;
Win::Win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
    g->lost=true;
    QPixmap bkgnd("Z:/CSPROJ/GameNew/win.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(this->width(),this->height());
    g->close();
}

Win::~Win()
{
    delete ui;
}

void Win::on_playagain_clicked()
{
    w->show();
    //delete w;
    //w = new MainWindow;
    //w->show();
    delete g;
    g = new game;
    this->close();
    delete this;
}


void Win::on_exit_clicked()
{
    delete w;
    delete g;
    this->close();
    delete this;
}

