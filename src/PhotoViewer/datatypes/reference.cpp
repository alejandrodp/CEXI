#include "datatypes/Reference.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>

Reference::Reference(QString name, QString varTypeToPoint)
    : Variable(name, "REFERENCE", 4), typeToRef(varTypeToPoint)
{
    this->data = "";
}

QString Reference::getValAdrr()
{
    return this->data;
}

void *Reference::getVal()
{
    if(!initialized) return nullptr;

    return MemoryManager::getInstance()->dereference(valAdrr);
}

void Reference::setData(std::bitset<32> valAddrr)
{
    valAdrr = valAddrr;

    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valAdrr);

    data = QString::fromStdString(ss.str());

    initialized = true;
}



