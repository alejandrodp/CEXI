//
// Created by davidsq on 07/03/18.
//

#include "MMU.h"
#include <iostream>
void * MMU::getAddress(bitset<32> virtAddress) {
    int page = 0;
    int offset = 0;

    offset = (int) (bitset<32>(virtAddress) & bitset<32>("00000000111111111111111111111111")).to_ulong(); //Logical "and" to isolate the value of the address' offset
    page = (int) (((virtAddress) >> 24).to_ulong()); //Shift the bitset's pages to the initial position of the set and get the page number from them

    MemoryManager * manager = MemoryManager::getInstance(); //Get the memory manager

    MemoryManager::listNode * currentNode = manager->pageList; //Get the first page in the list of pages

    for(;currentNode != nullptr; currentNode = currentNode->next){
        currentNode->usage >>= 1; //Shift the current page's usage counter to the right
        if(currentNode->page == page){
            currentNode->usage[0] = 1;
            break;
        }
    }

    if(currentNode->inMemory == false){
        manager->loadPage(page);
    }

    void * address = currentNode->start + offset;

    std::cout << std::dec << "Page number: " << page << " Inicio: " << currentNode->start;
    std::cout << " Desplazamiento: 0x" << std::hex << offset << std::endl;

    return address;
}
