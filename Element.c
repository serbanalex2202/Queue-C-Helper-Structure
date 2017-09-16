//
//  Element.c
//  Queue
//
//  Created by Alexandru Serban on 4/18/16.
//  Copyright © 2016 Alexandru Serban. All rights reserved.
//

#include "Element.h"

int compareTo(struct Element * el1, struct Element * el2){
    
    //TODO
    return 0;
}

void freeEl(struct Element * el){
    //TODO
    free(el);
    el = NULL;
}

void printEl(struct Element * el){
    
    printf("%d\n", el->id);
}

AElement createEl(int th_id){
    
    AElement el = (AElement)calloc(1, sizeof(Element));
    
    el->id = th_id;
    el->compareTo = &compareTo;
    el->freeEl = &freeEl;
    el->printEl = &printEl;
    
    return el;
}