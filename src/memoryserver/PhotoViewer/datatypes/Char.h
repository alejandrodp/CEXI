/**
 * @brief Class to controls char object instantiations.
 * 
 * @file Char.h
 * @author aleklnx
 * @date 2018-04-17
 */
#ifndef CHAR_H
#define CHAR_H

#include "Variable.h"
#include <bitset>

class Char : public Variable
{
public:
    /**
     * @brief Construct a new Char object.
     * 
     * @param name The name of the variable with the object instance.
     */
    Char(QString name);
    /**
     * @brief Get the value stored.
     * 
     * @return char* Pointer to value stored in virtual memory
     */
    char * getData();
    /**
     * @brief Set a new value to virutal memory.
     * 
     * @param value The new value passed by copy.
     */
    void setData(char value);
    /**
     * @brief Get the address of page and offset of the variable in virtual memory.
     * 
     * @return std::bitset<32> The address of variable.
     */
    std::bitset<32> getAdrr();
    /**
     * @brief Get the memory address of variable in real memory, this address is the hex number of pointer.
     * 
     * @return QString The address of variable.
     */
    QString getMemAddr();
private:
    /**
     * @brief The address of variable, in the virtual pages.
     * 
     */
};

#endif // CHAR_H
