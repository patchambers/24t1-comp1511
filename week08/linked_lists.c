// linked_list.c
// This program was written by YOUR-NAME (zID)
// Implementation for simple linked lists functions

#include <stdio.h>
#include <stdlib.h>

#include "linked_lists.h"

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

struct node *insert_head(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;

    // new_node is head of list now, since it was inserted before the old head
    return new_node;
}

struct node *insert_tail(struct node *head, int data) {
    struct node *new_node = create_node(data);
    // If list is empty, new_node is now the head of the list
    if (head == NULL) {
        return new_node;
    }
    // Loop until curr points at the last node in the list
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // Change next pointer of the last node to point at new_node
    curr->next = new_node;
    return head;
}

void print_list(struct node *head) {
    // Set current to be the first node in the list
    struct node *current = head;
    
    // Traverse the linked list and print each node 
    // until we reach the end of the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("X\n");
}

int list_length(struct node *head) {
    int length = 0;
    struct node *curr = head;
    // Increment length each time we iterate through the linked list
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}
