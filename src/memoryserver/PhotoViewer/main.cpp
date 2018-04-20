#include "launcher.h"
#include <QApplication>
#include "MemoryViewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Launcher w;
    w.show();
    return a.exec();
}
