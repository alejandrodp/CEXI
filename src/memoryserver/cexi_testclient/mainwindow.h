#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_closeApp_clicked();

    void on_button_connectServer_clicked();

    void on_button_test_clicked();

    void on_button_addData_clicked();

    void on_button_clearjson_clicked();

    void on_tableWidget_jsonData_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QTcpSocket * clientSocket;
    QJsonObject dataToSend;
};

#endif // MAINWINDOW_H
