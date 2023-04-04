#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "chap06.h"


Node* ll_create(int num, ...) {
    va_list items;
    va_start(items, num);

    Node* root = NULL;

    for (int i = 0; i < num; i++) {
        int value = va_arg(items, int);

        Node* new_node = malloc(sizeof (Node));
        new_node->data = value;
        new_node->next = NULL;

        if (root == NULL) {
            root = new_node;
            continue;
        }

        Node* current = root;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
    va_end(items);

    return root;
}

//
//void ll_print(Node* root) {
//    Node* current = root;
//    while (current != NULL) {
//        printf("%d", current->data);
//        current = current->next;
//    }
//}
//
//Node *create_ll(Node *root) {
//    for (;;) {
//        printf("Enter a number (-1 to finish): ");
//        int num;
//        scanf("%d", &num);
//
//        if (num == -1) break;
//
//        Node *new_node = malloc(sizeof(Node));
//        new_node->data = num;
//
//        if (root == NULL) {
//            root = new_node;
//            continue;
//        }
//
//        // Go to the last element in the list
//        Node *current = root;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = new_node;
//    }
//
//    return root;
//}
//
//void print_ll(Node* root) {
//    printf("\nList content: ");
//    for (Node* current = root; current != NULL; current = current->next) {
//        printf("%d -> ", current->data);
//    }
//    printf("NULL\n");
//}
//
//Node* prepend_ll(Node* start) {
//    printf("\nEnter number to prepend: ");
//    int num;
//    scanf("%d", &num);
//
//    Node* new_node = malloc(sizeof (Node));
//    new_node->data = num;
//    new_node->next = start;
//
//    return new_node;
//}
//
//Node* append_ll(Node* start) {
//    printf("\nEnter number to append: ");
//    int num;
//    scanf("%d", &num);
//
//    Node* new_node = malloc(sizeof(Node));
//    new_node->data = num;
//
//    if (start == NULL) return new_node;
//
//    Node* current = start;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    current->next = new_node;
//
//    return start;
//}
