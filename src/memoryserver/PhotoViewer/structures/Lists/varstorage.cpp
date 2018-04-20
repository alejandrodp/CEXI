#include "varstorage.h"

/**
 * @brief Construct a new Simple List:: Simple List object
 * Este es el constructor de la lista Simple.
 *
 */
VarStorage::VarStorage() {
    this->root = nullptr;
    this->size = 0;
}

/**
 * @brief Destroy the Simple List:: Simple List object
 * El destructor borra cada nodo que fue creado liberando la memoria.
 *
 */
VarStorage::~VarStorage(){
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
void VarStorage::AddEnd(Variable * newVar){
    struct Node * adding = new Node;
    adding->var = newVar;
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
Variable * VarStorage::getValue(int pos){
    if(pos < 0 || pos > size-1) return nullptr;

    Node * pivot = root;
    for(int i=0; i!=pos; i++){
        pivot = pivot->next;
    }

    return pivot->var;
}

/**
 * @brief Get size of list
 * Obtiene el tamaño de la lista
 * @return int
 */
int VarStorage::getSize(){

    return this->size;

}

Variable * VarStorage::getEndElm()
{
    Node * pivot = this->root;

    while(pivot->next != nullptr){
        pivot = pivot->next;
    }

    return pivot->var;
}

void VarStorage::deleteElm(int pos)
{
    Node * pivot = this->root;
    if(pos == 0){
        this->root = pivot->next;
        delete pivot;
    }else{

        for(int i=0; i < pos-1; i++){
            pivot = pivot->next;
        }

        Node * temp = pivot->next;
        pivot->next = temp->next;
        delete temp;
    }
    this->size--;
}
