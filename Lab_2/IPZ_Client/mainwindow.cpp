#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);



    ui->stackedWidget->setCurrentIndex(0);
    createSocket();
    _SetCity=new SelectCity(socket,obj);
    ui->stackedWidget->addWidget(_SetCity);
    connect(_SetCity, SIGNAL(BackCityMenu()), this, SLOT(moveLoginMenu()));
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
    QString LogLine = ui->GetLogin->text();
    QString PassLine = ui->GetPass->text();
    QRegularExpression LogFormat("[a-zA-Z0-9\\_\\-\\.]{5,20}");
    QRegularExpression PassFormat("[a-zA-Z0-9\\_\\.]{5,20}");

    if (LogFormat.match(LogLine).capturedLength() >= 5 &&LogFormat.match(LogLine).capturedLength() <= 20 && LogFormat.match(LogLine).capturedLength() == LogLine.length())
        // if login format is correct
    {
        if (PassFormat.match(PassLine).capturedLength() >= 5 && PassFormat.match(PassLine).capturedLength() <= 20 && PassFormat.match(PassLine).capturedLength() == PassLine.length())
            // if pass format is correct
        {
            //read data from line edits and convert it to JSON format
            QString txtToSend = QString("{\"operation\":\"login\", \"log\":\"%1\", \"pass\":\"%2\"}").arg(ui->GetLogin->text()).arg(ui->GetPass->text());
            //send log and pass to server
            socket->write(txtToSend.toUtf8());
            socket->waitForBytesWritten(1500);


        }
        // if passs format is not correct
        else
        {
            QMessageBox::information(this,"Invalid format","Password can only contain latin letters, "
                                                           "numbers and characters \".\", \"_\" and must "
                                                           "be longer than 5 but less 20 characters");
        }
    }
    else
    {
        // check pass format
        if (PassFormat.match(PassLine).capturedLength() < 5 || PassFormat.match(PassLine).capturedLength() >20 || PassFormat.match(PassLine).capturedLength() != PassLine.length())
            // if password format is incorrect
        {
            QMessageBox::information(this,"Invalid format","Login can only contain latin letters, numbers "
                                                           "and characters \".\", \"_\", \"-\" and "
                                                           "must be longer than 5 but less 20 characters\n\n"

                                                           "Password can only contain latin letters, "
                                                           "numbers and characters \".\", \"_\" and must "
                                                           "be longer than 5 but less 20 characters");
        }

        else
        {
                QMessageBox::information(this,"Invalid format","Login can only contain latin letters, numbers "
                                                               "and characters \".\", \"_\", \"-\" and "
                                                               "must be longer than 5 but less 20 characters");
        }
    }

}
void MainWindow::on_RegisterWidgetButton_clicked()

