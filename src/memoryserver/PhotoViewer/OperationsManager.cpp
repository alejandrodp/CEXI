#include "OperationsManager.h"
#include "MemoryManager/MemoryManager.h"
#include "MemoryViewer.h"
#include <QObject>
#include <QJsonDocument>
#include <QDebug>
#include <bitset>
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
#include <QJsonValue>
#include "MemoryManager/garbagecollector.h"

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
    QJsonArray msg;

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

    doc = QJsonDocument::fromJson(selectOperation(object));

    msg.append(doc.object());

    msg.append(varList());

    doc.setArray(msg);

    return doc.toJson();
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
        return getAddressMode(object);

    }else if(operation == "GET_VAL"){
        return getValMode(object);

    }else if(operation == "SCOPE"){
        return scopeMode(object);

    }else if(operation == "REPLACEMENT"){
        return replaceMode(object);

    }else if(operation == "END_PROGRAM"){
        return endProgramMode();

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

    if(variableAlreadyExists(object.value("NAME").toString(), true)){
        response.insert("RESULT", "MEMBER_ALREADY_EXISTS");

    }else if(type_target == "INT"){
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
        Reference * var = new Reference(object.value("NAME").toString());
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

    }else if(variableAlreadyExists(object.value("NAME").toString())){
        response.insert("RESULT", "VAR_ALREADY_EXISTS");

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
        Reference * var = new Reference(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);

    }else if(type_target == "STRUCT"){
        Structure * var = new Structure(object.value("NAME").toString());
        scopes.getEndValue()->AddEnd(var);
        if(object.value("SIGNAL") == "NEW"){
            isStructBegin = true;
            var->setDefault(true);
        }
        if(object.value("SIGNAL") == "VARIABLE"){
            var->createStructure((Structure *)searchVariable(object.value("ORIGIN").toString()));
            var->setDefault(false);
        }

    }else if(type_target == "ARRAY"){
        Array * var = new Array(object.value("NAME").toString(), object.value("TYPE").toString(), object.value("SIZE").toString().toInt());
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
        ((Integer *)varTarget)->setData(object.value("VAL").toString().toInt());

    }else if(type_target == "FLOAT"){
        ((Float *)varTarget)->setData(object.value("VAL").toString().toDouble());

    }else if(type_target == "CHAR"){
        ((Char *)varTarget)->setData(*(object.value("VAL").toString().toStdString().c_str()));

    }else if(type_target == "DOUBLE"){
        ((Double *)varTarget)->setData(object.value("VAL").toString().toDouble());

    }else if(type_target == "LONG"){
        ((Long *)varTarget)->setData(object.value("VAL").toString().toInt());

    }else if(type_target == "BOOL"){
        if(object.value("VAL").toString() == "true") ((Booleano *)varTarget)->setData(true);
        else ((Booleano *)varTarget)->setData(false);

    }else if(type_target == "REFERENCE"){
        if(object.value("IN_STRUCT").toString() == "TRUE"){
            if(searchVariable(object.value("STRUCT").toString())->getType() != "STRUCT"){
                response.insert("RESULT", "NOT_STRUCT");

            }
        }
        Variable * varSelected = searchVariable(object.value("VAR").toString(), "ANY" ,object.value("IN_STRUCT").toString(), object.value("STRUCT").toString());
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

Variable *OperationsManager::searchVariable(QString name, QString type, QString inStruct, QString structure)
{
    VarStorage * storage;
    Variable * var;

    if(inStruct == "TRUE"){
        for(int scp=0; scp<scopes.getSize(); scp++){
            storage = scopes.getValue(scp);
            for(int stg=0; stg < storage->getSize(); stg++){
                var = storage->getValue(stg);
                if(var->getName() == structure){
                    return ((Structure *)var)->getData(name);
                }
            }
        }
    }else{
        for(int scp=0; scp<scopes.getSize(); scp++){
            storage = scopes.getValue(scp);
            for(int stg=0; stg < storage->getSize(); stg++){
                var = storage->getValue(stg);
                if(var->getName() == name && type == "ANY") return var;
                if(var->getName() == name && var->getType() == type) return var;
            }
        }
    }
    return nullptr;
}

void OperationsManager::setReferenceData(Reference *reference, Variable *varToPoint)
{
    QString type_target = varToPoint->getType();
    if(type_target == "INT"){
        reference->setData(((Integer *)varToPoint)->getAdrr(), ((Integer *)varToPoint)->getType());

    }else if(type_target == "FLOAT"){
        reference->setData(((Float *)varToPoint)->getAdrr(), ((Float *)varToPoint)->getType());

    }else if(type_target == "CHAR"){
        reference->setData(((Char *)varToPoint)->getAdrr(), ((Char *)varToPoint)->getType());

    }else if(type_target == "DOUBLE"){
        reference->setData(((Double *)varToPoint)->getAdrr(), ((Double *)varToPoint)->getType());

    }else if(type_target == "LONG"){
        reference->setData(((Long *)varToPoint)->getAdrr(), ((Long *)varToPoint)->getType());

    }else if(type_target == "BOOL"){
        reference->setData(((Booleano *)varToPoint)->getAdrr(), ((Booleano *)varToPoint)->getType());

    }
    reference->setRefVar(varToPoint);
    varToPoint->setRefVar(reference);
}

QByteArray OperationsManager::getMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QString type_target = object.value("TYPE_TARGET").toString();

    Variable * varToSend = searchVariable(object.value("NAME").toString(), object.value("TYPE_TARGET").toString());

    if(varToSend == nullptr){
        response.insert("RESULT", "VAR_NOT_FOUND");

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
        QString data(((Char *)varToSend)->getData());
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

        Variable * valueVar = ((Structure *)varToSend)->getData(object.value("M_NAME").toString());

        if(valueVar == nullptr){
            response.insert("RESULT", "MEMBER_NOT_FOUND");
        }else if(valueVar->getType() == "INT"){
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
            QString data(((Char *)valueVar)->getData());
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
    }

    doc.setObject(response);
    return doc.toJson();
}

bool OperationsManager::variableAlreadyExists(QString name, bool isStruct)
{
    if(!isStruct){
        Variable * var = searchVariable(name);
        return var != nullptr;
    }else{
        Structure * var = ((Structure *)scopes.getEndValue()->getEndElm());
        return var->varAlreadyExists(name);
    }
}

QByteArray OperationsManager::getValMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    Variable * var = searchVariable(object.value("NAME").toString());
    if(var == nullptr){
        response.insert("RESULT", "VAR_NOT_FOUND");
        doc.setObject(response);
        return doc.toJson();
    }else if(var->getType() != "REFERENCE"){
        response.insert("RESULT", "BAD_VAR_TYPE");
        doc.setObject(response);
        return doc.toJson();
    }

    Reference * ref = (Reference *)var;
    QString valueType = ref->getValType();
    void * value = ref->getVal();

    if(valueType == "INT"){
        response.insert("VALUE", QString::number(*((int *)value)));
        response.insert("RESULT", "TRUE");

    }else if(valueType == "DOUBLE"){
        response.insert("VALUE", QString::number(*((double *)value)));
        response.insert("RESULT", "TRUE");

    }else if(valueType == "FLOAT"){
        response.insert("VALUE", QString::number(*((float *)value)));
        response.insert("RESULT", "TRUE");

    }else if(valueType == "LONG"){
        response.insert("VALUE", QString::number(*((long *)value)));
        response.insert("RESULT", "TRUE");

    }else if(valueType == "CHAR"){
        QString data(((Char *)value)->getData());
        response.insert("VALUE", data);
        response.insert("RESULT", "TRUE");

    }

    doc.setObject(response);

    return doc.toJson();
}

QByteArray OperationsManager::getAddressMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    Variable * var = searchVariable(object.value("NAME").toString());
    if(var == nullptr){
        response.insert("RESULT", "VAR_NOT_FOUND");
        doc.setObject(response);
        return doc.toJson();

    }else if(var->getType() == "REFERENCE"){
        response.insert("RESULT", "BAD_VAR_TYPE_REFERENCE");
        doc.setObject(response);
        return doc.toJson();

    }else if(var->getType() == "STRUCT"){
        response.insert("RESULT", "BAD_VAR_TYPE_STRUCT");
        doc.setObject(response);
        return doc.toJson();
    }

    QString varType = var->getType();

    if (varType == "INT"){
        response.insert("VALUE", ((Integer *)var)->getMemAddr());

    }else if (varType == "LONG"){
        response.insert("VALUE", ((Long *)var)->getMemAddr());

    }else if (varType == "FLOAT"){
        response.insert("VALUE", ((Float *)var)->getMemAddr());

    }else if (varType == "CHAR"){
        response.insert("VALUE", ((Char *)var)->getMemAddr());

    }else if (varType == "DOUBLE"){
        response.insert("VALUE", ((Double *)var)->getMemAddr());
    }

    response.insert("RESULT", "TRUE");
    response.insert("TYPE", var->getType());
    doc.setObject(response);

    return doc.toJson();
}

