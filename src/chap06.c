#include <stdio.h>
#include <stdlib.h>
#include "chap06.h"


int main(int argc, char *argv[]) {
    Node *start = NULL;
    int option;
    do {
        printf("\n***** MAIN MENU *****\n");
        printf(" 1: Create a list\n");
        printf(" 2: Display the list\n");
        printf(" 3: Add a node at the beginning\n");
        printf(" 4: Add a node at the end\n");
        printf(" 5: Add a node before a given node\n");
        printf(" 6: Add a node after a given node\n");
        printf(" 7: Delete a node from the beginning\n");
        printf(" 8: Delete a node from the end\n");
        printf(" 9: Delete a given node\n");
        printf("10: Delete a node after a given node\n");
        printf("11: Delete the entire list\n");
        printf("12: Sort the list\n");
        printf("13: EXIT\n");
        printf("\nEnter your option : ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                start = create_ll(start);
                printf("\nList created.\n");
                break;
            case 2:
                print_ll(start);
                break;
            case 3:
                start = prepend_ll(start);
                break;
            case 4:
                start = append_ll(start);
                break;
            default:
                break;
        }
    } while (option != 13);
    getchar();

    return 0;
}

Node *create_ll(Node *root) {
    for (;;) {
        printf("Enter a number (-1 to finish): ");
        int num;
        scanf("%d", &num);

        if (num == -1) break;

        Node *new_node = malloc(sizeof(Node));
        new_node->data = num;

        if (root == NULL) {
            root = new_node;
            continue;
        }

        // Go to the last element in the list
        Node *current = root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return root;
}

void print_ll(Node* root) {
    printf("\nList content: ");
    for (Node* current = root; current != NULL; current = current->next) {
        printf("%d -> ", current->data);
    }
    printf("NULL\n");
}

Node* prepend_ll(Node* start) {
    printf("\nEnter number to prepend: ");
    int num;
    scanf("%d", &num);

    Node* new_node = malloc(sizeof (Node));
    new_node->data = num;
    new_node->next = start;

    return new_node;
}

Node* append_ll(Node* start) {
    printf("\nEnter number to append: ");
    int num;
    scanf("%d", &num);

    Node* new_node = malloc(sizeof(Node));
    new_node->data = num;

    if (start == NULL) return new_node;

    Node* current = start;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    return start;
}