/**
 * @file MemoryManager.h
 * @author djsq95 (David Sanchez Quiros)
 * @date 2018-03-21
 */

#ifndef TAREACORTA_MEMORYMANAGER_H
#define TAREACORTA_MEMORYMANAGER_H

#include "MMU.h"
#include "DiskAccess.h"
#include <cstring>
#include "bitset"
#include <QObject>

using namespace std;

/**
 * @brief Class used to manage the virtual memory that is being simulated.
 */

class MemoryManager : public QObject {

    /**
     * QObject MACRO
     */

    Q_OBJECT

    friend class MMU;

private:

    /**
     * @brief Constructor used initialize the memory used for the program.
     *
     * @param size Amount of memory to use for the program
     * @param parent Pointer used by QT
     */

    explicit MemoryManager(int size, QObject * parent = nullptr);

    /**
     * @brief Pointer to the memory that is being used.
     */

    void * mem;

    ~MemoryManager();

    /**
     * @brief Singleton of the MemoryManager
     */

    static MemoryManager * instance;

public:

    /**
     * @brief Method to get and initialize the only instance of MemoryManager
     *
     * @return The instance on MemoryManager
     */
    static MemoryManager * getInstance();

    /**
     * @brief Method to assign a virtual memory position.
     *
     * @param size Amount of bytes to reserve
     * @return Bitset that represents the virtual address reserved
     */
    bitset<32> allocate(int size);

    /**
     * @brief Returns a pointer to the memory that is being stored.
     *
     * @param address Bitset that represents virtual address to access
     * @return Pointer to where the actual data is stored
     */
    void * dereference(bitset<32> address);

    /**
     * @brief Struct used to store the pages in memory.
     */
    struct listNode{
        /**
         * @brief Page number.
         */
        int page;

        /**
         * @brief Pointer to where that pages' memory starts.
         */
        void * start;

        /**
         * @brief Amount of bytes used.
         */
        int used;

        /**
         * @brief Whether the page is loaded in memory or not.
         */
        bool inMemory;

        /**
         * @brief Next page used.
         */
        listNode * next;

        /**
         * @brief Bitset used to measure usage of a page.
         */
        bitset<8> usage;
    };

signals:

    /**
     * @brief Signal to notify changes in the MemoryManager's pages
     */
    void change(MemoryManager::listNode pages);

protected:

    /**
     * @brief List of pages.
     */
    listNode * pageList;

    /**
     * @brief Method that check what's the least used page and switches it with the page to load.
     *
     * @param page Page to load
     */
    void loadPage(int page);

};


#endif //TAREACORTA_MEMORYMANAGER_H
