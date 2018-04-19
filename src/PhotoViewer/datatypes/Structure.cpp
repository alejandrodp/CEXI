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
#include <QDebug>

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
}

QString Structure::getAddr()
{
    Variable * var = dataList->getValue(0);

    if(var->getType() == "INT") return ((Integer *)var)->getMemAddr();
    if(var->getType() == "DOUBLE") return ((Double *)var)->getMemAddr();
    if(var->getType() == "FLOAT") return ((Float *)var)->getMemAddr();
    if(var->getType() == "LONG") return ((Long *)var)->getMemAddr();
    if(var->getType() == "BOOL") return ((Booleano *)var)->getMemAddr();
    if(var->getType() == "CHAR") return ((Char *)var)->getMemAddr();
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
        ((Double *)destiny)->setData(*(origin.toStdString().c_str()));
    }
}
