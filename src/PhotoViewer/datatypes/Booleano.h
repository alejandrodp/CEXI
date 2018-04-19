#ifndef BOOLEANO_H
#define BOOLEANO_H

#include "Variable.h"
#include <bitset>

class Booleano : public Variable
{
public:
    Booleano(QString name);
    bool * getData();
    void setData(bool value);
    std::bitset<32> getAdrr();
    QString getMemAddr();
private:
    std::bitset<32> valueAdrr;
};

#endif // BOOLEANO_H