QByteArray OperationsManager::replaceMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;
    QJsonObject origin = object.value("ORIGIN").toObject();
    QJsonObject destiny = object.value("DESTINY").toObject();
    Variable * varOrg;
    Variable * varDest;

    if(origin.value("IN_STRUCT") == "TRUE"){
        varOrg = searchVariable(origin.value("NAME").toString(), "ANY", "TRUE", origin.value("STRUCT").toString());
    }else{
        varOrg = searchVariable(origin.value("NAME").toString());
    }

    if(destiny.value("IN_STRUCT") == "TRUE"){
        varDest = searchVariable(origin.value("NAME").toString(), "ANY", "TRUE", origin.value("STRUCT").toString());
    }else{
        varDest = searchVariable(origin.value("NAME").toString());
    }

    if(varOrg == nullptr){
        response.insert("RESULT", "ORIGIN_VAR_NOT_FOUND");

    }else if(varDest == nullptr){
        response.insert("RESULT", "DESTINY_VAR_NOT_FOUND");

    }else if (varOrg->getType() != varDest->getType()) {
        response.insert("RESULT", "VAR_IMCOPATIBLE");

    }else{
        copyVariables(varOrg, varDest);
    }

    response.insert("RESULT", "OK");
    doc.setObject(response);
    return doc.toJson();
}

