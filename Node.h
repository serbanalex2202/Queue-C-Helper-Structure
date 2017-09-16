/*
 *
 * Node.h
 * Queue
 *
 * Created by Alexandru Serban on 4/18/16.
 * Copyright © 2016 Alexandru Serban. All rights reserved.
 */

#ifndef Node_h
#define Node_h

#include "Element.h"


/**
 * Node structure
 */
typedef struct Node {
    
    AElement el;
    struct Node* next;
    struct Node* prev;
    
    void (*freeNode)(struct Node *);
    
} Node, *ANode;

void freeNode(ANode n);
ANode crANode();

#endif /* Node_h */
