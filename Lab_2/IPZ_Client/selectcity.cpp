#include "selectcity.h"
#include "ui_selectcity.h"




SelectCity::SelectCity(QTcpSocket *sock, QJsonObject *object, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SelectCity)
{
    ui->setupUi(this);
    socket=sock;
    obj=object;

    modelCity=new QStringListModel(this);
    modelUniver=new QStringListModel(this);
    modelSpecialty=new QStringListModel(this);
    modelCourse=new QStringListModel(this);



    ui->stackedWidget->setCurrentIndex(0);
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
    on_RefreshCity_clicked();
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


        modelCity->setStringList(obj->value("data").toVariant().toStringList());
        ui->listCity->setModel(modelCity);
        ui->listCity->setEditTriggers(QAbstractItemView::NoEditTriggers | QAbstractItemView::SelectedClicked );


    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }

}


void SelectCity::on_RefreshCity_clicked()
{
    QString CityList = QString("{\"operation\":\"getCity\"}");
    socket->write(CityList.toUtf8());
    socket->waitForBytesWritten(1500);
}





void SelectCity::on_listCity_clicked(const QModelIndex &index)
{
    QString UniverList = QString("{\"operation\":\"getUniver\", \"CITY\":\""+ui->listCity->model()->data(index).toString()+"\"}");
    socket->write(UniverList.toUtf8());
    socket->waitForBytesWritten(1500);
    qDebug()<<UniverList;
    ui->stackedWidget->setCurrentIndex(1);



}
void SelectCity::on_listUniver_clicked(const QModelIndex &index)
{

    UniverList=(ui->listUniver->model()->data(index).toString());
    QString SpecialtyList = QString("{\"operation\":\"getSpecialty\", \"UNIVER\":\""+UniverList+"\"}");
    socket->write(SpecialtyList.toUtf8());
    socket->waitForBytesWritten(1500);


    qDebug()<<UniverList;
    ui->stackedWidget->setCurrentIndex(2);

}

void SelectCity::on_listSpecialty_clicked(const QModelIndex &index)
{

    SpecialtyList=(ui->listSpecialty->model()->data(index).toString());
    QString CourseList = QString("{\"operation\":\"getCourse\", \"SPECIALTY\":\""+SpecialtyList+"\"}");
    socket->write(CourseList.toUtf8());
    socket->waitForBytesWritten(1500);


    qDebug()<<SpecialtyList;
    ui->stackedWidget->setCurrentIndex(3);
}

void SelectCity::on_listCourse_clicked(const QModelIndex &index)
{

    CourseList=(ui->listCourse->model()->data(index).toString());
    QString RatingTable = QString("{\"operation\":\"getRating\",\"UNIVER\":\""+UniverList+"\", \"SPECIALTY\":\""+SpecialtyList+"\", \"COURSE\":\""+CourseList+"\"}");
    socket->write(RatingTable.toUtf8());
    socket->waitForBytesWritten(1500);


    qDebug()<<RatingTable;
    ui->stackedWidget->setCurrentIndex(4);
}
void SelectCity::GetUniver()
{


    if(obj->value("resp").toString()=="ok")
    {


        modelUniver->setStringList(obj->value("data").toVariant().toStringList());
        ui->listUniver->setModel(modelUniver);
        ui->listUniver->setEditTriggers(QAbstractItemView::NoEditTriggers | QAbstractItemView::SelectedClicked );



    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }

}

void SelectCity::GetSpecialty()
{
    if(obj->value("resp").toString()=="ok")
    {


        modelSpecialty->setStringList(obj->value("data").toVariant().toStringList());
        ui->listSpecialty->setModel(modelSpecialty);
        ui->listSpecialty->setEditTriggers(QAbstractItemView::NoEditTriggers | QAbstractItemView::SelectedClicked );



    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }
}

void SelectCity::GetCourse()
{
    if(obj->value("resp").toString()=="ok")
    {


        modelCourse->setStringList(obj->value("data").toVariant().toStringList());
        ui->listCourse->setModel(modelCourse);
        ui->listCourse->setEditTriggers(QAbstractItemView::NoEditTriggers | QAbstractItemView::SelectedClicked );



    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }
}

