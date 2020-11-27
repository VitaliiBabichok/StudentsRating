#include "selectcity.h"
#include "ui_selectcity.h"



SelectCity::SelectCity(QTcpSocket *sock, QJsonObject *object, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
    socket=sock;
    obj=object;

    model=new QStringListModel(this);
    QStringList City;
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
void SelectCity::GetCity( )
{


    if(obj->value("resp").toString()=="ok")
    {

        for(auto& City : obj->value("data").toVariant().toStringList())
        {

            qDebug()<<City;
        }
        model->setStringList(obj->value("data").toVariant().toStringList());
        ui->listCity->setModel(model);



    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }

}
void SelectCity::on_RefreshCity_clicked()
{
    QString reqSend = QString("{\"operation\":\"getCity\"}");
    socket->write(reqSend.toUtf8());
    socket->waitForBytesWritten(1500);
}
