#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
//communication with server related
#include <QTcpSocket>
//JSON
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
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
    QTcpSocket* socket;
    QByteArray recievedData;
    QJsonDocument* jsnDoc;
    QJsonParseError* errJsn = new QJsonParseError();
    QJsonObject* obj= new QJsonObject();
    void createSocket();    //create and init socket with IP and port number
    void decEndExec();
    void LogProc();
    void RegProc();
    bool TryReccon();
private slots:
    void on_RegisterButton_clicked();
    void on_BackRegisterWidget_clicked();
    void on_LoginButton_clicked();
    void moveLoginMenu();
    void on_ExitButton_clicked();
    void sockReady();   //reading from socket
    void sockDisk();    //disconnect from server event
    void on_RegisterWidgetButton_clicked();

private:
    Ui::MainWindow *ui;
    SelectCity _SetCity;
};
#endif // MAINWINDOW_H
