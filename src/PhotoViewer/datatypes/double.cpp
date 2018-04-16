#include "datatypes/Double.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Double::Double(QString name)
    : Variable(name, "DOUBLE", 8)
{
    valueAdrr = MemoryManager::getInstance()->allocate(size);

    *(static_cast<double *>(MemoryManager::getInstance()->dereference(valueAdrr))) = 0.0;
}

double * Double::getData()
{
    return static_cast<double *>(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Double::setData(double value)
{
    double * temp = static_cast<double *>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;

    initialized = true;
}

std::bitset<32> Double::getAdrr()
{
    return valueAdrr;
}

QString Double::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}
