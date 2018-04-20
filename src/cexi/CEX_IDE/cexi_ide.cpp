#include "cexi_ide.h"
#include "ui_cexi_ide.h"
#include <iostream>
#include <QTextBlock>
#include <QTextDocument>
#include <QTcpSocket>
#include "ConnectionConfig.h"

cexi_ide::cexi_ide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cexi_ide),
    clientSocket(new QTcpSocket(this)),
    ipAddress(new QString("0.0.0.0")),
    port(new int(0)),
    serverConfig(new ConnectionConfig(this, ipAddress, port))
{
    ui->setupUi(this);
    connect(clientSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(clientSocket);
        if(T.readAll() == "CONNECTION SUCCESFUL"){
            ui->plainText_log->appendPlainText("Server: " + T.readAll());
            ui->label_connectionStatus->setText("Status: Connected");
        }
    });

    connect(serverConfig, &ConnectionConfig::serverConfig, [&](){
        ui->label_ipAddress->setText(*ipAddress);
        ui->label_port->setText(QString::number(*port));
    });
}

cexi_ide::~cexi_ide()
{
    delete ui;
}

QString cexi_ide::getLine()
{
    QPlainTextEdit * editor = ui->plainText_editor;
    QTextBlock textBlock = editor->document()->findBlockByLineNumber(lineCounter);
    QString line = textBlock.text();

    return line;
}

void cexi_ide::on_plainText_editor_cursorPositionChanged()
{
    int line = ui->plainText_editor->textCursor().blockNumber();
    int col = ui->plainText_editor->textCursor().columnNumber();

    ui->lineEdit_lineandcol->setText("Line: " + QString::number(line) + " | " + "Col: " + QString::number(col));
}

void cexi_ide::on_plainText_editor_textChanged()
{
    int line = ui->plainText_editor->textCursor().blockNumber();
    int col = ui->plainText_editor->textCursor().columnNumber();

    ui->lineEdit_lineandcol->setText("Line: " + QString::number(line) + " | " + "Col: " + QString::number(col));
}

void cexi_ide::on_actionServer_memory_triggered()
{

    serverConfig->show();
}

void cexi_ide::on_button_start_clicked()
{
    if(!clientSocket->isOpen()){
        ui->plainText_log->appendPlainText("Server is disconnected.");
    }
}

void cexi_ide::on_button_connect_clicked()
{
    clientSocket->connectToHost(*ipAddress, *port);
}
