#include "cexi_ide.h"
#include "ui_cexi_ide.h"

cexi_ide::cexi_ide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cexi_ide)
{
    ui->setupUi(this);
}

cexi_ide::~cexi_ide()
{
    delete ui;
}