QJsonArray OperationsManager::varList()
{
    VarStorage * storage;
    QJsonArray list;
    Variable * var;
    for(int scp=0; scp<scopes.getSize(); scp++){
        storage = scopes.getValue(scp);
        for(int stg=0; stg < storage->getSize(); stg++){
            var = storage->getValue(stg);
            if(var->getType() == "STRUCT") if(((Structure *)var)->isDefault()) continue;
            list.append(varToJson(var));
        }
    }
    return list;
}

QJsonObject OperationsManager::varToJson(Variable *var)
{
    QJsonArray references;
    QJsonObject obj;
    obj.insert("NAME", var->getName());
    obj.insert("TYPE", var->getType());

    if(var->getType() == "INT"){
        Integer * value = (Integer * )var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "FLOAT"){
        Float * value = (Float *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "DOUBLE"){
        Double * value = (Double *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "LONG"){
        Long * value = (Long *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", QString::number(*(value->getData())));
        obj.insert("REF_COUNT", QString::number(value->getRefCount()));

    }else if(var->getType() == "CHAR"){
        Char * value = (Char *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        QString data(((Char *)value)->getData());
        obj.insert("VALUE", data);
        obj.insert("REF_COUNT", value->getRefCount());

    }else if(var->getType() == "REFERENCE"){
        Reference * value = (Reference *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", value->getValAdrr());
        obj.insert("VAR_POINTED", value->getValType());

    }else if(var->getType() == "STRUCT"){
        Structure * value = (Structure *)var;
        obj.insert("ADDRESS", value->getMemAddr());
        obj.insert("VALUE", "-");
        obj.insert("REF_COUNT", value->getRefCount());
        obj.insert("MEMBERS", value->getMembers());
    }

    if(var->getType() != "REFERENCE"){
        for(int i=0; i < var->getRefCount(); i++){
            references.append(varToJson(var->getRefVar(i)));
        }
        obj.insert("REFERENCES", references);
    }

    return obj;
}

void OperationsManager::copyVariables(Variable *origin, Variable *destiny)
{
    QString type = origin->getType();

    if(type == "INT"){
        ((Integer *)destiny)->setData(*(((Integer *)origin)->getData()));

    }else if(type == "FLOAT"){
        ((Float *)destiny)->setData(*(((Float *)origin)->getData()));

    }else if(type == "DOUBLE"){
        ((Double *)destiny)->setData(*(((Double *)origin)->getData()));

    }else if(type == "LONG"){
        ((Long *)destiny)->setData(*(((Long *)origin)->getData()));

    }else if(type == "CHAR"){
        ((Char *)destiny)->setData(*(((Char *)origin)->getData()));

    }else if(type == "REFERENCE"){
        ((Reference *)destiny)->setRefCopy((Reference *)origin);

    }else if(type == "STRUCT"){
        ((Structure *)destiny)->copyStructure((Structure *)origin);

    }
}

QByteArray OperationsManager::scopeMode(QJsonObject object)
{
    QJsonDocument doc;
    QJsonObject response;

    if(object.value("SIGNAL") == "NEW"){
        scopes.AddNew(object.value("LINE").toString().toInt());

    }else if(object.value("SIGNAL") == "CLOSE"){
        GarbageCollector::deleteVariables(scopes.getEndValue());
        scopes.deleteEnd();

    }else{
        response.insert("RESULT", "SIGNAL_NOT_FOUND");
    }

    if(response.size() == 0) response.insert("RESULT", "OK");

    doc.setObject(response);
    return doc.toJson();
}

QByteArray OperationsManager::endProgramMode()
{
    QJsonDocument doc;
    QJsonObject response;

    if(scopes.getSize() == 1){
        response.insert("RESULT", "TRUE");

    }else if (scopes.getSize() > 1) {
        response.insert("RESULT", "FALSE");
        response.insert("LINE", scopes.getLine());
    }

    while(scopes.getSize() != 0){
        GarbageCollector::deleteVariables(scopes.getEndValue());
        scopes.deleteEnd();
    }
    scopes.AddNew();

    doc.setObject(response);
    return doc.toJson();
}
