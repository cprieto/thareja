#ifndef THAREJA_CHAP06_H
#define THAREJA_CHAP06_H

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node* create_ll(Node*);
void print_ll(Node*);
Node* prepend_ll(Node*);
Node* append_ll(Node*);

#endif //THAREJA_CHAP06_H
