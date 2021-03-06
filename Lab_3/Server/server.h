#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QList>
#include <QDebug>
//server stuff
#include <QTcpServer>
#include <QTcpSocket>
//JSON
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
//SQL
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();
    QByteArray recievedData;
    QList <QTcpSocket*> *connectedClients;
    QJsonDocument* jsnDoc;
    QJsonParseError* errJsn = new QJsonParseError();
    QJsonObject* obj;
    QSqlDatabase* db;
    QSqlQuery* query;

    QString Data;
    void decEndExec(QJsonDocument* doc, QTcpSocket* socket);
    void LogProc(QTcpSocket* socket);
    void RegProc(QTcpSocket* socket);
    void GetCity(QTcpSocket* socket);
    void GetUniver(QTcpSocket* socket);
    void GetSpecialty(QTcpSocket* socket);
    void GetCourse(QTcpSocket* socket);
    void GetRating(QTcpSocket* socket);
    void GroupSearch(QTcpSocket* socket);
    void NameSearch(QTcpSocket* socket);

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisc();
    void DataSend(QTcpSocket* socket, QString data);

};

#endif // SERVER_H
