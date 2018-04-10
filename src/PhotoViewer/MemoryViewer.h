#ifndef MEMORYVIEWER_H
#define MEMORYVIEWER_H

#include <QDialog>
#include "MemoryManager/MemoryManager.h"

namespace Ui {
class MemoryViewer;
}

class MemoryViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryViewer(QWidget *parent = 0);
    ~MemoryViewer();

public slots:
    /**
     * @brief This put the pages into the correct table of memory monitor.
     * 
     * @param pages 
     */
    void selector(MemoryManager::listNode pages);

private:
    Ui::MemoryViewer *ui;
    MemoryManager * manager;

    enum Columns {
        PAGES, USAGE
    };
    /**
     * @brief This set the info of pages in memory into the GUI of memory monitor
     *
     * @param page The pointer of page to add.
     */
    void setPagesMemSlot(MemoryManager::listNode * page);
    /**
     * @brief This set the info of pages in disk into the GUI of memory monitor
     *
     * @param page The pointer of page to add.
     */
    void setPagesDiskSlot(MemoryManager::listNode * page);
    void setTotalmemory(MemoryManager::listNode * page);
};

#endif // MEMORYVIEWER_H
