#include "server.h"

Server::Server()
{
    //sreate connected clients list
    connectedClients = new QList <QTcpSocket*>();
};

Server::~Server() {}

//start server and make it listening local ip
void Server::startServer()
{
    QHostAddress _adress("127.0.0.1");

    //check if server started
    if(this->listen(_adress, 48130))
    {
        qDebug()<<"Server listening to: "<<_adress;

        //connect to db
        QString ServerName = "DESKTOP-N02R5KV";
        QString dbName = "RatingList";
        db = new QSqlDatabase();
        *db = QSqlDatabase::addDatabase("QODBC");
        QString dsn =QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=Yes;").arg(ServerName).arg(dbName);
        db->setDatabaseName(dsn);
        if(db->open())
        {
            qDebug()<<"Database opened";

            query = new QSqlQuery(*db);
        }
        else
        {
            qDebug()<<"Database not opened with ERROR: "<<db->lastError().text();
        }
    }
    else
    {
        qDebug()<<"Server NOT listening to:"<<_adress;
    }
}

//to handle disconnection from server
void Server::sockDisc()
{
    //create new socket (just to make code more readeble)
    QTcpSocket* socket;
    socket =new QTcpSocket();
    socket = qobject_cast<QTcpSocket*>(sender());
    qDebug()<<"Disconected";
    socket->deleteLater();
}

//gets executed when new client connects to server
void Server::incomingConnection(qintptr socketDescriptor)
{
    //create new socket (just to make code more readeble)
    QTcpSocket* socket;
    socket =new QTcpSocket();

    //set uniqe descriptor to client to be able to identify it later
    socket->setSocketDescriptor(socketDescriptor);

    //add client to list of connected clients
    connectedClients->append(socket);
    connect(socket,SIGNAL(readyRead()),this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(sockDisc()));

    qDebug()<<"Client is connected"<<"   "<<socketDescriptor;
}

