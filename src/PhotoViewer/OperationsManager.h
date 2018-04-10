#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H

class QString;
class QByteArray;

class OperationsManager
{
public:
    OperationsManager();
    static QString makeRequest(QByteArray text);
private:

};

#endif // OPERATIONSMANAGER_H
