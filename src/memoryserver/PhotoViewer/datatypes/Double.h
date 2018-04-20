#ifndef DOUBLE_H
#define DOUBLE_H

#include "Variable.h"
#include <bitset>

class Double : public Variable
{
public:
    Double(QString name);
    double * getData();
    void setData(double value);
    std::bitset<32> getAdrr();
    QString getMemAddr();
};


#endif // DOUBLE_H
