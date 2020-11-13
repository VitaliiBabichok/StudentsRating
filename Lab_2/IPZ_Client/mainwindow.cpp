#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&_SetCity);

    connect(&_SetCity, SIGNAL(BackCityMenu()), this, SLOT(moveLoginMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RegisterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_BackRegisterWidget_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LoginButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(&_SetCity);
}

void MainWindow::moveLoginMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ExitButton_clicked()
{
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Exit",
     "Do you want to leave the program?",QMessageBox::Yes |  QMessageBox::No);
    if(reply== QMessageBox::Yes)
    {
        QApplication::quit();
    }

}
