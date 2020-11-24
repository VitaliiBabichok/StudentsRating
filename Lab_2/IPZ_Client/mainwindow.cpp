#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&_SetCity);

    connect(&_SetCity, SIGNAL(BackCityMenu()), this, SLOT(moveLoginMenu()));

    createSocket();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RegisterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_BackRegisterWidget_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LoginButton_clicked()
{
    //read data from line edits and convert it to JSON format
    QString txtToSend = QString("{\"operation\":\"login\", \"log\":\"%1\", \"pass\":\"%2\"}").arg(ui->GetLogin->text()).arg(ui->GetPass->text());

    //send log and pass to server
    socket->write(txtToSend.toLocal8Bit());
    socket->waitForBytesWritten(1500);


}
void MainWindow::on_RegisterWidgetButton_clicked()
{
    if(ui->PassRegisterWidget->text()==ui->ConfirmPassRegisterWidget->text())
    {
        if(ui->PassRegisterWidget->text().length()!=0 && ui->ConfirmPassRegisterWidget->text().length()!=0){
            //read data from line edits and convert it to JSON format
            QString txtToSend = QString("{\"operation\":\"register\", \"log\":\"%1\", \"pass\":\"%2\", \"verific pass\": \"%3\"}").arg(ui->LoginRegisterWidget->text()).arg(ui->PassRegisterWidget->text()).arg(ui->ConfirmPassRegisterWidget->text());
            //send log and pass to server
            socket->write(txtToSend.toLocal8Bit());
            socket->waitForBytesWritten(1500);
        }
        else{
            QMessageBox::critical(this,"Error information","Passwords cannot be empty. Please try again","Ok");
        }
    }
    else{
        QMessageBox::critical(this,"Error information","Passwords do not match . Please try again","Ok");
    }
}


void MainWindow::moveLoginMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ExitButton_clicked()
{
    QMessageBox::StandardButton reply =  QMessageBox::question(this,"Exit",
     "Do you want to leave the program?",QMessageBox::Yes |  QMessageBox::No);
    if(reply== QMessageBox::Yes)
    {
        QApplication::quit();
    }

}

//creating and initializing socket
void MainWindow::createSocket()
{
    //create socket and connect signals
    socket = new QTcpSocket();
    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisk()));

    //init socket with ip and port of server
    socket->connectToHost("194.44.71.144", 48130);

    //wait for connection to be established
    socket->waitForConnected(1500);
}

//reading from socket
void MainWindow::sockReady()
{
    //wait for stable connection
    if(socket->waitForConnected(1500))
    {
        //read all data
        recievedData = socket->readAll();

        //create new JSON doc
        jsnDoc = new QJsonDocument();

        //convert recieved data to JSON format
        *jsnDoc = QJsonDocument::fromJson(recievedData, errJsn);

        //get JSON object from JSON document

        *obj = jsnDoc->object();

        //chack if convertion eas successful
        if(errJsn->errorString().toInt() == QJsonParseError::NoError)
        {
            //do smt accordin to command from server
            decEndExec();
            return;
        }
        //if data could not be converted to json
        else
        {
            //show can not convert err msg box
            QMessageBox::critical(this,"Error information","Something went wrong. Please restert the app","Ok");
            return;
        }
    }
    //if connecting failed
    else
    {
        //show bad connection error
        qDebug()<<"Can not read data from client: Connestion failed";
        return;
    }
}

//disconnect from server event
void MainWindow::sockDisk()
{
    //to do:try to recconect
    qDebug()<<"Disconnected from server";
    socket->deleteLater();
}

void MainWindow::decEndExec()
{
    // if it is respond to login process
    if (obj->value("operation").toString() == "login")
    {
        // call login funct
        logProc();
    }
    // if it is respond to registration process
    else if (obj->value("operation").toString() == "register")
    {
        regProc();
    }
    // if server send unknown operation
    else
    {
        QMessageBox::critical(this, "Error information", "Something went wrong. Please check your internet connection", "Ok");
    }
}

void MainWindow::logProc()
{
    // if log and pass are good
    if (obj->value("resp").toString() == "ok")
    {
        ui->stackedWidget->setCurrentWidget(&_SetCity);
    }
    // if smt went wrong
    else
    {
        QMessageBox::critical(this, "Error information", obj->value("err").toString(), "Ok");
    }
}

void MainWindow::regProc()
{
    // if registration is successful
    if (obj->value("resp").toString() == "ok")
    {
        // show msg and go to login menu
        QMessageBox::information(this, "Registration info", "Registration is successful. Now yoo can login");

        ui->stackedWidget->setCurrentIndex(0);
    }
    // if smt went wrong
    else
    {
        QMessageBox::critical(this, "Registration error", obj->value("err").toString(), "Ok");
    }
}
