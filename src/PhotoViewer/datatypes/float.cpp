#include "datatypes/Float.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Float::Float(QString name)
    : Variable(name, "FLOAT", 4)
{
    valueAdrr = MemoryManager::getInstance()->allocate(size);

    *(static_cast<float *>(MemoryManager::getInstance()->dereference(valueAdrr))) = 0.00;
}

float * Float::getData()
{
    return static_cast<float *>(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Float::setData(float value)
{
    float * temp = static_cast<float *>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;

    initialized = true;
}

std::bitset<32> Float::getAdrr()
{
    return valueAdrr;
}

QString Float::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}
