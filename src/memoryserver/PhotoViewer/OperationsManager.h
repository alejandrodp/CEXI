#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H

#include "structures/Lists/Scope.h"
#include <QJsonObject>
#include <QJsonArray>

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
    Variable * searchVariable(QString name, QString type = "ANY", QString inStruct = "FALSE", QString structure = "");
    void setReferenceData(Reference * reference, Variable * varToPoint);
    QByteArray getMode(QJsonObject object);
    bool variableAlreadyExists(QString name, bool isStruct = false);
    QByteArray getValMode(QJsonObject object);
    QByteArray getAddressMode(QJsonObject object);
    QByteArray replaceMode(QJsonObject object);
    QJsonArray varList();
    QJsonObject varToJson(Variable * var);
    void copyVariables(Variable * origin, Variable * destiny);
    QByteArray scopeMode(QJsonObject object);
    QByteArray endProgramMode();


    MemoryManager * memory;
    Scope scopes;
    static OperationsManager * instance;

};

#endif // OPERATIONSMANAGER_H
