#include "selectcity.h"
#include "ui_selectcity.h"



SelectCity::SelectCity(QTcpSocket *sock, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
    socket=sock;

}

SelectCity::~SelectCity()
{
    delete ui;
}



void SelectCity::on_BackSetCityButton_clicked()
{
    emit BackCityMenu();
}

void SelectCity::on_BackSetUniversityButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SelectCity::on_BackSetSpecialtyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SelectCity::on_BackSetCourseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SelectCity::on_BackRatingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
