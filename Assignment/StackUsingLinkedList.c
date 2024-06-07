//Implementation of stack as data structure using linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} node;

node* push(node* head, int data) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) { // Check for allocation failure
        printf("Memory allocation error\n");
        return head;
    }

    temp -> data = data;
    // if(head == NULL) {
    //     head = temp;
    //     return head;
    // }
    //else { 
    temp -> link = head;
    head = temp;
    return head;
    //}
}

node* pop(node* head) {
    if(head == NULL) {
        printf("Stack Underflow");
        return NULL;
    }
    // if(head -> link == NULL) {
    //     printf("%d is popped\n", head -> data);
    //     return NULL;
    // }
    
        node *temp = head;
        head = head -> link;
        free(temp);
    
    return head;
}

void print(node *head) {
    node *ptr = head;
    if(head == NULL) {
        printf("There are no elements in stack");
    }
    else {
        while(ptr != NULL) {
            printf("%d ", ptr -> data);
            ptr = ptr -> link;
        }
    }
    printf("\n");
}

int main () {
    node *head = NULL;
    head = push(head, 45);
    head = push(head, 65);

    print(head);

    head = push(head, 5);
    
    print(head);

    head = pop(head);
    
    print(head);

    head = pop(head);
    print(head);

    return 0;
}

// Output:
// 65 45 
// 5 65 45 
// 65 45 
// 45
