#ifndef REFERENCE_H
#define REFERENCE_H

#include "Variable.h"
#include <bitset>

class Reference : public Variable
{
public:
    Reference(QString name, QString varTypeToPoint);
    QString getValAdrr();
    void * getVal();
    void setData(std::bitset<32> valAddrr);

private:
    QString data;
    std::bitset<32> valAdrr;
    QString typeToRef;
};

#endif // REFERENCE_H
