#include "Scope.h"
#include <iostream>

/**
 * @brief Construct a new Simple List:: Simple List object
 * Este es el constructor de la lista Simple.
 *
 */
Scope::Scope() {
    this->root = nullptr;
    this->size = 0;
}

/**
 * @brief Destroy the Simple List:: Simple List object
 * El destructor borra cada nodo que fue creado liberando la memoria.
 *
 */
Scope::~Scope(){
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
void Scope::AddNew(int line)
{
    struct Node* adding = new struct Node;
    adding->line = line;
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
VarStorage * Scope::getValue(int pos){
    if(pos == 0){
        return root->variables;
    }else{
        struct Node* searching = root;
        for(int i=0; i != pos; i++){
            searching = searching->next;
        }
        return searching->variables;
    }
}

/**
 * @brief Get size of list
 * Obtiene el tamaño de la lista
 * @return int
 */
int Scope::getSize(){

    return this->size;

}

void Scope::deleteEnd()
{
    struct Node* pivot = root;
    if(pivot->next == nullptr){
        delete root;
        root = nullptr;
    }else{
        while (pivot->next->next != nullptr){
            pivot = pivot->next;
        }
        delete pivot->next;
        pivot->next = nullptr;
    }

    this->size--;
}

VarStorage * Scope::getEndValue()
{
    struct Node* searching = root;
    for(int i=0; i != this->size-1; i++){
        searching = searching->next;
    }
    return searching->variables;
}

int Scope::getLine()
{
    struct Node* searching = root;
    for(int i=0; i != this->size-1; i++){
        searching = searching->next;
    }

    return searching->line;

}

void Scope::AddNew()
{
    struct Node* adding = new struct Node;
    adding->line = 0;
    adding->next = nullptr;
    adding->variables = new VarStorage;
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
