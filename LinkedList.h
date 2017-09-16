/*
 * Author: Serban Alexandru
 *
 * LinkedList structure
 *
 */


#include "Node.h"


/**
 * LinkedList structure.
 * The structure contains the head of the list, the tail the size and the related methods.
 */
typedef struct LinkedList {

	ANode head;
	ANode tail;
	unsigned int size;

    void (*addFirst)(struct LinkedList *, AElement);
	AElement (*popFirst)(struct LinkedList*);
	AElement (*showFirst)(struct LinkedList*);

	void (*addLast)(struct LinkedList*, AElement);
    AElement (*popLast)(struct LinkedList*);
	AElement (*showLast)(struct LinkedList*);
	
	void (*display)(struct LinkedList*);
	void (*displayR)(struct LinkedList*);

	int (*contains)(struct LinkedList*, AElement);
	void (*freeMem)(struct LinkedList*);


} LinkedList, *ALinkedList;


void addFirst(LinkedList* list, AElement el);
AElement popFirst(LinkedList* list);
AElement showFirst(LinkedList* list);

void addLast(LinkedList* list, AElement el);
AElement popLast(LinkedList* list) ;
AElement showLast(LinkedList* list);

void display(LinkedList* list);
void displayR(LinkedList* list);

int contains(LinkedList* list, AElement el);
void freeMem(LinkedList* list);
ALinkedList crALinkedList();
