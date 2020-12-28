#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create and start server
    server = new Server();
    server->startServer();

}

MainWindow::~MainWindow()
{
    delete ui;
}

