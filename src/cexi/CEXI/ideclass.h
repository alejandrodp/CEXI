#ifndef IDECLASS_H
#define IDECLASS_H

#include <QMainWindow>

namespace Ui {
class IdeClass;
}

class IdeClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit IdeClass(QWidget *parent = 0);
    ~IdeClass();

private:
    Ui::IdeClass *ui;
};

#endif // IDECLASS_H
