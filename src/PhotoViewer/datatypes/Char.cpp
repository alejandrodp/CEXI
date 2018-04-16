#include "datatypes/Char.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>


Char::Char(QString name)
    : Variable(name, "CHAR", 1)
{
    valueAdrr = MemoryManager::getInstance()->allocate(size);

    *(static_cast<char *>(MemoryManager::getInstance()->dereference(valueAdrr))) = '-';
}

char * Char::getData()
{
    return static_cast<char* >(MemoryManager::getInstance()->dereference(valueAdrr));
}

void Char::setData(char value)
{

    char * temp = static_cast<char*>(MemoryManager::getInstance()->dereference(valueAdrr));

    *temp = value;

    initialized = true;
}

std::bitset<32> Char::getAdrr()
{
    return valueAdrr;
}

QString Char::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valueAdrr);

    return QString::fromStdString(ss.str());
}

