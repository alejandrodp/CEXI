/**
 * @file MMU.h
 * @author djsq95 (David Sanchez Quiros)
 * @date 2018-03-21
 */

#ifndef TAREACORTA_MMU_H
#define TAREACORTA_MMU_H

#include "MemoryManager.h"
#include "bitset"

using namespace std;

/**
 * @brief Class used to resolve the virtual addresses into a physical address.
 *
 */

class MMU {

public:
    /**
     * @brief Takes a bitset that corresponds to a page in the virtual memory.
     *
     * @param virtAddress Virtual address to be resolved into a physical address
     * @return Pointer to the physical address that corresponds to the virtual address
     */
    static void * getAddress(bitset<32> virtAddress);;

};

#endif //TAREACORTA_MMU_H
