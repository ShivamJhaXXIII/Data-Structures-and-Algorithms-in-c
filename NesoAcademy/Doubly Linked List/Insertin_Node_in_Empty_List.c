#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} Node;

Node *addToEmpty(Node *head, int data) {
    Node *temp = malloc(sizeof(Node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;
}
int main () {
    Node *head = NULL;
    head = addToEmpty(head, 45);
    printf("%d", head -> data);
    return 0;
}