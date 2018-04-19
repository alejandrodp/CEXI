#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H

#include "structures/Lists/Scope.h"
#include <QJsonObject>

class QString;
class QByteArray;
class MemoryManager;
class Reference;

class OperationsManager
{
public:
    QByteArray makeRequest(QByteArray text);
    static OperationsManager * getInstance();
private:
    OperationsManager();
    QByteArray selectOperation(QJsonObject object);
    int getTypeSize(QString type);
    QByteArray setStructMember(QJsonObject object);
    QByteArray declarationMode(QJsonObject object);
    QByteArray changingMode(QJsonObject object);
    Variable * searchVariable(QString name, QString type = "ANY");
    void setReferenceData(Reference * reference, Variable * varToPoint);
    QByteArray getMode(QJsonObject object);

    MemoryManager * memory;
    Scope scopes;
    static OperationsManager * instance;

};

#endif // OPERATIONSMANAGER_H
