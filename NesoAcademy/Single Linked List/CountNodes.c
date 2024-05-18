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

struct node* add_at_end(struct node *ptr, int data) {
    
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;

}

int main() {
     struct node *head = NULL;
     head = (struct node*)malloc(sizeof(struct node));
     head -> data = 45;
     head -> link = NULL;

     struct node *ptr = head;
     ptr = add_at_end(ptr, 98);
     ptr = add_at_end(ptr, 3);
     ptr = add_at_end(ptr, 7);

     ptr = head;

     print_data(head);

     count_of_nodes(head);
    
}