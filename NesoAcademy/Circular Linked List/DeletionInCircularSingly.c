#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;
    struct Node *next;
} node;

// Function to create a node in an empty list
node *addToEmpty(int data) {
    node *temp = malloc(sizeof(node)); // Allocate memory for the new node
    temp->data = data; // Set the data
    temp->next = temp; // Point next to itself to form a circular list
    return temp; // Return the new node (tail)
}

// Function to add a node at the end of the list
node *addAtEnd(node *tail, int data) {
    node *newP = malloc(sizeof(node)); // Allocate memory for the new node
    newP->data = data; // Set the data
    newP->next = tail->next; // Point the new node's next to the head node
    tail->next = newP; // Update the old tail's next to the new node
    tail = newP; // Update the tail to the new node
    return tail; // Return the new tail
}

// Function to create a circular singly linked list
node *createCircularSinglyList(node *tail) {
    int n = 0, i, data;
    printf("Enter the number of nodes you want: ");
    scanf("%d", &n);

    // If no nodes are to be added
    if (n == 0) {
        printf("No nodes added");
        return tail;
    }
    else {
        printf("Enter the data for 1 node: ");
        scanf("%d", &data);
        tail = addToEmpty(data); // Create the first node

        for (i = 1; i < n; i++) { // Loop to add the remaining nodes
            printf("Enter the data for %d node: ", (i + 1));
            scanf("%d", &data);
            tail = addAtEnd(tail, data); // Add each new node at the end
        }
    }
    return tail; // Return the tail of the list
}

// Function to print the list
void print(node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    node *ptr = tail->next; // Start from the head node
    printf("Elements of the node are: ");
    do {
        printf("%d ", ptr->data); // Print the data
        ptr = ptr->next; // Move to the next node
    } while (ptr != tail->next); // Loop until we come back to the head
    printf("\n");
}

// Function to delete the first node of the list
node *delFirst(node *tail) {
    if (tail == NULL) {
        return tail; // If the list is empty, return
    }
    if (tail->next == tail) { // If there's only one node
        free(tail); // Free the node
        tail = NULL; // Set tail to NULL as the list is now empty
        return tail;
    }
    node *temp = tail->next; // The head node
    tail->next = temp->next; // Update the tail's next to the second node
    free(temp); // Free the head node
    temp = NULL; // Set temp to NULL for safety
    return tail; // Return the updated tail
}

// Function to delete the last node of the list
node *delLast(node *tail) {
    if (tail == NULL) {
        return tail; // If the list is empty, return
    }
    node *ptr = tail->next; // Start from the head node
    if (tail->next == tail) { // If there's only one node
        free(tail); // Free the node
        tail = NULL; // Set tail to NULL as the list is now empty
        return tail;
    }
    while (ptr->next != tail) { // Traverse to the second last node
        ptr = ptr->next;
    }
    ptr->next = tail->next; // Update the second last node's next to head
    free(tail); // Free the tail node
    tail = ptr; // Update the tail to the second last node
    return tail; // Return the updated tail
}

// Function to delete a node from any position in a circular linked list
node *delAnyPos(node *tail, int pos) {
    // Check if the list is empty
    if (tail == NULL) {
        return tail;
    }
    
    node *temp = tail->next; // Start from the node next to tail
    
    // If there's only one node in the list
    if (tail->next == tail) {
        free(tail); // Free the only node
        tail = NULL; // Set tail to NULL as list is now empty
        return tail;
    }
    
    node *temp2 = temp->next; // Node to be deleted (next to temp)
    
    // Traverse the list to find the node just before the one to be deleted
    while (pos > 2) {
        temp = temp->next;
        pos--;
    }
    
    temp->next = temp2->next; // Bypass the node to be deleted
    if (temp2 == tail) { // If the node to be deleted is the tail
        tail = temp; // Update tail to the previous node
    }
    free(temp2); // Free the memory of the deleted node
    temp2 = NULL; // Set temp2 to NULL for safety
    
    return tail; // Return the updated tail pointer
}

// Main function to test the list functions
int main() {
    node *tail = NULL;
    tail = createCircularSinglyList(tail); // Create the list
    printf("\nList before deletion: ");
    print(tail); // Print the list before deletion
    
    // Uncomment one of the below lines to test deletion functions
    // tail = delFirst(tail);
    // tail = delLast(tail);
    tail = delAnyPos(tail, 2); // Delete a node from a specific position
    
    printf("\nList after deletion: ");
    print(tail); // Print the list after deletion

    return 0;
}
