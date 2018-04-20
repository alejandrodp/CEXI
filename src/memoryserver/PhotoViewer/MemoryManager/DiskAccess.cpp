//
// Created by davidsq on 12/03/18.
//

#include <cstring>
#include <iostream>
#include <sstream>
#include "DiskAccess.h"
#include <stdio.h>
#include <string>

#define PAGESIZE 0x14

void *DiskAccess::readFromDisk(int pageNumber) {
    stringstream string;
    string << "Page" << pageNumber << ".bin";
    fstream file = fstream(string.str(),ios::in|ios::binary);
    std::cout << "Reading page:" << file.is_open() << ":" << string.str() << "\n";
    void * data = calloc(1024, PAGESIZE);
    file.read((char *)data, PAGESIZE);
    file.close();

    return data;
}

void DiskAccess::writeToDisk(int pageNumber, void *memorySpace, int size) {
    stringstream string;
    string << "Page" << pageNumber << ".bin";
    ofstream file(string.str(), ios::out | ios::binary);
    std::cout << "Writing page:" << file.is_open() << ":" << string.str() << "\n";
    char * buffer = static_cast<char *>(memorySpace);
    file.write(buffer, size);
    file.close();
}
