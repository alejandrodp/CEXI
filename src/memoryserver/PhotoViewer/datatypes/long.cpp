#include "datatypes/Long.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Long::Long(QString name)
    : Variable(name, "LONG", 8)
{
    varAddress = MemoryManager::getInstance()->allocate(size);

    *(static_cast<long *>(MemoryManager::getInstance()->dereference(varAddress))) = 0;
}

long * Long::getData()
{
    return static_cast<long *>(MemoryManager::getInstance()->dereference(varAddress));
}

void Long::setData(long value)
{
    long * temp = static_cast<long *>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;

    initialized = true;
}

std::bitset<32> Long::getAdrr()
{
    return varAddress;
}

QString Long::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}
