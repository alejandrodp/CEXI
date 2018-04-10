#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QTcpSocket * clientSocket;
};

#endif // MAINWINDOW_H
