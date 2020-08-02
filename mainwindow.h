#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "star_gen/star.hpp"

#define STARFIELD_SIZE 350

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void new_starscape();
    void connect_stars();

private:
    starfield<STARFIELD_SIZE> *s;
    void display_stars();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
