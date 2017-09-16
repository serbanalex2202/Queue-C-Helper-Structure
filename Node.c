//
//  Node.c
//  Queue
//
//  Created by Alexandru Serban on 4/18/16.
//  Copyright © 2016 Alexandru Serban. All rights reserved.
//

#include "Node.h"

void freeNode(ANode n){
    
    free(n);
    n = NULL;
}

ANode crANode(){
    
    ANode n = (ANode)calloc(1, sizeof(Node));
    n->el = NULL;
    n->next = NULL;
    n->prev = NULL;
    n->freeNode = &freeNode;
    
    return n;
}