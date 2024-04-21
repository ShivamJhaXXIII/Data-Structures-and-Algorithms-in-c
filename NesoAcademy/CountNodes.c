#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

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
    printf("\nNumber of nodes in the linked list is: %d", count);
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

     printf("%d %d %d", head->data, head->link->data, head->link->link->data);

     count_of_nodes(head);
}