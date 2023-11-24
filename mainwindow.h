#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "game.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *soundtrack;
    QAudioOutput *audio;
    bool getmusic();;
    bool gender;
private slots:
    void on_Start_clicked();

    void on_Exit_clicked();

    void on_on_clicked();

    void on_off_clicked();

    void on_male_clicked();

    void on_female_clicked();

private:
        Ui::MainWindow *ui;
        bool music;
};
#endif // MAINWINDOW_H
