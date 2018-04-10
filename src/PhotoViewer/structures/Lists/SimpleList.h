#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <iostream>
#include "bitset"

/**
* @file SimpleList.h
* @Author aleklnx
* @date 19/03/2018
* @brief SimpleList structure implementation
*/
class SimpleList{
private:

    struct Node{
        struct Node* next;
        std::bitset<32> address;
        int value;

    } *root;
    unsigned int size;
public:
    /**
     * @brief Construct a new Simple List object
     * 
     */
    SimpleList();
    /**
     * @brief Destroy the Simple List object
     * 
     */
    ~SimpleList();
    /**
     * @brief This add new elements at end of the list
     * 
     * @param value The value to add
     */
    void AddEnd(std::bitset<32> value);
    /**
     * @brief Get the Value object
     * 
     * @param pos The index position starting from zero, whre the element is
     * @return std::bitset<32> Return the value in the position configured.
     */
    std::bitset<32> getValue(int pos);
    /**
     * @brief Get the Size object
     * 
     * @return int The size of the list starting from one.
     */
    int getSize();
};
#endif
