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

private:
    Ui::cexi_ide *ui;
};

#endif // CEXI_IDE_H
