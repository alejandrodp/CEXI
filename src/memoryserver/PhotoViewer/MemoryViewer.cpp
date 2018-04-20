#include "MemoryViewer.h"
#include "ui_MemoryViewer.h"
#include "MemoryManager/MemoryManager.h"
#include <iostream>

MemoryViewer::MemoryViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryViewer),
    manager(MemoryManager::getInstance())
{
    ui->setupUi(this);
}

void MemoryViewer::selector(MemoryManager::listNode pages){
    ui->table_pagesInDisk->setRowCount(0);
    ui->table_pagesInMem->setRowCount(0);
    MemoryManager::listNode * pagesPointer = &pages;

    while(pagesPointer != nullptr){
        if(pagesPointer->inMemory){
            this->setPagesMemSlot(pagesPointer);
        }else{
            this->setPagesDiskSlot(pagesPointer);
        }

        pagesPointer = pagesPointer->next;
    }
    this->setTotalmemory(&pages);

    delete pagesPointer;

}


void MemoryViewer::setPagesDiskSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowDisk;
    QTableWidgetItem * usedRowDisk;
    QTableWidget * table = ui->table_pagesInDisk;

    table->insertRow(table->rowCount());

    int ROW = table->rowCount() - 1;

    pageRowDisk = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);

    if(page->used != 0){
        usedRowDisk = new QTableWidgetItem(QString::number(page->used));
        usedRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);
    }else{
        usedRowDisk = new QTableWidgetItem("0");
        usedRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);
    }

    table->setItem(ROW, PAGES, pageRowDisk);
    table->setItem(ROW, USAGE, usedRowDisk);
}

void MemoryViewer::setPagesMemSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowMem;
    QTableWidgetItem * usedRowMem;
    QTableWidget * table = ui->table_pagesInMem;

    table->insertRow(table->rowCount());

    int ROW = table->rowCount() -1;

    pageRowMem = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowMem->setFlags(pageRowMem->flags() ^ Qt::ItemIsEditable);

    if(page->used != 0){
        usedRowMem = new QTableWidgetItem(QString::number(page->used));
        usedRowMem->setFlags(usedRowMem->flags() ^ Qt::ItemIsEditable);
    }else{
        usedRowMem = new QTableWidgetItem("0");
        usedRowMem->setFlags(usedRowMem->flags() ^ Qt::ItemIsEditable);
    }

    ui->table_pagesInMem->setItem(ROW, PAGES, pageRowMem);
    ui->table_pagesInMem->setItem(ROW, USAGE, usedRowMem);
}

void MemoryViewer::setTotalmemory(MemoryManager::listNode * page){
    double totalB = 0;
    while(page != nullptr){
        totalB += page->used;
        page = page->next;
    }
    ui->lcd_TotalMem->display(totalB);
}



MemoryViewer::~MemoryViewer()
{
    delete ui;
}
