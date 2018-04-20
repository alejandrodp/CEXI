#include <iostream>
#include <bitset>
#include "MemoryManager.h"

bool writeToDisk(int pageNumber, void *memorySpace, int size) {
    ofstream file = ofstream('Page' + pageNumber + ".bin",ios::out);
    char * buffer = static_cast<char *>(memorySpace);
    file.write(buffer, size);
    file.close();
    return false;
}

void * readFromDisk(int pageNumber) {
    fstream file = fstream('Page' + pageNumber + ".bin",ios::in|ios::binary);
    void * data = calloc(1024, 1024 * 4);
    file.read((char *)data, 0x400000);
    file.close();
    return data;
}


int main() {
    void * ptr = calloc(1024, 1024 * 4);

    char * pointer = static_cast<char *>(ptr);
    *pointer = 'r';

    writeToDisk(1, ptr, 0x400000);
    void * test = readFromDisk(1);
    char * print = static_cast<char *>(test);
    std::cout << (char *)ptr << std::endl;
    /*bitset<32> pointer = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer2 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer3 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer4 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer5 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer6 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer7 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer8 = MemoryManager::getInstance()->allocate(0x160000);
    bitset<32> pointer9 = MemoryManager::getInstance()->allocate(0x160000);

    std::cout << pointer << "\n" << static_cast<int *>(MemoryManager::getInstance()->dereference(pointer)) << "\n";
    std::cout << pointer2 << "\n" << static_cast<int *>(MemoryManager::getInstance()->dereference(pointer2)) << "\n";
    std::cout << pointer3 << "\n" << static_cast<int *>(MemoryManager::getInstance()->dereference(pointer3)) << "\n";
    std::cout << pointer4 << "\n" << static_cast<int *>(MemoryManager::getInstance()->dereference(pointer4)) << "\n";

    int * ptr = static_cast<int *>(MemoryManager::getInstance()->dereference(pointer));

    *(ptr) = 10;

    std::cout << ptr << "  " << *ptr;*/

    return 0;
}