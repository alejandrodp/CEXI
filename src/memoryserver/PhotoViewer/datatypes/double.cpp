#include "datatypes/Double.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Double::Double(QString name)
    : Variable(name, "DOUBLE", 8)
{
    varAddress = MemoryManager::getInstance()->allocate(size);

    *(static_cast<double *>(MemoryManager::getInstance()->dereference(varAddress))) = 0.0;
}

double * Double::getData()
{
    return static_cast<double *>(MemoryManager::getInstance()->dereference(varAddress));
}

void Double::setData(double value)
{
    double * temp = static_cast<double *>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;

    initialized = true;
}

std::bitset<32> Double::getAdrr()
{
    return varAddress;
}

QString Double::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}
