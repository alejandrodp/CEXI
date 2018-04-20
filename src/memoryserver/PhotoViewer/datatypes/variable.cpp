#include "datatypes/Variable.h"
#include "structures/Lists/varstorage.h"

Variable::Variable(QString name, QString type, int size)
    :name(name), type(type), size(size), initialized(false), refVarList(new VarStorage)
{

}

Variable::Variable()
    : name(""), type(""), size(0), initialized(false), refVarList(new VarStorage)
{

}

void Variable::setRefVar(Variable * var)
{
    refVarList->AddEnd(var);
}

void Variable::deleteRefVar(QString name)
{
    for(int i=0; i< refVarList->getSize(); i++){
        if(refVarList->getValue(i)->getName() == name){
            refVarList->deleteElm(i);
        }
    }
}

int Variable::getRefCount()
{
    return refVarList->getSize();
}

Variable *Variable::getRefVar(int pos)
{
    return refVarList->getValue(pos);
}
