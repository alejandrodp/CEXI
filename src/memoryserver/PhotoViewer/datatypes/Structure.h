#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "Variable.h"

class MemoryManager;
class VarStorage;
class QJSonValue;
class QJsonArray;
class QJsonObject;

class Structure : public Variable
{
public:
    Structure(QString name);
    Variable * getData(QString name);
    bool setData(QString value, QString name);
    void setData(Variable * value);
    bool varAlreadyExists(QString name);
    void createStructure(Structure * origin);
    void copyStructure(Structure * origin);
    QString getMemAddr();
    void setDefault(bool var) {defaultBase = var;}
    bool isDefault(){return defaultBase;}
    QJsonArray getMembers();
private:
    MemoryManager * memory;
    VarStorage * dataList;
    bool defaultBase;
    void changeData(Variable * destiny, QString origin);
    void setNewMember(Variable * var);
    QJsonObject memberToJson(Variable * var);
};

#endif // STRUCTURE_H
