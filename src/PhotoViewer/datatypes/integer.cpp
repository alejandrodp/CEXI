#include "datatypes/Integer.h"
#include "MemoryManager/MemoryManager.h"
#include <QDebug>
#include <sstream>


Integer::Integer(QString name)
    : Variable(name, "INT", 4)
{
    valueAdrr = MemoryManager::getInstance()->allocate(size);

    *(static_cast<int *>(MemoryManager::getInstance()->dereference(valueAdrr))) = 0;

    initialized = true;

}

int * Integer::getData()
{
    return static_cast<int* >(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Integer::setData(int value)
{
    int * temp = static_cast<int*>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;
    initialized = true;
}

std::bitset<32> Integer::getAdrr()
{
    return valueAdrr;
}

QString Integer::getMemAddr()
{
    std::stringstream ss;

    //ss << MemoryManager::getInstance()->dereference(valueAdrr);
    MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}
