#include "garbagecollector.h"
#include "../structures/Lists/varstorage.h"
#include "MemoryManager.h"
#include "datatypes/Variable.h"

GarbageCollector::GarbageCollector()
{

}

void GarbageCollector::deleteVariables(VarStorage *list)
{
    int offset;
    int page;
    std::bitset<32> virtAddress;
    int firstPage;
    MemoryManager * manager = MemoryManager::getInstance();

    for(int i=0; i< list->getSize(); i++){
        Variable * value = list->getValue(i);
        std::bitset<32> virtAddress = value->getAddress();

        page = (int) (((virtAddress) >> 24).to_ulong()); //Shift the bitset's pages to the initial position of the set and get the page number from them
        offset = (int) (bitset<32>(virtAddress) & bitset<32>("00000000111111111111111111111111")).to_ulong(); //Logical "and" to isolate the value of the address' offset

        MemoryManager::listNode * pageList = manager->pageList;
        MemoryManager::listNode * pageTarget = pageList;

        while(pageList->page != page){
            pageList = pageList->next;
        }

        void * pointer = pageList->start + offset;

        memset(pointer, 0, value->getSize());

        pageList->used -= value->getSize();

        if(pageList->used == 0 && pageList->page != 1){
            pageList = manager->pageList;
            while(pageList->next->page != page){
                pageList = pageList->next;
            }
            delete pageList->next;
            pageList->next = nullptr;
        }
        manager->emitChange();
    }
}
