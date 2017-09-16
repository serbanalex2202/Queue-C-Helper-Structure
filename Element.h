/*
 * Element.h
 * Queue
 *
 * Created by Alexandru Serban on 4/18/16.
 * Copyright © 2016 Alexandru Serban. All rights reserved.
 */

#ifndef Element_h
#define Element_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/**
 *  Element structure
 */
typedef struct Element {
    
    int id;
    //TODO add
    
    int (*compareTo)(struct Element * el1, struct Element * el2);
    void (*freeEl)(struct Element *);
    void (*printEl)(struct Element * el);
    
} Element, *AElement;


int compareTo(struct Element * el1, struct Element * el2);
void freeEl(struct Element *);
void printEl(struct Element * el);
AElement createEl(int th_id);  //TODO

#endif /* Element_h */
