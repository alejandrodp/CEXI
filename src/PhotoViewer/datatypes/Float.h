#ifndef FLOAT_H
#define FLOAT_H

#include "Variable.h"
#include <bitset>

class Float : public Variable
{
public:
    Float(QString name);
    float * getData();
    void setData(float value);
    std::bitset<32> getAdrr();
    QString getMemAddr();
private:
    std::bitset<32> valueAdrr;
};

#endif // FLOAT_H
