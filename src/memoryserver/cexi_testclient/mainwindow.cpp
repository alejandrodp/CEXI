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
    if(!clientSocket->isOpen()){
        ui->serverConsole->appendPlainText("Client: Client is not open");
        return;
    }
    QJsonDocument doc;

    doc.setObject(dataToSend);

    QTextStream T(clientSocket);
    T << doc.toJson();
    clientSocket->flush();

    ui->serverConsole->appendPlainText("Client: " + QString::fromStdString(doc.toJson().toStdString()));
}

void MainWindow::on_button_addData_clicked()
{
    QString key = ui->lineEdit_key->text();
    QJsonDocument doc;
    QJsonObject obj;

    if(key == "1"){
        obj.insert("OPERATION", "DECLARATION");
        obj.insert("TYPE_TARGET", "LONG");
        obj.insert("NAME", "NUMBER1");

    }else if(key == "2"){
        obj.insert("OPERATION", "DECLARATION");
        obj.insert("TYPE_TARGET", "LONG");
        obj.insert("NAME", "NUMBER2");

    }else if(key == "3"){
        obj.insert("OPERATION", "DECLARATION");
        obj.insert("TYPE_TARGET", "LONG");
        obj.insert("NAME", "NUMBER3");

    }else if(key == "4"){
        obj.insert("OPERATION", "SCOPE");
        obj.insert("SIGNAL", "NEW");

    }else if(key == "5"){
        obj.insert("OPERATION", "DECLARATION");
        obj.insert("TYPE_TARGET", "INT");
        obj.insert("NAME", "NUM");

    }else if(key == "6"){
        obj.insert("OPERATION", "SCOPE");
        obj.insert("SIGNAL", "CLOSE");

    }else if(key == "7"){
        obj.insert("OPERATION", "END_PROGRAM");
    }

    dataToSend = obj;
    on_button_test_clicked();




    /*QString key = ui->lineEdit_key->text();
    QString value = ui->lineEdit_value->text();
    dataToSend.insert(key, value);

    QTableWidgetItem * keyPage;
    QTableWidgetItem * valuePage;
    QTableWidget * table = ui->tableWidget_jsonData;

    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    ui->tableWidget_jsonData->setRowCount(0);

    foreach (QString keyvar, dataToSend.keys()) {
        table->insertRow(table->rowCount());

        int ROW = table->rowCount() - 1;

        keyPage = new QTableWidgetItem(keyvar);
        keyPage->setFlags(keyPage->flags() ^ Qt::ItemIsEditable);

        valuePage = new QTableWidgetItem(dataToSend.value(keyvar).toString());
        valuePage->setFlags(keyPage->flags() ^ Qt::ItemIsEditable);

        table->setItem(ROW, 0, keyPage);
        table->setItem(ROW, 1, valuePage);
    }*/
}

void MainWindow::on_button_clearjson_clicked()
{
    dataToSend = QJsonObject();
    ui->tableWidget_jsonData->setRowCount(0);
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
}

void MainWindow::on_tableWidget_jsonData_cellDoubleClicked(int row, int column)
{
    QString key = ui->tableWidget_jsonData->item(row, 0)->text();

    dataToSend.remove(key);

    ui->tableWidget_jsonData->removeRow(row);
}
