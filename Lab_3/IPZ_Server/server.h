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
    void decEndExec(QJsonDocument* doc, QTcpSocket* socket);

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisc();

};

#endif // SERVER_H
