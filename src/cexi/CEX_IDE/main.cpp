#include "cexi_ide.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cexi_ide w;
    w.show();

    return a.exec();
}
