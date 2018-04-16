#include "OperationsManager.h"
#include "MemoryManager/MemoryManager.h"
#include "MemoryViewer.h"
#include <QObject>
#include <QJsonDocument>
#include <QTextStream>
#include <QDebug>
#include <bitset>
#include <QDebug>
#include <iostream>
#include "datatypes/Booleano.h"
#include "datatypes/Integer.h"
#include "datatypes/Array.h"
#include "datatypes/Char.h"
#include "datatypes/Double.h"
#include "datatypes/Float.h"
#include "datatypes/Long.h"
#include "datatypes/Reference.h"
#include "datatypes/Structure.h"

bool isStructBegin = false;
OperationsManager * OperationsManager::instance = nullptr;
OperationsManager::OperationsManager()
    : memory(MemoryManager::getInstance())
{
    scopes.AddNew();
}

QByteArray OperationsManager::makeRequest(QByteArray req)
{
    QJsonDocument doc = QJsonDocument::fromJson(req);
    QJsonObject object;
    if(doc.isNull()){
        object.insert("RESULT", "BAD_MSG");
        doc.setObject(object);
        return doc.toJson();
    }else if(!doc.isObject()){
        object.insert("RESULT", "BAD_JSON");
        doc.setObject(object);
        return doc.toJson();
    }else{
        object = doc.object();
    }

    return selectOperation(object);


}

OperationsManager * OperationsManager::getInstance()
{
    if(instance == nullptr) instance = new OperationsManager;
    return instance;

}

QByteArray OperationsManager::selectOperation(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QString operation = object.value("OPERATION").toString();

    if(operation == "DECLARATION"){
        return declarationMode(object);
    }else if(operation == "GET"){
        return getMode(object);
    }else if(operation == "CHANGE"){
        return changingMode(object);
    }else if(operation == "GET_ADDRESS"){

    }else if(operation == "GET_VAL"){

    }else if(operation == "SCOPE"){

    }else if(operation == "REPLACEMENT"){

    }else if(operation == "END_PROGRAM"){

    }else{
        response.insert("RESULT", "NO_OPERATION_DETECTED");
        doc.setObject(response);
        return doc.toJson();
    }
}

int OperationsManager::getTypeSize(QString type)
{
    if(type == "LONG") return 8;
    if(type == "INT") return 4;
    if(type == "FLOAT") return 4;
    if(type == "DOUBLE") return 8;
    if(type == "BOOL") return 8;
    if(type == "CHAR") return 1;
    if(type == "REFERENCE") return 4;
    if(type == "LONG") return 8;
    return 0;

}

