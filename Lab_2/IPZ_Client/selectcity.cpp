#include "selectcity.h"
#include "ui_selectcity.h"

SelectCity::SelectCity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
   
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

void SelectCity::on_goUniversity_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void SelectCity::on_goSpecialty_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SelectCity::on_goCourse_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void SelectCity::on_goRating_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}
