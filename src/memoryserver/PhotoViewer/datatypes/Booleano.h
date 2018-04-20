/**
 * @brief Class to manage the boolean variables.
 * 
 * @file Booleano.h
 * @author aleklnx
 * @date 2018-04-18
 */
#ifndef BOOLEANO_H
#define BOOLEANO_H

#include "Variable.h"
#include <bitset>

class Booleano : public Variable
{
public:
    /**
     * @brief Construct a new boolean object
     * 
     * @param name The name of new boolean variable.
     */
    Booleano(QString name);
    /**
     * @brief Get bool pointer to value in virtual memory.
     * 
     * @return true If the value in memory is true.
     * @return false If the value in memory is false.
     */
    bool * getData();
    /**
     * @brief Set new value in memory.
     * 
     * @param value The value to set.
     */
    void setData(bool value);
    /**
     * @brief Get index in the pages of value.
     * 
     * @return std::bitset<32> The adress of the value in virtual memory.
     */
    std::bitset<32> getAdrr();
    /**
     * @brief Get address of the value in memory as hex value.
     * 
     * @return QString The hex value converted to QString.
     */
    QString getMemAddr();
};

#endif // BOOLEANO_H
