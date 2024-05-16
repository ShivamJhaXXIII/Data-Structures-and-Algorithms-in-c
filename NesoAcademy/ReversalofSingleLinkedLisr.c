#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_list(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data); // Print data value
        ptr = ptr->link;
    }
    printf("\n");
}

struct node* reverasl_of_list(struct node *head){
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL){
        next = head -> link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}
int main () {
    struct node *head;
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

    print_list(head);

    head = reverasl_of_list(head);

    print_list(head);

    free(elem1);
    free(elem2);
    free(elem3);
    free(elem4);
    free(elem5);
    return 0;

}