#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "Variable.h"

class MemoryManager;
class VarStorage;
class QJSonValue;

class Structure : public Variable
{
public:
    Structure(QString name);
    Variable * getData(QString name);
    bool setData(QString value, QString name);
    void setData(Variable * value);
    QString getAddr();
private:
    MemoryManager * memory;
    VarStorage * dataList;
    void changeData(Variable * destiny, QString origin);
};

#endif // STRUCTURE_H
