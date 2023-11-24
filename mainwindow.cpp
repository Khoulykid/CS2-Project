#include "mainwindow.h"
extern game *g;
#include "ui_mainwindow.h"
#include "player.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    music=false;
    gender=false;
    ui->setupUi(this);
    QPixmap bkgnd("Z:/CSPROJ/GameNew/dragon.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(this->width(),this->height());
    soundtrack=new QMediaPlayer;
    audio=new QAudioOutput;
    soundtrack->setAudioOutput(audio);
    soundtrack->setSource(QUrl::fromLocalFile("Z:/CSPROJ/GameNew/Xuanzang.mp3"));
    soundtrack->setLoops(QSoundEffect::Infinite);
    audio->setVolume(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_male_clicked()
{
    gender=false;
}
void MainWindow::on_female_clicked()
{
    gender = true;

}

void MainWindow::on_Start_clicked()
{
    if(ui->name->text()!=""&& ui->name->text()!="insert name to start"){
        if(g->lost)
            g->gamestart();

        delete g->p;
        g->p = new player(g->boarddata, gender);
        g->scene->addItem(g->p);
        g->show();
        this->hide();
    }
    else
        ui->name->setText("insert name to start");
}


void MainWindow::on_Exit_clicked()
{
    delete g;
    this->close();
    delete this;
}

bool MainWindow :: getmusic(){
    return music;
}



void MainWindow::on_on_clicked()
{
     soundtrack->play();
}



void MainWindow::on_off_clicked()
{
    soundtrack->stop();
}

