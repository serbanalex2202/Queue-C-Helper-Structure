#include "LinkedList.h"


/**
 * Adds new element at the beginning of the list and allocate memory.
 */
void addFirst(LinkedList* list, AElement el) {
    
    ANode n = crANode();
    ANode aux;
    n->el = el;
   
    if(list->size == 0){
        list->head = n;
        list->tail = n;
    }
    else{
        aux = list->head;
        list->head = n;
        list->head->next = aux;
        aux->prev = list->head;
    }
    
    list->size++;
}

/*
 * Returns the first element and removes it from the list.
 * The element must be freed afterwards.
 */
AElement popFirst(LinkedList* list) {
    
    if (list->size == 0){
        printf("Empty LinkedList");
        return NULL;
    }
    
    ANode head = list->head;
    AElement el = head->el;
    
    list->head = head->next;
    if (list->head != NULL){
        list->head->prev = NULL;
    }
    list->size--;
    
    head->freeNode(head);
    return el;
}

/*
 * * Only returns the first element without removing it from the list
 */
AElement showFirst(LinkedList* list) {
    
    if (list->size == 0){
        printf("Empty LinkedList");
        return NULL;
    }
    
    Node* head = list->head;
    return head->el;
}

/**
 * Adds new item at the end of the list
 */
void addLast(LinkedList* list, AElement el) {
    
    ANode aux;
    ANode n = crANode();
    n->el = el;
    
    if(list->size == 0){
        list->head = n;
        list->tail = n;
    }else{
        aux = list->tail;
        list->tail = n;
        list->tail->prev = aux;
        aux->next = list->tail;
    }
    
    list->size++;
}

/**
 * Returns the last element and removes it form the list.
 * The element must be freed until the end of the program.
 */
AElement popLast(LinkedList* list) {
    
    if (list->size == 0){
        printf("Empty LinkedList");
        return NULL;
    }
    
    ANode tail = list->tail;
    AElement el = tail->el;
    
    list->tail = tail->prev;
    if (list->tail != NULL){
        list->tail->next = NULL;
    }
    
    list->size--;
    
    tail->freeNode(tail);
    return el;
}

/**
 * Only returns the last element without removing it from the list
 */
AElement showLast(LinkedList* list) {
    
    if (list->size == 0){
        printf("Empty LinkedList");
        return NULL;
    }
    
    
    ANode tail = list->tail;
    return tail->el;
}

/**
 *  Prints list with given print function
 */
void display(LinkedList* list) {
    
    printf("List :\n");
    if (list->size == 0)
        printf("Empty LinkedList");
    
    else {
        ANode current = list->head;
        
        while (current != NULL){
            (current->el->printEl(current->el));
            current = current->next;
        }
    }
    printf("\n");
}

/**
 * Reverse print of elements (done for testing links)
 */
void displayR(LinkedList* list) {
    
    printf("ListaR :\n");
    if (list->size == 0)
        printf("Empty LinkedList");
    
    else {
        ANode current = list->tail;
        
        while (current != NULL){
            (current->el->printEl(current->el));
            current = current->prev;
        }
    }
    printf("\n");
}

/*
 * Verify if List contains given item and returns 1 or 0 if it doesn't
 */
int contains(LinkedList* list, AElement el) {
    
    if (list->size == 0) {
        return 0;
        
    } else {
        
        ANode current = list->head;
        
        while (current != NULL){
            if (el->compareTo(el, current->el) == 0) {
                return 1;
            }
            
            current = current->next;
        }
    }
    
    return 0;
}


/*
 * Free memory of each element and LinkedList memory
 */
void freeMem(ALinkedList list) {
    
    if (list->size == 0) {
        return;
    }
    
    ANode current = list->head;
    ANode next = current->next;
    
    while (1) {
        
        current->el->freeEl(current->el);
        current->freeNode(current);
        current = next;
        
        /* Break when current node is last node */
        if (current == NULL) {
            free(list);
            list = NULL;
            break;
        }
        
        next = current->next;
    }
}


/**
 * ALinkedList constructor function
 */
ALinkedList crALinkedList() {
    
    ALinkedList list = (ALinkedList)calloc(1, sizeof(LinkedList));
    
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    
    list->addFirst = &addFirst;
    list->popFirst = &popFirst;
    list->showFirst = &showFirst;
    
    list->showLast = &showLast;
    list->addLast = &addLast;
    list->popLast = &popLast;
    
    list->display = &display;
    list->displayR = &displayR;
    
    list->contains = &contains;
    list->freeMem = &freeMem;
    
    return list;
}

