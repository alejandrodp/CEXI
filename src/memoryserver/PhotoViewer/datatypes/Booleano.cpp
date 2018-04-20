#include "Booleano.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>

Booleano::Booleano(QString name)
    : Variable(name, "BOOL", 1)
{
      varAddress = MemoryManager::getInstance()->allocate(size);

      *(static_cast<bool *>(MemoryManager::getInstance()->dereference(varAddress))) = false;

}

bool *Booleano::getData()
{
    return static_cast<bool *>(MemoryManager::getInstance()->dereference(varAddress));
}

void Booleano::setData(bool value)
{

    bool * temp = static_cast<bool *>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;
    initialized = true;
}

std::bitset<32> Booleano::getAdrr()
{
    return varAddress;
}

QString Booleano::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}
