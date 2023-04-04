#ifndef THAREJA_CHAP06_H
#define THAREJA_CHAP06_H

typedef struct node
{
    int data;
    struct node *next;
} Node;

/**
 * Create a single linked list
 * @param num number of items
 * @param num ... items to include in list
 * @return head of list or NULL if empty
 */
Node* ll_create(int num, ...);

/**
 * Gives the length of a linked list
 * @param head start of linked list
 * @return length of the given linked list
 */
int ll_length(Node* head);


/**
 *
 */

//void print_ll(Node*);
//Node* prepend_ll(Node*);
//Node* append_ll(Node*);

#endif //THAREJA_CHAP06_H
