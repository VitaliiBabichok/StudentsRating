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

private:
    Ui::SelectCity *ui;
    
   signals:
    void BackCityMenu();
};

#endif // SELECTCITY_H
