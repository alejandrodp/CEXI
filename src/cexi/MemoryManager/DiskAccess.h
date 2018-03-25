/**
 * @brief Class used to write and read files from disk.
 *
 * @file DiskAccess.h
 * @author djsq95 (David Sanchez Quiros)
 * @date 2018-03-21
 */

#ifndef TAREACORTA_DISKACCESS_H
#define TAREACORTA_DISKACCESS_H

#include "fstream"

using namespace std;


class DiskAccess {
public:
    /**
     * @brief Reads the page specified in the input parameter. This file is saved as a binary file.
     *
     * @param pageNumber Number of the page to read
     * @return Pointer to where the data that has been read is stored
     */
    static void * readFromDisk(int pageNumber);

    /**
     * @brief Saves the data stored in the memory location specified in a binary file.
     *
     * @param pageNumber Number of the page to save
     * @param memorySpace Location of the information to save
     * @param size Amount of bytes to save
     */
    static void writeToDisk(int pageNumber, void * memorySpace, int size);
};


#endif //TAREACORTA_DISKACCESS_H
