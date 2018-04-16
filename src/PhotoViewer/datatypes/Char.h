#ifndef CHAR_H
#define CHAR_H

#include "Variable.h"
#include <bitset>

class Char : public Variable
{
public:
    Char(QString name);
    char * getData();
    void setData(char value);
    std::bitset<32> getAdrr();
    QString getMemAddr();
private:
    std::bitset<32> valueAdrr;
};

#endif // CHAR_H
