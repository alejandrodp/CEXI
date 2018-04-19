#include "Booleano.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>

Booleano::Booleano(QString name)
    : Variable(name, "BOOL", 1)
{
      valueAdrr = MemoryManager::getInstance()->allocate(size);

      *(static_cast<bool *>(MemoryManager::getInstance()->dereference(valueAdrr))) = false;

}

bool *Booleano::getData()
{
    return static_cast<bool *>(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Booleano::setData(bool value)
{

    bool * temp = static_cast<bool *>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;
    initialized = true;
}

std::bitset<32> Booleano::getAdrr()
{
    return valueAdrr;
}

QString Booleano::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}
