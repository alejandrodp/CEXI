#include <iostream>
#include "SimpleList.h"

/**
 * @brief Construct a new Simple List:: Simple List object
 * Este es el constructor de la lista Simple.
 * 
 */
SimpleList::SimpleList() {
    this->root = nullptr;
    this->size = 0;
}

/**
 * @brief Destroy the Simple List:: Simple List object
 * El destructor borra cada nodo que fue creado liberando la memoria.
 * 
 */
SimpleList::~SimpleList(){
    if(this->size == 1){
        delete root;
        root = nullptr;
    }else if(root != nullptr){
    struct Node* toDel = root;
    struct Node* next = root->next;
    while (next->next != nullptr) {
        delete toDel;
        toDel = next;
        next = next->next;
    }
    delete toDel;
    delete next;
    }
}

/**
 * @brief Add new elements
 * Añade nuevos elementos a la lista en el final.
 * @param value El vlor quese desea añadir
 */
void SimpleList::AddEnd(std::bitset<32> address){
    struct Node* adding = new struct Node;
    adding->address = address;
    adding->value = this->size;
    adding->next = nullptr;
    if (root == nullptr){
         root = adding;
    }else{
        struct Node* pivot = root;
        while (pivot->next != nullptr){
            pivot = pivot->next;
        }
        pivot->next = adding;
    }
    this->size++;
}

/**
 * @brief Get values of certain position
 * Obtiene elementos en una posición determinada
 * @param pos Posición en la lista
 * @return int El elemento solicitado
 */
std::bitset<32> SimpleList::getValue(int pos){
    if(pos == 0){
        return root->address;
    }else{
        struct Node* searching = root;
        for(int i=0; i<pos; i++){
            searching = searching->next;
        }
        if(searching->next == nullptr) return searching->address; else return searching->next->address;
    }
}

/**
 * @brief Get size of list
 * Obtiene el tamaño de la lista
 * @return int 
 */
int SimpleList::getSize(){

    return this->size;

}

