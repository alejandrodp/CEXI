#include "datatypes/Float.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Float::Float(QString name)
    : Variable(name, "FLOAT", 4)
{
    varAddress = MemoryManager::getInstance()->allocate(size);

    *(static_cast<float *>(MemoryManager::getInstance()->dereference(varAddress))) = 0.00;
}

float * Float::getData()
{
    return static_cast<float *>(MemoryManager::getInstance()->dereference(varAddress));
}

void Float::setData(float value)
{
    float * temp = static_cast<float *>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;

    initialized = true;
}

std::bitset<32> Float::getAdrr()
{
    return varAddress;
}

QString Float::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}