//this func gets exec when server recieve smt from client
void Server::sockReady()
{
    //create new socket (just to make code more readeble)
    QTcpSocket* socket;
    socket =new QTcpSocket();

    //detect sender info
    socket = qobject_cast<QTcpSocket*>(sender());

    //wait for stable connection
    if(socket->waitForConnected(1500))
    {
        //read all data
        recievedData = socket->readAll();
        qDebug()<<"user send "<<recievedData;
        //create new JSON doc
        jsnDoc = new QJsonDocument();

        //convert recieved data to JSON format
        *jsnDoc = QJsonDocument::fromJson(recievedData, errJsn);

        //chack if convertion eas successful
        if(errJsn->errorString().toInt() == QJsonParseError::NoError)
        {
            //do smt accordin to command from client
            decEndExec(jsnDoc, socket);
            return;
        }
        //if data could not be converted to json
        else
        {
            //send client respond about bad data format
            socket->write("{\"operation\":\"convetrion to JSON\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
            socket->waitForBytesWritten(1500);
            return;
        }
    }
    //if connecting failed
    else
    {
        qDebug()<<"Can not read data from client: Connestion failed";
        return;
    }
}



//find what command does client send and do needed things to execute it
void Server::decEndExec(QJsonDocument* doc, QTcpSocket* socket)
{
    obj = new QJsonObject;
    *obj = doc->object();

    // when client try to login
    if (obj->value("operation") == "login")
    {
        // call login func
        LogProc(socket);
    }
    // new user registration
    else if (obj->value("operation") == "register")
    {
        // call registration func
        RegProc(socket);
    }
    else if(obj->value("operation") == "getCity")
    {
        GetCity(socket);
    }
    else if(obj->value("operation") == "getUniver")
    {
        GetUniver(socket);
    }
    else if(obj->value("operation") == "getSpecialty")
    {
        GetSpecialty(socket);
    }
    else if(obj->value("operation") == "getCourse")
    {
        GetCourse(socket);
    }
    else if(obj->value("operation") == "getRating")
    {
        GetRating(socket);
    }
    else if(obj->value("operation") == "searchGroup")
    {
        GroupSearch(socket);
    }
    else if(obj->value("operation") == "searchStudent")
    {
        NameSearch(socket);
    }

    // if we dont know command that client send
    else
    {
        // send to cliend command error msg
        socket->write("{\"operation\":\"not exist\"}");
        socket->waitForBytesWritten(1500);
    }
};

void Server::LogProc(QTcpSocket* socket)
{
    // find log in database
    query->prepare("select * from UserInfo where UserLog = :log");
    query->bindValue(":log", obj->value("log").toString());

    // if qry is not empty (if log exist)
    if (query->exec())
    {
        if (query->next())
        {
            // if password is correct
            if (query->value(1).toString() == obj->value("pass").toString())
            {
                // return validation is ok respond to client
                socket->write("{\"operation\":\"login\", \"resp\":\"ok\"}");
                socket->waitForBytesWritten(1500);

            }
            // if password is not correct
            else
            {
                // send invalid password respond to client
                socket->write("{\"operation\":\"login\", \"resp\":\"bad\", \"err\":\"Invalid password\"}");
                socket->waitForBytesWritten(1500);
            }
        }
        // qry is empty so login does not exist
        else
        {
            // send no such login respond to client
            socket->write("{\"operation\":\"login\", \"resp\":\"bad\", \"err\":\"Login doesn't exist\"}");
            socket->waitForBytesWritten(1500);
        }
    }
    else
    {
        // handle bad query execution
        socket->write("{\"operation\":\"login\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::RegProc(QTcpSocket *socket )
{
    // find log in database
    query->prepare("select * from UserInfo where UserLog = :log");
    query->bindValue(":log", obj->value("log").toString());

    if (query->exec())
    {
        // if qry is not empty (if log exist)
        if (query->next())
        {
            // send user already exist password respond to client
            socket->write("{\"operation\":\"register\", \"resp\":\"bad\", \"err\":\"User already exist\"}");
            socket->waitForBytesWritten(1500);
        }
        // qry is empty so login does not exist
        else
        {
            // insert login and password to database
            query->prepare("insert into UserInfo (UserLog, UserPass) values (:log, :pass)");
            query->bindValue(":log", obj->value("log").toString());
            query->bindValue(":pass", obj->value("pass").toString());

            // if registration successful
            if (query->exec())
            {
                // send good respond
                socket->write("{\"operation\":\"register\", \"resp\":\"ok\"}");
                socket->waitForBytesWritten(1500);
            }
            else
            {
                // set smt went wrong respond
                socket->write("{\"operation\":\"register\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
                socket->waitForBytesWritten(1500);
            }
        }
    }
    else
    {
        // handle bad query execution
        socket->write("{\"operation\":\"register\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GetCity(QTcpSocket *socket)
{
    if(query->exec("select * From CityInfo"))
    {
        QString respon="{\"operation\":\"getCity\", \"resp\":\"ok\", \"data\":[";
        while(query->next())
        {
              respon.append("\""+query->value(0).toString()+"\",");
        }
        respon.remove(respon.length()-1,1);
        respon.append("]}");

        socket->write(respon.toUtf8());
        socket->waitForBytesWritten(1500);
        qDebug()<<respon;
    }
    else
    {
        // eror bad connect
        socket->write("{\"operation\":\"getCity\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GetUniver(QTcpSocket *socket)
{
    query->prepare("select * From UniverInfo Where NameCity=:City");
    query->bindValue(":City",obj->value("CITY").toString());
    if(query->exec())
    {
        QString UniverList="{\"operation\":\"getUniver\", \"resp\":\"ok\", \"data\":[";
        while(query->next())
        {
              UniverList.append("\""+query->value(1).toString()+"\",");
        }
        UniverList.remove(UniverList.length()-1,1);
        UniverList.append("]}");

        socket->write(UniverList.toUtf8());
        socket->waitForBytesWritten(1500);
        qDebug()<<UniverList;
    }
    else
    {
        // eror bad connect
        socket->write("{\"operation\":\"getUniver\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GetSpecialty(QTcpSocket *socket)
{
    query->prepare("SELECT NameSpecialty From RatingList Where NameUniver=:Univer Group by NameSpecialty ");
    query->bindValue(":Univer",obj->value("UNIVER").toString());
    if(query->exec())
    {
        QString SpecialtyList="{\"operation\":\"getSpecialty\", \"resp\":\"ok\", \"data\":[";
        while(query->next())
        {
              SpecialtyList.append("\""+query->value(0).toString()+"\",");
        }
        SpecialtyList.remove(SpecialtyList.length()-1,1);
        SpecialtyList.append("]}");

        socket->write(SpecialtyList.toUtf8());
        socket->waitForBytesWritten(1500);
        qDebug()<<SpecialtyList;
    }
    else
    {
        // eror bad connect
        socket->write("{\"operation\":\"getSpecialty\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GetCourse(QTcpSocket *socket)
{
    query->prepare("SELECT CourseNum From RatingList Where NameSpecialty=:Specialty Group by CourseNum ");
    query->bindValue(":Specialty",obj->value("SPECIALTY").toString());
    if(query->exec())
    {
        QString CourseList="{\"operation\":\"getCourse\", \"resp\":\"ok\", \"data\":[";
        while(query->next())
        {
              CourseList.append("\""+query->value(0).toString()+"\",");
        }
        CourseList.remove(CourseList.length()-1,1);
        CourseList.append("]}");

        socket->write(CourseList.toUtf8());
        socket->waitForBytesWritten(1500);
        qDebug()<<CourseList;
    }
    else
    {
        // eror bad connect
        socket->write("{\"operation\":\"getCourse\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GetRating(QTcpSocket *socket)
{
    query->prepare(" Select GroupNum, LastNameStudent,FirstNameStudent, RatingMark From RatingList Where NameUniver=:Univer and NameSpecialty=:Specialty and CourseNum =:Course Order by RatingMark DESC ");

    query->bindValue(":Univer",obj->value("UNIVER").toString());
     query->bindValue(":Specialty",obj->value("SPECIALTY").toString());
     query->bindValue(":Course",obj->value("COURSE").toString());

    if(query->exec())
    {
        QString RatingTable="{\"operation\":\"getRating\", \"resp\":\"ok\", \"data\":[";
        while(query->next())
        {
            for(int i=0; i<=3;++i)
            {
              RatingTable.append("\""+query->value(i).toString()+"\",");
            }
        }
        RatingTable.remove(RatingTable.length()-1,1);
        RatingTable.append("]}");

        socket->write(RatingTable.toUtf8());
        socket->waitForBytesWritten(1500);
        qDebug()<<RatingTable;
    }
    else
    {
        // eror bad connect
        socket->write("{\"operation\":\"getRating\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
        socket->waitForBytesWritten(1500);
    }
}

void Server::GroupSearch(QTcpSocket *socket)
{
    query->prepare(" Select GroupNum, LastNameStudent,FirstNameStudent, RatingMark From RatingList Where NameUniver=:Univer and NameSpecialty=:Specialty and CourseNum =:Course and GroupNum=:Group Order by RatingMark DESC ");

    query->bindValue(":Univer",obj->value("UNIVER").toString());
     query->bindValue(":Specialty",obj->value("SPECIALTY").toString());
     query->bindValue(":Course",obj->value("COURSE").toString());
     query->bindValue(":Group",obj->value("GROUP").toString());
     if(query->exec())
     { int total=0;
         QString RatingTable="{\"operation\":\"searchGroup\", \"resp\":\"ok\", \"data\":[";
         while(query->next())
         {
             for(int i=0; i<=3;++i,++total)
             {
               RatingTable.append("\""+query->value(i).toString()+"\",");
             }

         }
         if(total)
         RatingTable.remove(RatingTable.length()-1,1);
         RatingTable.append("]}");

         socket->write(RatingTable.toUtf8());
         socket->waitForBytesWritten(1500);
         qDebug()<<RatingTable;
     }
     else
     {
         // eror bad connect
         socket->write("{\"operation\":\"searchGroup\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
         socket->waitForBytesWritten(1500);
     }

}

void Server::NameSearch(QTcpSocket *socket)
{
    query->prepare(" Select GroupNum, LastNameStudent,FirstNameStudent, RatingMark From RatingList Where NameUniver=:Univer and NameSpecialty=:Specialty and CourseNum =:Course and FirstNameStudent=:Name Order by RatingMark DESC ");

    query->bindValue(":Univer",obj->value("UNIVER").toString());
     query->bindValue(":Specialty",obj->value("SPECIALTY").toString());
     query->bindValue(":Course",obj->value("COURSE").toString());
     query->bindValue(":Name",obj->value("NAME").toString());
     if(query->exec())
     { int total=0;
         QString RatingTable="{\"operation\":\"searchStudent\", \"resp\":\"ok\", \"data\":[";
         while(query->next())
         {
             for(int i=0; i<=3;++i,++total)
             {
               RatingTable.append("\""+query->value(i).toString()+"\",");
             }

         }
         if(total)
         RatingTable.remove(RatingTable.length()-1,1);
         RatingTable.append("]}");

         socket->write(RatingTable.toUtf8());
         socket->waitForBytesWritten(1500);
         qDebug()<<RatingTable;
     }
     else
     {
         // eror bad connect
         socket->write("{\"operation\":\"searchStudent\", \"resp\":\"bad\", \"err\":\"Something went wrong when transfering data. Please check your internet connection\"}");
         socket->waitForBytesWritten(1500);
     }

}


