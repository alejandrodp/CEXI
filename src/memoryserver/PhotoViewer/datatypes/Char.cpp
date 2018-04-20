#include "datatypes/Char.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Char::Char(QString name)
    : Variable(name, "CHAR", 1)
{
    varAddress = MemoryManager::getInstance()->allocate(size);
}

char * Char::getData()
{
    return static_cast<char* >(MemoryManager::getInstance()->dereference(varAddress));
}

void Char::setData(char value)
{

    char * temp = static_cast<char*>(MemoryManager::getInstance()->dereference(varAddress));

    *temp = value;
}

std::bitset<32> Char::getAdrr()
{
    return varAddress;
}

QString Char::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}

