//
//  main.c
//  Queue
//
//  Created by Alexandru Serban on 4/17/16.
//  Copyright © 2016 Alexandru Serban. All rights reserved.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

static int interval_rand(unsigned int a, unsigned int b){
    return a + rand() % b;
}

static void handle_el(AElement el){
    if(el != NULL){
        //el->printEl(el);
        el->freeEl(el);
    }
}

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int i,j;
    ALinkedList l = crALinkedList();
    
    
    for (j = 0; j < 100000; j++) {
        
        switch (interval_rand(0, 4)) {
            case 1:
                for (i = 0; i < interval_rand(0, 20); i++) {
                    l->addFirst(l, createEl(i));
                }
                break;
            case 2:
                for (i = 0; i < interval_rand(0, 20); i++) {
                    l->addLast(l, createEl(i));
                }
                break;
            case 3:
                for (i = 0; i < interval_rand(0, 200); i++) {
                    handle_el(l->popFirst(l));
                }
                break;
            case 4:
                for (i = 0; i < interval_rand(0, 200); i++) {
                    handle_el(l->popLast(l));
                }
                break;
                
            default:
                break;
        }
        
    }
                
    l->freeMem(l);
                
    
    return 0;
    
}
