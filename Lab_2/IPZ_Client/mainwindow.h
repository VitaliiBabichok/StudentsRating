#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "selectcity.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RegisterButton_clicked();

    void on_BackRegisterWidget_clicked();

    void on_LoginButton_clicked();

    void moveLoginMenu();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
    SelectCity _SetCity;
};
#endif // MAINWINDOW_H