{
    QString LogLine = ui->LoginRegisterWidget->text();
    QString PassLine = ui->PassRegisterWidget->text();
    QString ConfPassLine = ui->PassRegisterWidget->text();
    QRegularExpression LogFormat("[a-zA-Z0-9\\_\\-\\.]{5,20}");
    QRegularExpression PassFormat("[a-zA-Z0-9\\_\\.]{5,20}");
    QRegularExpression ConfPassFormat("[a-zA-Z0-9\\_\\.]{5,20}");

    if (LogFormat.match(LogLine).capturedLength() >= 5 &&LogFormat.match(LogLine).capturedLength() <= 20 && LogFormat.match(LogLine).capturedLength() == LogLine.length())
        // if login format is correct
    {
        if (PassFormat.match(PassLine).capturedLength() >= 5 && PassFormat.match(PassLine).capturedLength() <= 20 && PassFormat.match(PassLine).capturedLength() == PassLine.length())
            // if pass format is correct
        {
            if(ui->PassRegisterWidget->text()==ui->ConfirmPassRegisterWidget->text())
            {
                if(ui->PassRegisterWidget->text().length()!=0 && ui->ConfirmPassRegisterWidget->text().length()!=0){
                    //read data from line edits and convert it to JSON format
                    QString txtToSend = QString("{\"operation\":\"register\", \"log\":\"%1\", \"pass\":\"%2\", \"verific pass\": \"%3\"}").arg(ui->LoginRegisterWidget->text()).arg(ui->PassRegisterWidget->text()).arg(ui->ConfirmPassRegisterWidget->text());
                    //send log and pass to server
                    socket->write(txtToSend.toUtf8());
                    socket->waitForBytesWritten(1500);
                }
                else
                {
                    QMessageBox::information(this,"Invalid format","Password can only contain latin letters, "
                                                                   "numbers and characters \".\", \"_\" and must "
                                                                   "be longer than 5 but less 20 characters");
                }
            }
            else
            {
                QMessageBox::critical(this,"Error information","Passwords do not match . Please try again","Ok");
            }
        }
        else
        {
            QMessageBox::information(this,"Invalid format","Password can only contain latin letters, "
                                                           "numbers and characters \".\", \"_\" and must "
                                                           "be longer than 5 but less 20 characters");
        }
    }
    else
    {
        // check pass format
        if (PassFormat.match(PassLine).capturedLength() < 5 || PassFormat.match(PassLine).capturedLength() >20 || PassFormat.match(PassLine).capturedLength() != PassLine.length())
            // if password format is incorrect
        {
            QMessageBox::information(this,"Invalid format","Login can only contain latin letters, numbers "
                                                           "and characters \".\", \"_\", \"-\" and "
                                                           "must be longer than 5 but less 20 characters\n\n"

                                                           "Password can only contain latin letters, "
                                                           "numbers and characters \".\", \"_\" and must "
                                                           "be longer than 5 but less 20 characters");
        }

        else
        {
                QMessageBox::information(this,"Invalid format","Login can only contain latin letters, numbers "
                                                               "and characters \".\", \"_\", \"-\" and "
                                                               "must be longer than 5 but less 20 characters");
        }
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
    socket->connectToHost("194.44.192.53", 48130);

    //wait for connection to be established
    socket->waitForConnected(1500);
    qDebug()<<socket->state();
}

//reading from socket
void MainWindow::sockReady()
{

    if (socket->waitForConnected(1500))
        {
            recievedData += socket->readAll();
        }

        else
        {

            QMessageBox::critical(this,"Error information","Can not read data from server: Connection failed. Please restert the app","Ok");
            return;
        }

        QByteArray terminantWord = "DATAEND";
        int recDatLength = recievedData.length();

        for (int i = 1; i <= terminantWord.length(); ++i)
        {
            if (recievedData[recDatLength - i] != terminantWord[terminantWord.length() - i] || (recDatLength - i < 0))
            {
                return;
            }
        }

        recievedData.resize(recievedData.length() - terminantWord.length());
        *jsnDoc = QJsonDocument::fromJson(recievedData, errJsn);

        recievedData.clear();
        *obj = jsnDoc->object();

        if (errJsn->error == QJsonParseError::NoError)
        {
            decEndExec();
            return;
        }

        else
        {


            QMessageBox::critical(this,"Error information","Can not convert data from server. Please restert the app","Ok");
            return;
        }






}

bool MainWindow::TryReccon()
{
    bool reconnRepl = 1;
    while (reconnRepl == 1)
    {
        // try to recconect to server
        socket->connectToHost("194.44.192.53", 48130);

        // wait for connection to be established
        socket->waitForConnected(5000);

        // if client is not connected reconnect
        if (socket->state() != QTcpSocket::ConnectedState)
        {
            // create msf box
            // ask if user want to try to connect again
            QMessageBox recMsgBox;
            recMsgBox.setWindowTitle("Connection with server lost");
            recMsgBox.setInformativeText("Unable connect to server. Do u want to try again?");
            recMsgBox.addButton("Yes", QMessageBox::YesRole);
            QAbstractButton* recNo = recMsgBox.addButton("Quit app", QMessageBox::NoRole);
            recMsgBox.setIcon(QMessageBox::Question);
            recMsgBox.exec();
            if (recMsgBox.clickedButton() == recNo)
            {
                reconnRepl = 0;
            }
        }
        // if we connected
        else
        {
            // if connected returk true
            return 1;
        }
    }
    // if not connected and user dont want to try again
    return 0;
}




//disconnect from server event
void MainWindow::sockDisk()
{
    // if we user dont want to reconnect
    if (!TryReccon())
    {
        // if user dont want to reconnect
        qDebug()<<"Disconnected from server";
        socket->deleteLater();
        this->close();
    }
}




void MainWindow::decEndExec()
{
    qDebug()<<obj->value("operation").toString();
    // if it is respond to login process
    if (obj->value("operation").toString() == "login")
    {
        // call login funct
        LogProc();
    }
    // if it is respond to registration process
    else if (obj->value("operation").toString() == "register")
    {
        RegProc();
    }
    else if(obj->value("operation").toString() == "getCity")
    {
       _SetCity->GetCity();
    }
    else if(obj->value("operation").toString() == "getUniver")
    {
       _SetCity->GetUniver();
    }
    else if(obj->value("operation").toString() == "getSpecialty")
    {
       _SetCity->GetSpecialty();
    }
    else if(obj->value("operation").toString() == "getCourse")
    {
       _SetCity->GetCourse();
    }
    else if(obj->value("operation").toString() == "getRating")
    {
       _SetCity->GetRating();
    }
    else if(obj->value("operation").toString() == "searchGroup")
    {
       _SetCity->SearchGroup();
    }
    else if(obj->value("operation").toString() == "searchStudent")
    {
       _SetCity->SearchName();
    }
    // if server send unknown operation
    else
    {
        QMessageBox::critical(this, "Error information", "Something went wrong. Please check your internet connection", "Ok");
    }
}

void MainWindow::LogProc()
{
    // if log and pass are good
    if (obj->value("resp").toString() == "ok")
    {
        ui->stackedWidget->setCurrentWidget(_SetCity);

        QString CityList = QString("{\"operation\":\"getCity\"}");
        socket->write(CityList.toUtf8());
        socket->waitForBytesWritten(1500);
    }
    // if smt went wrong
    else
    {
        QMessageBox::critical(this, "Error information", obj->value("err").toString(), "Ok");
    }
}

void MainWindow::RegProc()
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



