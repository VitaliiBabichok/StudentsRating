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
