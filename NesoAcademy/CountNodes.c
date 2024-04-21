#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_data(struct node *head) {
    if(head == NULL) 
    printf("Linked List is empty");
    
    struct node *ptr = head;
    
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
    printf("\n");
}

void count_of_nodes(struct node *head) {
    int count = 0;
    if(head == NULL)
    printf("Linked List is Empty");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr -> link;
    }
    printf("Number of nodes in the linked list is: %d", count);
}

void add_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    temp -> data = data;
    temp -> link = NULL;
    
    while(ptr -> link != NULL) {
        ptr = ptr -> link;
    }
    ptr -> link = temp;

}

int main() {
     struct node *head = NULL;
     head = (struct node*)malloc(sizeof(struct node));
     head -> data = 45;
     head -> link = NULL;

     struct node *current = (struct node*)malloc(sizeof(struct node));
     current -> data = 98;
     head -> link = current;
     current -> link = NULL;

     current = malloc(sizeof(struct node));
     current -> data = 3;
     current -> link = NULL;

     head -> link -> link = current;

     print_data(head);

     add_at_end(head, 67);
     print_data(head);

     count_of_nodes(head);
}