#ifndef CEXI_IDE_H
#define CEXI_IDE_H

#include <QMainWindow>

namespace Ui {
class cexi_ide;
}

class cexi_ide : public QMainWindow
{
    Q_OBJECT

public:
    explicit cexi_ide(QWidget *parent = 0);
    ~cexi_ide();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cexi_ide *ui;
    QString getLine();
};

#endif // CEXI_IDE_H