QByteArray OperationsManager::setStructMember(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QString type_target = object.value("TYPE_TARGET").toString();

    if(type_target == "INT"){
        Integer * var = new Integer(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);
    }else if(type_target == "FLOAT"){
        Float * var = new Float(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "CHAR"){
        Char * var = new Char(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "DOUBLE"){
        Double * var = new Double(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "LONG"){
        Long * var = new Long(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "BOOL"){
        Booleano * var = new Booleano(object.value("NAME").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "REFERENCE"){
        Reference * var = new Reference(object.value("NAME").toString(), object.value("TYPE").toString());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "ARRAY"){
        Array * var = new Array(object.value("NAME").toString(), object.value("TYPE").toString(), object.value("SIZE").toInt());
        static_cast<Structure *>(scopes.getEndValue()->getEndElm())->setData(var);

    }else if(type_target == "STRUCT"){
        if(object.value("SIGNAL") == "END") isStructBegin = false;
        else response.insert("RESULT", "NEW_SIGNAL_ALREADY_SENDED");

    }else{
        response.insert("RESULT", "DATATYPE_UNDEFINED");
    }

    if(response.size() == 0) response.insert("RESULT", "OK");
    doc.setObject(response);
    return doc.toJson();
}

QByteArray OperationsManager::declarationMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QString type_target = object.value("TYPE_TARGET").toString();

    if(isStructBegin){
       return setStructMember(object);

    }else if(type_target == "INT"){
        Integer * var = new Integer(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "FLOAT"){
        Float * var = new Float(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "CHAR"){
        Char * var = new Char(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "DOUBLE"){
        Double * var = new Double(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "LONG"){
        Long * var = new Long(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "BOOL"){
        Booleano * var = new Booleano(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "REFERENCE"){
        Reference * var = new Reference(object.value("NAME").toString(), object.value("TYPE").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "STRUCT"){
        Structure * var = new Structure(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);
        if(object.value("SIGNAL") == "NEW") isStructBegin = true;

    }else if(type_target == "ARRAY"){
        Array * var = new Array(object.value("NAME").toString(), object.value("TYPE").toString(), object.value("SIZE").toInt());
        scopes.getEndValue()->AddEnd(var);
    }else{
        response.insert("RESULT", "DATATYPE_UNDEFINED");
    }
    if(response.size() == 0) response.insert("RESULT", "OK");
    doc.setObject(response);
    return doc.toJson();
}

QByteArray OperationsManager::changingMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    Variable * varTarget = searchVariable(object.value("NAME").toString());
    QString type_target = object.value("TYPE_TARGET").toString();

    if(varTarget == nullptr){
        response.insert("RESULT", "VAR_NOT_FOUND");
    }else if(type_target == "INT"){
        ((Integer *)varTarget)->setData(object.value("VAL").toInt());

    }else if(type_target == "FLOAT"){
        ((Float *)varTarget)->setData(object.value("VAL").toDouble());

    }else if(type_target == "CHAR"){
        ((Char *)varTarget)->setData(*(object.value("VAL").toString().toStdString().c_str()));

    }else if(type_target == "DOUBLE"){
        ((Double *)varTarget)->setData(object.value("VAL").toDouble());

    }else if(type_target == "LONG"){
        ((Long *)varTarget)->setData(object.value("VAL").toInt());

    }else if(type_target == "BOOL"){
        ((Booleano *)varTarget)->setData(object.value("VAL").toBool());

    }else if(type_target == "REFERENCE"){
        Variable * varSelected = searchVariable(object.value("VAR").toString());
        if(varSelected == nullptr) response.insert("RESULT", "NOT_VAL_TO_POINT");
        else setReferenceData((Reference *)varTarget, varSelected);

    }else if(type_target == "STRUCT"){
        ((Structure *)varTarget)->setData(object.value("VAL").toString(), object.value("MEMBER").toString());

    }else{
        response.insert("RESULT", "DATATYPE_UNDEFINED");
    }

    if(response.size() == 0) response.insert("RESULT", "OK");
    doc.setObject(response);
    return doc.toJson();
}

Variable *OperationsManager::searchVariable(QString name, QString type)
{
    VarStorage * storage;
    Variable * var;

    for(int scp=0; scp<scopes.getSize(); scp++){
        storage = scopes.getValue(scp);
        for(int stg=0; stg < storage->getSize(); stg++){
            var = storage->getValue(stg);
            if(var->getName() == name && type == "ANY") return var;
            if(var->getName() == name && var->getType() == type) return var;
        }
    }
    return nullptr;
}

void OperationsManager::setReferenceData(Reference *reference, Variable *varToPoint)
{
    QString type_target = varToPoint->getType();
    if(type_target == "INT"){
        reference->setData(((Integer *)varToPoint)->getAdrr());

    }else if(type_target == "FLOAT"){
        reference->setData(((Float *)varToPoint)->getAdrr());

    }else if(type_target == "CHAR"){
        reference->setData(((Char *)varToPoint)->getAdrr());

    }else if(type_target == "DOUBLE"){
        reference->setData(((Double *)varToPoint)->getAdrr());

    }else if(type_target == "LONG"){
        reference->setData(((Long *)varToPoint)->getAdrr());

    }else if(type_target == "BOOL"){
        reference->setData(((Booleano *)varToPoint)->getAdrr());
    }
}

QByteArray OperationsManager::getMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QString type_target = object.value("TYPE_TARGET").toString();

    Variable * varToSend = searchVariable(object.value("NAME").toString(), object.value("TYPE_TARGET").toString());

    if(varToSend == nullptr){
        response.insert("RESULT", "false");

    }else if(type_target == "INT"){
        response.insert("RESULT", "TRUE");
        int data = *(((Integer *)varToSend)->getData());
        response.insert("VALUE", QString::number(data));
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "FLOAT"){
        response.insert("RESULT", "TRUE");
        float data = *(((Float *)varToSend)->getData());
        response.insert("VALUE", QString::number(data));
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "CHAR"){
        response.insert("RESULT", "TRUE");
        char data = *(((Char *)varToSend)->getData());
        response.insert("VALUE", data);
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "DOUBLE"){
        response.insert("RESULT", "TRUE");
        double data = *(((Double *)varToSend)->getData());
        response.insert("VALUE", QString::number(data));
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "LONG"){
        response.insert("RESULT", "TRUE");
        long data = *(((Long *)varToSend)->getData());
        response.insert("VALUE", QString::number(data));
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "BOOL"){
        response.insert("RESULT", "TRUE");
        bool data = *(((Booleano *)varToSend)->getData());
        data ? response.insert("VALUE", "true") : response.insert("VALUE", "false");
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "REFERENCE"){
        response.insert("RESULT", "TRUE");
        QString data = ((Reference *)varToSend)->getValAdrr();
        response.insert("VALUE", data);
        response.insert("TYPE", varToSend->getType());

    }else if(type_target == "STRUCT"){
        response.insert("RESULT", "TRUE");
        if(object.value("SIGNAL").toString() == "MEMBER"){
            Variable * valueVar = ((Structure *)varToSend)->getData(response.value("M_NAME").toString());
            if(valueVar->getType() == "INT"){
                    response.insert("RESULT", "TRUE");
                    int data = *(((Integer *)valueVar)->getData());
                    response.insert("VALUE", QString::number(data));
                    response.insert("TYPE", valueVar->getType());

                }else if(valueVar->getType() == "FLOAT"){
                    response.insert("RESULT", "TRUE");
                    float data = *(((Float *)valueVar)->getData());
                    response.insert("VALUE", QString::number(data));
                    response.insert("TYPE", valueVar->getType());

                }else if(valueVar->getType() == "CHAR"){
                    response.insert("RESULT", "TRUE");
                    char data = *(((Char *)valueVar)->getData());
                    response.insert("VALUE", data);
                    response.insert("TYPE", valueVar->getType());

                }else if(valueVar->getType() == "DOUBLE"){
                    response.insert("RESULT", "TRUE");
                    double data = *(((Double *)valueVar)->getData());
                    response.insert("VALUE", QString::number(data));
                    response.insert("TYPE", valueVar->getType());

                }else if(valueVar->getType() == "LONG"){
                    response.insert("RESULT", "TRUE");
                    long data = *(((Long *)valueVar)->getData());
                    response.insert("VALUE", QString::number(data));
                    response.insert("TYPE", valueVar->getType());

                }else if(valueVar->getType() == "BOOL"){
                    response.insert("RESULT", "TRUE");
                    bool data = *(((Booleano *)valueVar)->getData());
                    data ? response.insert("VALUE", "true") : response.insert("VALUE", "false");
                    response.insert("TYPE", valueVar->getType());

                }
        }else if (object.value("SIGNAL").toString() == "STRUCT") {
            response.insert("RESULT", "TRUE");
            QString data = ((Structure *)varToSend)->getAddr();
            response.insert("VALUE", data);
            response.insert("TYPE", varToSend->getType());
        }
    }

    doc.setObject(response);
    return doc.toJson();
}


