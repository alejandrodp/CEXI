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
private:
    std::bitset<32> valueAdrr;
};

#endif // INTEGER_H
