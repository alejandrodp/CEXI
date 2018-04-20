#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <bitset>

class VarStorage;

class Variable
{
public:
    Variable(QString name, QString type, int size);
    Variable();
    int getSize(){return size;}
    QString getName(){return name;}
    QString getType(){return type;}
    bool isInitialized(){return initialized;}
    void setRefVar(Variable * var);
    void deleteRefVar(QString name);
    int getRefCount();
    Variable * getRefVar(int pos);
    std::bitset<32> getAddress()
    {
        return this->varAddress;
    }
protected:
    QString name;
    QString type;
    int size;
    bool initialized;
    VarStorage * refVarList;
    std::bitset<32> varAddress;

};

#endif // VARIABLE_H
