#ifndef WIN_H
#define WIN_H

#include <QMainWindow>

namespace Ui {
class Win;
}

class Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();

private slots:
    void on_playagain_clicked();

    void on_exit_clicked();

private:
    Ui::Win *ui;
};

#endif // WIN_H
