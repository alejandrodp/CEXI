#include "ideclass.h"
#include "ui_ideclass.h"

IdeClass::IdeClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IdeClass)
{
    ui->setupUi(this);
}

IdeClass::~IdeClass()
{
    delete ui;
}
