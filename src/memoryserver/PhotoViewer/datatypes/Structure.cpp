#include "Structure.h"
#include "structures/Lists/varstorage.h"
#include "MemoryManager/MemoryManager.h"
#include <QJsonValue>
#include "datatypes/Booleano.h"
#include "datatypes/Integer.h"
#include "datatypes/Array.h"
#include "datatypes/Char.h"
#include "datatypes/Double.h"
#include "datatypes/Float.h"
#include "datatypes/Long.h"
#include <sstream>
#include <QJsonArray>
#include <QJsonObject>

Structure::Structure(QString name)
    : Variable(name, "STRUCT", 0), memory(MemoryManager::getInstance()), dataList(new VarStorage)
{

}

Variable * Structure::getData(QString name) {
    for(int i=0; i< dataList->getSize(); i++){
        if(dataList->getValue(i)->getName() == name){
            return dataList->getValue(i);
        }
    }
    return nullptr;
}

bool Structure::setData(QString value, QString name) {
    for(int i=0; i<dataList->getSize(); i++){
        if(dataList->getValue(i)->getName() == name){
            changeData(dataList->getValue(i), value);
        }
    }
    return true;
}

void Structure::setData(Variable * value)
{
    dataList->AddEnd(value);
    this->size += value->getSize();
}

bool Structure::varAlreadyExists(QString name)
{
    for(int i=0; i<dataList->getSize(); i++){
        if(dataList->getValue(i)->getName() == name){
            return true;
        }
    }
    return false;
}

void Structure::createStructure(Structure * origin)
{
    for(int i=0; i< origin->dataList->getSize(); i++){
        setNewMember(origin->dataList->getValue(i));
    }
    this->size = origin->size;
}

void Structure::copyStructure(Structure *origin)
{
    this->dataList = origin->dataList;
    this->setRefVar(origin);
    origin->setRefVar(this);

}

QString Structure::getMemAddr()
{
    if(dataList->getSize() == 0) return "";

    QString varType = dataList->getEndElm()->getType();

    if(varType == "INT"){
        return ((Integer *)dataList->getEndElm())->getMemAddr();

    }else if(varType == "DOUBLE"){
        return ((Double *)dataList->getEndElm())->getMemAddr();

    }else if(varType == "FLOAT"){
        return ((Float *)dataList->getEndElm())->getMemAddr();

    }else if(varType == "LONG"){
        return ((Long *)dataList->getEndElm())->getMemAddr();

    }else if(varType == "CHAR"){
        return ((Char *)dataList->getEndElm())->getMemAddr();
    }

    return "NON_TYPE_DETECTED";

}

QJsonArray Structure::getMembers()
{
    QJsonArray list;
    for(int i=0; i< dataList->getSize(); i++){
        list.append(memberToJson(dataList->getValue(i)));
    }

    return list;

}

void Structure::changeData(Variable * destiny, QString origin)
{
    if(destiny->getType() == "INT"){
        ((Integer *)destiny)->setData(origin.toInt());

    }else if(destiny->getType() == "DOUBLE"){
        ((Double *)destiny)->setData(origin.toDouble());

    }else if(destiny->getType() == "FLOAT"){
        ((Float *)destiny)->setData(origin.toDouble());

    }else if(destiny->getType() == "LONG"){
        ((Long *)destiny)->setData(origin.toLong());

    }else if(destiny->getType() == "CHAR"){
        ((Char *)destiny)->setData(*(origin.toStdString().c_str()));
    }
}

void Structure::setNewMember(Variable *var)
{
    if(var->getType() == "INT"){
        Integer * newVar = new Integer(var->getName());
        dataList->AddEnd(newVar);

    }else if(var->getType() == "FLOAT"){
        Float * newVar = new Float(var->getName());
        dataList->AddEnd(newVar);

    }else if(var->getType() == "DOUBLE"){
        Double * newVar = new Double(var->getName());
        dataList->AddEnd(newVar);

    }else if(var->getType() == "LONG"){
        Long * newVar = new Long(var->getName());
        dataList->AddEnd(newVar);

    }else if(var->getType() == "CHAR"){
        Char * newVar = new Char(var->getName());
        dataList->AddEnd(newVar);

    }
}

QJsonObject Structure::memberToJson(Variable * var)
{
    QJsonArray references;
    QJsonObject obj;
    obj.insert("NAME", var->getName());
    obj.insert("TYPE", var->getType());

    if(var->getType() == "INT"){
        Integer * value = (Integer * )var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "FLOAT"){
        Float * value = (Float *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "DOUBLE"){
        Double * value = (Double *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "LONG"){
        Long * value = (Long *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "CHAR"){
        Char * value = (Char *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        QString data(((Char *)value)->getData());
        obj.insert("VALUE", data);
        obj.insert("REF_COUNT", value->getRefCount());

    }

    for(int i=0; i < var->getRefCount(); i++){
        references.append(memberToJson(var->getRefVar(i)));
    }
    obj.insert("REFERENCES", references);

    return obj;
}
