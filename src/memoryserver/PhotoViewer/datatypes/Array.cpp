#include "Array.h"
#include <QString>
#include "MemoryManager/MemoryManager.h"
#include "structures/Lists/varstorage.h"
#include "datatypes/Booleano.h"
#include "datatypes/Integer.h"
#include "datatypes/Array.h"
#include "datatypes/Char.h"
#include "datatypes/Double.h"
#include "datatypes/Float.h"
#include "datatypes/Long.h"

Array::Array(QString name, QString type, int size)
    : Variable(name, type, size), memory(MemoryManager::getInstance()), dataList(new VarStorage)
{

}

Variable * Array::getData(int pos){
    return dataList->getValue(pos);
}

void Array::setData(QString value, int pos){

    if(pos > size){
        return;
    }

    Variable * var = dataList->getValue(pos);

    if(type == "INT"){
        ((Integer *)var)->setData(value.toInt());
    }else if(type == "DOUBLE"){
        ((Double *)var)->setData(value.toDouble());

    }else if(type == "FLOAT"){
        ((Float *)var)->setData(value.toFloat());

    }else if(type == "LONG"){
        ((Long *)var)->setData(value.toLong());

    }else if(type == "BOOL"){
        ((Booleano *)var)->setData(value.toDouble());

    }else if(type == "CHAR"){
        ((Char *)var)->setData(*(value.toStdString().c_str()));

    }
}

int Array::getQuantity()
{
    if(type == "LONG") return 8 * size;
    if(type == "INT") return 4 * size;
    if(type == "FLOAT") return 4 * size;
    if(type == "DOUBLE") return 8 * size;
    if(type == "BOOL") return 8 * size;
    if(type == "CHAR") return size;
    if(type == "REFERENCE") return 4 * size;
    return 0;
}
