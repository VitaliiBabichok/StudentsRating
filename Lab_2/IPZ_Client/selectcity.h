#ifndef SELECTCITY_H
#define SELECTCITY_H

#include <QDialog>
#include<QTcpSocket>
#include <QTcpServer>
#include <QStringListModel>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>
#include <QStandardItemModel>

namespace Ui {
class SelectCity;
}

class SelectCity : public QDialog
{
    Q_OBJECT

public:
    explicit SelectCity(QTcpSocket *sock ,QJsonObject *object , QWidget *parent = nullptr);
    ~SelectCity();
    QJsonObject* obj= new QJsonObject();
    QTcpSocket * socket;
    QString UniverList;
    QString SpecialtyList;
    QString CourseList;
    QString GroupSearch;
    QString NameSearch;

    void GetCity();
    void GetUniver();
    void GetSpecialty();
    void GetCourse();
    void GetRating();
    void SearchGroup();
   void SearchName();

private slots:

    void on_BackSetCityButton_clicked();
    void on_BackSetUniversityButton_clicked();
    void on_BackSetSpecialtyButton_clicked();
    void on_BackSetCourseButton_clicked();
    void on_BackRatingsButton_clicked();
    void on_RefreshCity_clicked();


    void on_listCity_clicked(const QModelIndex &index);

   // void on_listUniver_clicked(const QModelIndex &index);



    void on_listUniver_clicked(const QModelIndex &index);



    void on_listSpecialty_clicked(const QModelIndex &index);

    void on_listCourse_clicked(const QModelIndex &index);

    void on_GetGroup_editingFinished();

    void on_GetNameStudent_editingFinished();

private:
    Ui::SelectCity *ui;
    QStringListModel* modelCity;
    QStringListModel* modelUniver;
    QStringListModel* modelSpecialty;
    QStringListModel* modelCourse;
    QStandardItemModel *modelRating;

    
   signals:
    void BackCityMenu();
};

#endif // SELECTCITY_H
