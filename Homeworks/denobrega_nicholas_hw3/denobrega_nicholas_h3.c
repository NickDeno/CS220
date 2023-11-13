#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node { 
    int val; 
    struct node *next;
};
typedef struct node Node;

unsigned int count_nodes(Node *head){
    unsigned int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

Node **split_list(Node *head, unsigned int num) {
    Node **ret = (Node**)malloc(num * sizeof(Node*));
    int idx = 0;
    while (head != NULL) {
        Node *temp = head->next;
        if (ret[idx] == NULL) {
            ret[idx] = head;
            head->next = NULL;
        } else {
            Node *tail = ret[idx];
            while (tail->next != NULL) tail = tail->next;
            tail->next = head;
            head->next = NULL;
        }
        head = temp;
        idx = (idx + 1) % num;
    }
    return ret;
}

Node *interleave_list(Node *head1, Node *head2){
    if(head1 == NULL && head2 == NULL) return NULL;   
    else if(head1 != NULL && head2 == NULL) return head1;
    else if(head1 == NULL && head2 != NULL) return head2;

    Node *current = NULL;
    Node *result = NULL;
    while(head1 != NULL && head2 != NULL){
        if(current == NULL){
            current = head1;
            result = current;
        } else {
            current->next = head1;
            current = current->next;
        }
        head1 = head1->next;

        current->next = head2;
        head2 = head2->next;
        current = current->next;
    }  
    if(head1 != NULL){
        current->next = head1;
    } else if(head2 != NULL){
        current->next = head2;
    }
    return result;
}

int get_float_exponent(float f){
    if(f == 0)return -126; //1 - bias where bias = 127 in this case
    int temp = *(unsigned int*)&f;
    int frac_bits = (temp >> 23) & 0xFF;
    return frac_bits - 127;
}