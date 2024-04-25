#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data) {
    
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;

}

void add_at_pos(struct node *head, int data, int pos) {// NOT WORKING
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2 -> data = data;
    ptr2 -> link = NULL;

    
    while (pos > 1) {
        ptr = ptr -> link;
        pos--;
    }
    ptr2 -> link = ptr -> link;
    ptr -> link = ptr2;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    int data = 67, position = 2;

    add_at_pos(head, data, position);
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf("%d", ptr -> data);
        ptr = ptr -> link;
    }
    return 0;

     
}