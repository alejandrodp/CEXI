//
// Created by davidsq on 12/03/18.
//

#include <iostream>
#include "MemoryManager.h"
#include <QThread>

MemoryManager * MemoryManager::instance = nullptr;

bitset<32> MemoryManager::allocate(int size) {
    listNode * currentPage = pageList;
    bool spaceFound = false; //Flag to know if a new page will be needed
    bitset<32> newAddress;
    for(;currentPage != nullptr; currentPage = currentPage->next){
        currentPage->usage >>= 1; //Shift usage counter to the right
        if(currentPage->used + size < 0x400000) {  //Check if there is enough space in any of the existing pages
            spaceFound = true;
            currentPage->usage[0] = 1; //Mark chosen page as recent used
            break;
        }else if(currentPage->next == nullptr){
            break;
        }
    }

    if(!spaceFound){ //Create new page if needed
        currentPage->next = new listNode;
        currentPage->next->start = (currentPage->start + 0x400000); //The page should start where the last one ends
        currentPage->next->page = currentPage->page + 1;
        currentPage = currentPage->next;
        currentPage->next = nullptr;
        currentPage->used = 0;
        currentPage->usage = bitset<8>("10000000");
        if (currentPage->page > 3)
        currentPage->inMemory = false;
        else
        currentPage->inMemory = true;
    }

    std::cout << "Page to save photo: " << currentPage->page << std::endl;

    if(currentPage->inMemory == false){
        loadPage(currentPage->page);
    }

    newAddress = bitset<32>(currentPage->page); //Initializes a new bitset to store the pointers information

    newAddress <<= 24; //The bitset's data is shifted to the position of page bits

    newAddress |= bitset<32>(currentPage->used); //A logic "or" to add the offset to the address

    currentPage->used += size;

    emit change(*pageList);

    QThread::sleep(0.5);

    return newAddress;
}

MemoryManager::MemoryManager(int size, QObject * parent) : QObject(parent){
    mem = malloc(static_cast<size_t>(size));
    pageList = new listNode();
    pageList->page = 1;
    pageList->inMemory = true;
    pageList->start = mem;
    pageList->used = 0;
    pageList->next = nullptr;
    pageList->usage = bitset<8>("00000000");
}

MemoryManager::~MemoryManager(){

}

MemoryManager * MemoryManager::getInstance() {
    if(instance == nullptr){
        instance = new MemoryManager(0xC00000);
    }
    return instance;
}

void MemoryManager::loadPage(int page) {
    listNode * leastUsed;
    listNode * currentPage;
    listNode * toLoad = nullptr;
    if(page > 1){ //Check for the special case that the page to load is the first page
        leastUsed = pageList;
        currentPage = pageList->next;
    }
    else{
        leastUsed = pageList->next;
        currentPage = pageList->next->next;
        toLoad = pageList;
    }

    for(;currentPage != nullptr; currentPage = currentPage->next){
        if(currentPage->inMemory){ //Checks if the current page is in memory
            if(leastUsed->usage.to_ulong() >= currentPage->usage.to_ulong()){ //Checks if the current page is used more than the one chosen to be taken down
                leastUsed = currentPage;
            }
            currentPage->usage >>= 1; //Shift the current page's usage counter to the right
        }else if(currentPage->page == page){ //Get the details of the page to load
            toLoad = currentPage;
        }
    }

    DiskAccess::writeToDisk(leastUsed->page, leastUsed->start, 0x400000); //Write the content of the page  to take down into the disk

    if(toLoad->used > 0) { //Check for something to load
        void *dataToLoad = DiskAccess::readFromDisk(page); //Temporary pointer to swap the pages

        toLoad->start = memcpy(leastUsed->start, dataToLoad, 0x400000); //Update the first address of the page that is being loaded

        delete dataToLoad; //Release the temporary pointer
    }else{ //If there is nothing to load, clear up the memory
        toLoad->start = leastUsed->start; //Update the first address of the page that is being loaded
        memset(toLoad->start, 0, 0x400000); //Set all bits in the position to 0, as if called with calloc
    }

    toLoad->inMemory = true;
    leastUsed->inMemory = false;

    emit change(*pageList);

    QThread::sleep(0.5);
}

void *MemoryManager::dereference(bitset<32> address) {
    return MMU::getAddress(address);
}
