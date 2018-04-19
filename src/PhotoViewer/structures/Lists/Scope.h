#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include "varstorage.h"

/**
* @file Scope.h
* @Author aleklnx
* @date 19/03/2018
* @brief SimpleList structure implementation
*/
class Scope{
private:

    struct Node{
        struct Node* next;
        VarStorage * variables = new VarStorage;
    } *root;
    unsigned int size;
public:
    /**
     * @brief Construct a new Simple List object
     *
     */
    Scope();
    /**
     * @brief Destroy the Simple List object
     *
     */
    ~Scope();
    /**
     * @brief This add new elements at end of the list
     *
     * @param value The value to add
     */
    void AddNew();

    /**
     * @brief Get the Value object
     *
     * @param pos The index position starting from zero, whre the element is
     * @return std::bitset<32> Return the value in the position configured.
     */
    VarStorage * getValue(int pos);
    /**
     * @brief Get the Size object
     *
     * @return int The size of the list starting from one.
     */
    int getSize();

    void deleteEnd();

    VarStorage * getEndValue();
};

#endif // SCOPE_H
