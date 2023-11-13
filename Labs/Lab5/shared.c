#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

void *logger_malloc(unsigned int size){
    void *ret;
    printf("Allocating %u bytes....", size);
    ret = malloc(size);
    if(ret == 0){
        printf("Allocation Failed!\n");
    } else {
        printf("Sucessfully allocated at %p", ret);
    }
    return ret;
}

void logger_free(void *p){
    printf("Freeing memory at %p", p);
    free(p);
    printf("DONE\n");
}