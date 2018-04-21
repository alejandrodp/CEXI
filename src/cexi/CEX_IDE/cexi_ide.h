#ifndef CEXI_IDE_H
#define CEXI_IDE_H

#include <QMainWindow>
#include "../interpreter/interpreter.h"

namespace Ui {
class cexi_ide;
}

class QTcpSocket;
class ConnectionConfig;

class cexi_ide : public QMainWindow
{
    Q_OBJECT

public:
    explicit cexi_ide(QWidget *parent = 0);
    ~cexi_ide();

private slots:

    void on_plainText_editor_cursorPositionChanged();

    void on_plainText_editor_textChanged();

    void on_actionServer_memory_triggered();

    void on_button_start_clicked();

    void on_button_connect_clicked();
    
    void on_button_step_clicked();
    
private:
    Ui::cexi_ide *ui;
    QString getLine();
    int lineCounter = 0;
    QTcpSocket * clientSocket;
    QString * ipAddress;
    int * port;
    ConnectionConfig * serverConfig;
    bool started;
    Interpreter interpreter;
    
};

#endif // CEXI_IDE_H
