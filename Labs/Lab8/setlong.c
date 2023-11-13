#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#define SIZE 10

struct var_state{
    void *addr;
    unsigned int size;
    struct var_state *next;
    char data[0];
};
struct var_state *var_state_head = NULL;

void save_state(void *var_addr, unsigned int var_size){
    struct var_state *new_node = (struct var_state*)malloc(sizeof(struct var_state) + var_size);
    new_node->addr = var_addr;
    new_node->size = var_size;
    memcpy(new_node->data, var_addr, var_size);
    new_node->next = var_state_head;
    var_state_head = new_node;  
}

void restore_state(){
    struct var_state *curr, *prev;
    curr = prev = var_state_head;
    while(curr){
        memcpy(curr->addr, curr->data, curr->size);
        curr = curr->next;
        free(prev);
        prev = curr;
    }
}

jmp_buf env;
int g = 10;

void handler(int signum){
    if(signum == SIGSEGV){
        longjmp(env, signum);
    }
}

int main(){
    int x;
    char *p;
    x = 11;
    p = (char*)malloc(SIZE);
    p[0] = p[1] = 'x';

    save_state(&g, sizeof(g));
    save_state(&x, sizeof(x));
    save_state(&p, SIZE);

    signal(SIGSEGV, handler);

    if(setjmp(env) == 0){
        g = 30;
        x = 100;
        p = 0;
        p[0] = p[1] = p[2] = 'x';
    } else {
        restore_state();
        printf("%d, %d, %c, %c\n", g, x, p[0], p[1]);
    }
    return 0;
}

