#ifndef SELECTCITY_H
#define SELECTCITY_H

#include <QDialog>
#include<QTcpSocket>
#include <QTcpServer>
namespace Ui {
class SelectCity;
}

class SelectCity : public QDialog
{
    Q_OBJECT

public:
    explicit SelectCity(QTcpSocket *sock  , QWidget *parent = nullptr);
    ~SelectCity();
    QTcpSocket * socket;
private slots:

    void on_BackSetCityButton_clicked();
    void on_BackSetUniversityButton_clicked();
    void on_BackSetSpecialtyButton_clicked();
    void on_BackSetCourseButton_clicked();
    void on_BackRatingsButton_clicked();

private:
    Ui::SelectCity *ui;
    
   signals:
    void BackCityMenu();
};

#endif // SELECTCITY_H
