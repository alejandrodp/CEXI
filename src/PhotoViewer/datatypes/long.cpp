#include "datatypes/Long.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Long::Long(QString name)
    : Variable(name, "LONG", 8)
{
    valueAdrr = MemoryManager::getInstance()->allocate(size);

    *(static_cast<long *>(MemoryManager::getInstance()->dereference(valueAdrr))) = 0;
}

long * Long::getData()
{
    return static_cast<long *>(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Long::setData(long value)
{
    long * temp = static_cast<long *>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;

    initialized = true;
}

std::bitset<32> Long::getAdrr()
{
    return valueAdrr;
}

QString Long::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}
