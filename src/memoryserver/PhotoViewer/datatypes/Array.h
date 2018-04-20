/**
 * @brief Class to manage the arrays data type.
 * 
 * @file Array.h
 * @author aleklnx
 * @date 2018-04-17
 */
#ifndef ARRAY_H
#define ARRAY_H

#include "Variable.h"

class MemoryManager;
class VarStorage;

class Array : public Variable
{
private:
    /**
     * @brief Simple list with all values in the array, they are stored as Variable object.
     * 
     */
    VarStorage * dataList;
    /**
     * @brief Pointer to memory manager, this is for return values or set them.
     * 
     */
    MemoryManager * memory;
public:
    /**
     * @brief Construct a new Array object
     * 
     * @param name The name of the new array.
     * @param type The type of the values in the new array.
     * @param size The amount of values which array gonna store.
     */
    Array(QString name, QString type, int size);
    /**
     * @brief Get som value of the array.
     * 
     * @param pos The position of value in the array.
     * @return Variable* The value requested is a Variable objetc pointer.
     */
    Variable * getData(int pos);
    /**
     * @brief Set new values in the fields of array.
     * 
     * @param value The value cnoverted to QString.
     * @param pos The position of field to store the value.
     */
    void setData(QString value, int pos);
    /**
     * @brief Get size of array based on type of the array and size.
     * 
     * @return int 
     */
    int getQuantity();
};

#endif // ARRAY_H
