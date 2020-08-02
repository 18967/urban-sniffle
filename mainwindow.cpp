#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    s=new starfield<STARFIELD_SIZE>;
    display_stars();
    ui->setupUi(this);

    connect(ui->action_new_starscape,&QAction::triggered,this, &MainWindow::new_starscape);
    connect(ui->action_connect_stars,&QAction::triggered,this, &MainWindow::connect_stars);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_starscape(){
    delete s;
    s=new starfield<STARFIELD_SIZE>;
    display_stars();
}

void MainWindow::connect_stars(){
    connect_closest(*s);
    display_stars();
}

void MainWindow::display_stars(){
    std::stringstream o;
    o<<*s;
    QByteArray b(o.str().c_str(),o.str().length());
    ui->svgWidget->load(b);
}
