#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function to print the linked list (remains unchanged)
void print_list(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");  // Add a newline for better readability
}

// Function to reverse the linked list (improved with clear comments)
struct node *reverse_list(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    // Iterate through the list, reversing links
    while (current != NULL) {
        next = current->link;  // Store the next node before overwriting link
        current->link = prev;  // Reverse the link to the previous node
        prev = current;        // Update prev for the next iteration
        current = next;        // Move to the next node
    }

    // Return the new head (the last node in the original list)
    return prev;
}

int main() {
    // Initialize head to point to the first node (elem1)
    struct node *head;

    // Create and link nodes as before
    struct node *elem1 = malloc(sizeof(struct node));
    struct node *elem2 = malloc(sizeof(struct node));
    struct node *elem3 = malloc(sizeof(struct node));
    struct node *elem4 = malloc(sizeof(struct node));
    struct node *elem5 = malloc(sizeof(struct node));

    elem1->data = 45;
    elem2->data = 98;
    elem3->data = 3;
    elem4->data = 95;
    elem5->data = 100;

    elem1->link = elem2;
    elem2->link = elem3;
    elem3->link = elem4;
    elem4->link = elem5;
    elem5->link = NULL;

    head = elem1;

    // Print the original list
    printf("Original list: ");
    print_list(head);

    // Reverse the list
    head = reverse_list(head);

    // Print the reversed list
    printf("Reversed list: ");
    print_list(head);

    // Free the allocated nodes (avoid memory leaks)
    free(elem1);
    free(elem2);
    free(elem3);
    free(elem4);
    free(elem5);

    return 0;
}
