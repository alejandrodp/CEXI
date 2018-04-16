#ifndef ARRAY_H
#define ARRAY_H

#include "Variable.h"

class MemoryManager;
class VarStorage;

class Array : public Variable
{
private:
    VarStorage * dataList;
    MemoryManager * memory;
public:
    Array(QString name, QString type, int size);
    Variable * getData(int pos);
    void setData(QString value, int pos);
    int getQuantity();
};

#endif // ARRAY_H
