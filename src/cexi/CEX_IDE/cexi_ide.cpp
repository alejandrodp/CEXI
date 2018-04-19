#include "cexi_ide.h"
#include "ui_cexi_ide.h"
#include <iostream>
#include <QTextBlock>
#include <QTextDocument>


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

QString cexi_ide::getLine()
{

    QTextDocument * editor = ui->plainTextEdit->document();
    QTextBlock textBlock = editor->findBlockByLineNumber(0);
    QString line = textBlock.text();

    return line;
}

void cexi_ide::on_pushButton_clicked()
{
    std::cout << getLine().toStdString() << std::endl;
}
