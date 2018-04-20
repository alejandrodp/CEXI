#include "datatypes/Reference.h"
#include "MemoryManager/MemoryManager.h"
#include <sstream>
#include <string>
#include "structures/Lists/varstorage.h"

Reference::Reference(QString name)
    : Variable(name, "REFERENCE", 4)
{
    this->data = "";
    this->varAddress = MemoryManager::getInstance()->allocate(size);

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

void Reference::setData(std::bitset<32> valAddrr, QString varType)
{
    valAdrr = valAddrr;

    typeToRef = varType;

    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(valAdrr);

    data = QString::fromStdString(ss.str());

    initialized = true;
}

QString Reference::getValType()
{
    return typeToRef;
}

QString Reference::getMemAddr()
{
    std::stringstream ss;

    ss << MemoryManager::getInstance()->dereference(varAddress);

    return QString::fromStdString(ss.str());
}

std::bitset<32> Reference::getValCode()
{
    return valAdrr;
}

void Reference::setRefCopy(Reference *var)
{
    this->valAdrr = var->valAdrr;
    for(int i=0; i< var->refVarList->getSize(); i++){
        this->refVarList->AddEnd(var->refVarList->getValue(i));
        var->refVarList->getValue(i)->setRefVar(this);
    }
}



