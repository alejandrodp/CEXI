#ifndef CONNECTIONCONFIG_H
#define CONNECTIONCONFIG_H

#include <QDialog>

namespace Ui {
class ConnectionConfig;
}

class ConnectionConfig : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionConfig(QWidget *parent = 0, QString * ip = new QString("localhost"), int * port = new int(5555));
    ~ConnectionConfig();

private slots:
    void on_button_accept_clicked();

    void on_button_cancel_clicked();

signals:
    void serverConfig();

private:
    Ui::ConnectionConfig *ui;
    QString * ip;
    int * port;
};

#endif // CONNECTIONCONFIG_H
