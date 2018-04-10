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
        ui->listItem_servMessages->addItem("Server: " + T.readAll());
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
    object.insert("OPERATION", "ASSIGNATION");
    doc.setObject(object);

    QTextStream T(clientSocket);
    T << doc.toJson();
    clientSocket->flush();
}
