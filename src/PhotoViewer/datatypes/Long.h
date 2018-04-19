#ifndef LONG_H
#define LONG_H

#include "Variable.h"
#include <bitset>

class Long : public Variable
{
public:
    Long(QString name);
    long * getData();
    void setData(long value);
    std::bitset<32> getAdrr();
    QString getMemAddr();
private:
    std::bitset<32> valueAdrr;
};


#endif // LONG_H
