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
    void GetCity();


private slots:

    void on_BackSetCityButton_clicked();
    void on_BackSetUniversityButton_clicked();
    void on_BackSetSpecialtyButton_clicked();
    void on_BackSetCourseButton_clicked();
    void on_BackRatingsButton_clicked();
    void on_RefreshCity_clicked();
private:
    Ui::SelectCity *ui;
    QStringListModel* model;
    
   signals:
    void BackCityMenu();
};

#endif // SELECTCITY_H
