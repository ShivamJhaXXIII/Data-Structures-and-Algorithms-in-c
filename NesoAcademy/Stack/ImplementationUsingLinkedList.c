#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* link;
} node;

// Function to push elements onto the stack
node* push(node* head) {
    int n, data;
    printf("Enter how many elements you want to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element for %d index: ", i);
        scanf("%d", &data);

        // Allocate memory for a new node
        node* temp = malloc(sizeof(node));
        if (temp == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            return head;
        }
        temp->data = data;  // Set the data for the new node
        temp->link = NULL;  // New node will be the last node, so link is NULL

        if (head == NULL) {
            // If the list is empty, the new node becomes the head
            head = temp;
        } else {
            // Traverse to the end of the list
            node* ptr = head;
            while (ptr->link != NULL) {
                ptr = ptr->link;
            }
            // Link the new node at the end of the list
            ptr->link = temp;
        }
        printf("%d pushed successfully\n", data);
    }

    return head;  // Return the updated head of the list
}

node *pop(node *head) {
    
    char ch = 'y';
    while(ch == 'y') {

        if(head == NULL) {
            printf("There are no elements to perform pop operation");
            return head;
        } else {
            if(head -> link == NULL) {
                free(head);
                head = NULL;
            } else { 
            node *ptr = head;
            while(ptr -> link != NULL) {
                ptr = ptr -> link;
            }
            free(ptr -> link);
            ptr -> link = NULL;
            
        }
        }
        printf("Do you want to continue y or n \n");
        while (getchar() != '\n'); // Clear the input buffer
        scanf("%c", &ch);
    }
    return head;
}

// Function to print the elements of the stack
void print(node* head) {
    node* ptr = head;
    printf("The elements in the stack are: ");
    while (ptr != NULL) {
        // Print the data of each node
        printf("%d ", ptr->data);
        ptr = ptr->link;  // Move to the next node
    }
    printf("\n");
}

int main() {
    node* head = NULL;  // Initialize head to NULL

    // Push elements onto the stack
    head = push(head);

    // Print the elements of the stack
    print(head);

    head = pop(head);

    print(head);

    // Free the allocated memory to avoid memory leaks
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }

    return 0;  // Return 0 to indicate successful execution
}
