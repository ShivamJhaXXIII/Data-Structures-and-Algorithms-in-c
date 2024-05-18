#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} Node;

void print_list(Node *head) {
    Node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

Node *addToEmpty(Node *head, int data) {
    Node *temp = malloc(sizeof(Node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;
}

Node *addAtBeg(Node *head, int data) {
    Node *temp = malloc(sizeof(Node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    // Creation of the node done
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    return head;
}

void addAtEnd(Node *head, int data) {
    Node *temp = malloc(sizeof(Node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    Node *ptr = head;

    while(ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    temp -> prev = ptr;
    ptr -> next = temp;
    temp -> next = NULL;
}

void addAtAnyPos(Node *head, int data, int pos) {
    Node *temp = malloc(sizeof(Node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    // Creation of the node done
    Node *ptr = head;
    while(pos != 1) {
        ptr = ptr -> next;
        pos--;
    }
    Node *temp2 = ptr -> next;
    ptr -> next = temp;
    temp2 -> prev = temp;
    temp -> next = temp2;
}

int main () {
    Node *head = NULL;

    head = addToEmpty(head, 45);

    head = addAtBeg(head, 34);

    print_list(head);
    printf("\n");

    addAtEnd(head, 75);

    print_list(head);
    printf("\n");

    addAtAnyPos(head, 9, 2);

    print_list(head);
    printf("\n");
    return 0;
}