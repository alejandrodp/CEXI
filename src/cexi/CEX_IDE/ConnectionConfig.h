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
    explicit ConnectionConfig(QWidget *parent = 0, QString * ip, int * port);
    ~ConnectionConfig();

private slots:
    void on_button_accept_clicked();

private:
    Ui::ConnectionConfig *ui;
    QString * ip;
    int * port;
};

#endif // CONNECTIONCONFIG_H
