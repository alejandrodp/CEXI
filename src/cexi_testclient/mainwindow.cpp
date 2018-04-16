#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    clientSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    connect(clientSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(clientSocket);
        ui->serverConsole->appendPlainText("Server: " + T.readAll());;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_closeApp_clicked()
{
    close();
}

void MainWindow::on_button_connectServer_clicked()
{
    clientSocket->connectToHost("localhost", 5555);
}

void MainWindow::on_button_test_clicked()
{
    QJsonDocument doc;
    QJsonObject object;
    int row = ui->listItem_availableMsg->currentRow();

    if(row > 8 && row <= 16){
        object.insert("OPERATION", "CHANGE");
    }else if(row > 16 && row <= 26)
        object.insert("OPERATION", "GET");
    switch (row) {
    case 0:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","INT");
        object.insert("NAME", "number");
        break;
    case 1:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","CHAR");
        object.insert("NAME", "letter");
        break;
    case 2:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","LONG");
        object.insert("NAME", "largo");
        break;
    case 3:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","DOUBLE");
        object.insert("NAME", "doble");
        break;
    case 4:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","FLOAT");
        object.insert("NAME", "flotante");
        break;
    case 5:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","BOOL");
        object.insert("NAME", "booleano");
        break;
    case 6:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","REFERENCE");
        object.insert("TYPE","INT");
        object.insert("NAME", "data");
        break;
    case 7:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","STRUCT");
        object.insert("NAME", "Node");
        object.insert("SIGNAL", "NEW");
        break;
    case 8:
        object.insert("OPERATION", "DECLARATION");
        object.insert("TYPE_TARGET","STRUCT");
        object.insert("SIGNAL", "END");
        break;
    case 9:
        object.insert("TYPE_TARGET", "INT");
        object.insert("NAME", "number");
        object.insert("VAL", 3);
        break;
    case 10:
        object.insert("TYPE_TARGET", "CHAR");
        object.insert("NAME", "letter");
        object.insert("VAL", "t");
        break;
    case 11:
        object.insert("TYPE_TARGET", "LONG");
        object.insert("NAME", "largo");
        object.insert("VAL", 12345);
        break;
    case 12:
        object.insert("TYPE_TARGET", "DOUBLE");
        object.insert("NAME", "doble");
        object.insert("VAL", 4.56234);
        break;
    case 13:
        object.insert("TYPE_TARGET", "FLOAT");
        object.insert("NAME", "flotante");
        object.insert("VAL", 2.67);
        break;
    case 14:
        object.insert("TYPE_TARGET", "BOOL");
        object.insert("NAME", "booleano");
        object.insert("VAL", true);
        break;
    case 15:
        object.insert("TYPE_TARGET", "REFERENCE");
        object.insert("NAME", "data");
        object.insert("VAR", "number");
        break;
    case 16:
        object.insert("TYPE_TARGET", "STRUCT");
        object.insert("NAME", "Node");
        object.insert("VAL", 23);
        object.insert("MEMBER", "number");
        break;
    case 17:
        object.insert("TYPE_TARGET", "INT");
        object.insert("NAME", "number");
        break;
    case 18:
        object.insert("TYPE_TARGET", "CHAR");
        object.insert("NAME", "letter");
        break;
    case 19:
        object.insert("TYPE_TARGET", "LONG");
        object.insert("NAME", "largo");
        break;
    case 20:
        object.insert("TYPE_TARGET", "DOUBLE");
        object.insert("NAME", "doble");
        break;
    case 21:
        object.insert("TYPE_TARGET", "FLOAT");
        object.insert("NAME", "flotante");
        break;
    case 22:
        object.insert("TYPE_TARGET", "BOOL");
        object.insert("NAME", "booleano");
        break;
    case 23:
        object.insert("TYPE_TARGET", "REFERENCE");
        object.insert("NAME", "data");
        break;
    case 24:
        object.insert("TYPE_TARGET", "STRUCT");
        object.insert("SIGNAL", "STRUCT");
        object.insert("NAME", "Node");
        break;
    case 25:
        object.insert("TYPE_TARGET", "STRUCT");
        object.insert("SIGNAL", "MEMBER");
        object.insert("NAME", "Node");
        object.insert("M_NAME", "number");
        break;
    case 26:
        object.insert("TYPE_TARGET", "STRUCT");
        object.insert("SIGNAL", "MEMBER");
        object.insert("NAME", "Node");
        object.insert("M_NAME", "flotante");
        break;
    default:
        break;
    }

    doc.setObject(object);

    QTextStream T(clientSocket);
    T << doc.toJson();
    clientSocket->flush();

    ui->serverConsole->appendPlainText("Client: " + QString::fromStdString(doc.toBinaryData().toStdString()));
}
