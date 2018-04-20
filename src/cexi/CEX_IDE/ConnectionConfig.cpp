#include "ConnectionConfig.h"
#include "ui_ConnectionConfig.h"

ConnectionConfig::ConnectionConfig(QWidget *parent, QString * ip, int * port) :
    QDialog(parent),
    ui(new Ui::ConnectionConfig),
    ip(ip),
    port(port)
{
    ui->setupUi(this);
    ui->lineEdit_ipAddr->setText(*ip);
    ui->spinBox_portNumber->setValue(*port);
}

ConnectionConfig::~ConnectionConfig()
{
    delete ui;
}

void ConnectionConfig::on_button_accept_clicked()
{


}
