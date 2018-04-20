#ifndef CEXI_IDE_H
#define CEXI_IDE_H

#include <QMainWindow>

namespace Ui {
class cexi_ide;
}

class QTcpSocket;

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

private:
    Ui::cexi_ide *ui;
    QString getLine();
    int lineCounter = 0;
    QTcpSocket * clientSocket;
    QString * ipAddress;
    int * port;
};

#endif // CEXI_IDE_H