void SelectCity::GetRating()
{

    if(obj->value("resp").toString()=="ok")
    {

        QModelIndex modelIndex;
        QStringList ArrRating=obj->value("data").toVariant().toStringList();
        modelRating=new QStandardItemModel(ArrRating.length()/4, 4, this);

            for (int row = 0; row < ArrRating.length()/4; ++row )
            {
                for(int col=0; col<4;++col)
                {
                    modelIndex=modelRating->index(row,col);
                    modelRating->setData(modelIndex,ArrRating[row*4+col]);
                    modelRating->setData(modelIndex, Qt::AlignLeft, Qt::TextForceLeftToRight);

                }

            }


           modelRating->setHeaderData(0,Qt::Horizontal ,"Група");
           modelRating->setHeaderData(1,Qt::Horizontal ,"Прізвище");
           modelRating->setHeaderData(2,Qt::Horizontal ,"Ім'я");
           modelRating->setHeaderData(3,Qt::Horizontal ,"Бал");

            ui->tableRatings->setModel(modelRating);
            ui->tableRatings->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableRatings->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 13pt; }");
            ui->tableRatings->setEditTriggers(QAbstractItemView::NoEditTriggers );


    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }
}

void SelectCity::SearchGroup()
{
    if(obj->value("resp").toString()=="ok")
    {

        QModelIndex modelIndex;
        QStringList ArrRating=obj->value("data").toVariant().toStringList();
        modelRating=new QStandardItemModel(ArrRating.length()/4, 4, this);

            for (int row = 0; row < ArrRating.length()/4; ++row )
            {
                for(int col=0; col<4;++col)
                {
                    modelIndex=modelRating->index(row,col);
                    modelRating->setData(modelIndex,ArrRating[row*4+col]);
                    modelRating->setData(modelIndex, Qt::AlignLeft, Qt::TextForceLeftToRight);

                }

            }


           modelRating->setHeaderData(0,Qt::Horizontal ,"Група");
           modelRating->setHeaderData(1,Qt::Horizontal ,"Прізвище");
           modelRating->setHeaderData(2,Qt::Horizontal ,"Ім'я");
           modelRating->setHeaderData(3,Qt::Horizontal ,"Бал");

            ui->tableRatings->setModel(modelRating);
            ui->tableRatings->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableRatings->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 13pt; }");
            ui->tableRatings->setEditTriggers(QAbstractItemView::NoEditTriggers );


    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }
}

void SelectCity::SearchName()
{
    if(obj->value("resp").toString()=="ok")
    {

        QModelIndex modelIndex;
        QStringList ArrRating=obj->value("data").toVariant().toStringList();
        modelRating=new QStandardItemModel(ArrRating.length()/4, 4, this);

            for (int row = 0; row < ArrRating.length()/4; ++row )
            {
                for(int col=0; col<4;++col)
                {
                    modelIndex=modelRating->index(row,col);
                    modelRating->setData(modelIndex,ArrRating[row*4+col]);
                    modelRating->setData(modelIndex, Qt::AlignLeft, Qt::TextForceLeftToRight);

                }

            }


           modelRating->setHeaderData(0,Qt::Horizontal ,"Група");
           modelRating->setHeaderData(1,Qt::Horizontal ,"Прізвище");
           modelRating->setHeaderData(2,Qt::Horizontal ,"Ім'я");
           modelRating->setHeaderData(3,Qt::Horizontal ,"Бал");

            ui->tableRatings->setModel(modelRating);
            ui->tableRatings->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableRatings->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 13pt; }");
            ui->tableRatings->setEditTriggers(QAbstractItemView::NoEditTriggers );


    }
    else
    {
        QMessageBox::critical(this, "Data error", obj->value("err").toString(), "Ok");
    }
}






void SelectCity::on_GetGroup_editingFinished()
{

    GroupSearch = (ui->GetGroup->text());

    QString GroupNum = QString("{\"operation\":\"searchGroup\",\"UNIVER\":\""+UniverList+"\", \"SPECIALTY\":\""+SpecialtyList+"\", \"COURSE\":\""+CourseList+"\",\"GROUP\":\""+GroupSearch+"\"}");
    socket->write(GroupNum.toUtf8());
    socket->waitForBytesWritten(1500);


    //qDebug()<<GroupNum;

}

void SelectCity::on_GetNameStudent_editingFinished()
{
    NameSearch = (ui->GetNameStudent->text());

    QString StudentName = QString("{\"operation\":\"searchStudent\",\"UNIVER\":\""+UniverList+"\", \"SPECIALTY\":\""+SpecialtyList+"\", \"COURSE\":\""+CourseList+"\",\"NAME\":\""+NameSearch+"\"}");
    socket->write(StudentName.toUtf8());
    socket->waitForBytesWritten(1500);

}
