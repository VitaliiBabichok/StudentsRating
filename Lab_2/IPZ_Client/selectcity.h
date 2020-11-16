#ifndef SELECTCITY_H
#define SELECTCITY_H

#include <QDialog>


namespace Ui {
class SelectCity;
}

class SelectCity : public QDialog
{
    Q_OBJECT

public:
    explicit SelectCity(QWidget *parent = nullptr);
    ~SelectCity();

private slots:

    
    void on_BackSetCityButton_clicked();

    void on_BackSetUniversityButton_clicked();

    void on_BackSetSpecialtyButton_clicked();

    void on_BackSetCourseButton_clicked();

    void on_BackRatingsButton_clicked();

    void on_goUniversity_clicked();

    void on_goSpecialty_clicked();

    void on_goCourse_clicked();

    void on_goRating_clicked();

private:
    Ui::SelectCity *ui;
    
   signals:
    void BackCityMenu();
};

#endif // SELECTCITY_H
