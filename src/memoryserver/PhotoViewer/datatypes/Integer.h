#ifndef INTEGER_H
#define INTEGER_H

#include "Variable.h"
#include <bitset>

class Integer : public Variable
{
public:
    Integer(QString name);
    int * getData();
    void setData(int value);
    std::bitset<32> getAdrr();
    QString getMemAddr();    
};

#endif // INTEGER_H
