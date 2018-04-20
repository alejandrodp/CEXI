#include "datatypes/Integer.h"
#include "MemoryManager/MemoryManager.h"
#include <QDebug>
#include <sstream>


Integer::Integer(QString name)
    : Variable(name, "INT", 4)
{
    varAddress = MemoryManager::getInstance()->allocate(size);

    *(static_cast<int *>(MemoryManager::getInstance()->dereference(varAddress))) = 0;

    initialized = true;

}

int * Integer::getData()
{
    return static_cast<int* >(MemoryManager::getInstance()->dereference(varAddress));
}

void Integer::setData(int value)
{
    int * temp = static_cast<int*>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;
    initialized = true;
}

std::bitset<32> Integer::getAdrr()
{
    return varAddress;
}

QString Integer::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}
