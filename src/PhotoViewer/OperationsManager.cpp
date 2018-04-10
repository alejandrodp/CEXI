#include "OperationsManager.h"
#include "MemoryManager/MemoryManager.h"
#include "MemoryViewer.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <QDebug>

OperationsManager::OperationsManager()
{

}

QString OperationsManager::makeRequest(QByteArray req)
{
    QJsonDocument doc = QJsonDocument::fromJson(req);
    QJsonObject object;
    if(doc.isNull()){
        return "error: request is not a json type.";
    }else if(!doc.isObject()){
        return "error: bad type of json (it must be an object)";
    }else{
        object = doc.object();
    }

    return object.value("OPERATION").toString();

}
