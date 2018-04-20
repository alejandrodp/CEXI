#ifndef VARSTORAGE_H
#define VARSTORAGE_H

#include <iostream>
#include "bitset"
#include "datatypes/Variable.h"


/**
* @file VarStorage.h
* @Author aleklnx
* @date 19/03/2018
* @brief SimpleList structure implementation
*/
class VarStorage{
private:

    struct Node{
        struct Node* next;
        Variable * var;
    } *root;
    unsigned int size;
public:
    /**
     * @brief Construct a new Simple List object
     *
     */
    VarStorage();
    /**
     * @brief Destroy the Simple List object
     *
     */
    ~VarStorage();
    /**
     * @brief This add new elements at end of the list
     *
     * @param value The value to add
     */
    void AddEnd(Variable * newVar);

    /**
     * @brief Get the Value object
     *
     * @param pos The index position starting from zero, whre the element is
     * @return std::bitset<32> Return the value in the position configured.
     */
    Variable * getValue(int pos);
    /**
     * @brief Get the Size object
     *
     * @return int The size of the list starting from one.
     */
    int getSize();

    Variable * getEndElm();

    void deleteElm(int pos);
};

#endif // VARSTORAGE_H
