#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>

class Variable
{
public:
    Variable(QString name, QString type, int size)
        : name(name), type(type), size(size), initialized(false){}
    Variable(): name(""), type(""), size(0), initialized(false){}
    int getSize(){return size;}
    QString getName(){return name;}
    QString getType(){return type;}
    bool isInitialized(){return initialized;}
protected:
    QString name;
    QString type;
    int size;
    bool initialized;
};

#endif // VARIABLE_H
