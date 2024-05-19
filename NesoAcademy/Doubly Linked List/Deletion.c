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
    printf("\n");
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

Node *addAtEnd(Node *head, int data) {
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
    return head;
}

Node *delFirst(Node *head) {
    Node *temp = head;
    head = head -> next;
    free(temp);
    temp = NULL;
    head -> prev = NULL;
    return head;
}

Node *delLast(Node *head) {
    Node *temp = head;
     
    while(temp -> next != NULL) 
    {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
    temp = NULL;
    
    return head;
}

Node *delAnyPos(Node *head, int pos) {
    Node *temp = head;
    Node *temp2, *temp3;
    while(pos > 1) {
        temp = temp -> next;
        pos--;
    }
    temp2 = temp -> prev;
    temp3 = temp -> next;
    temp2 -> next = temp3;
    temp3 -> prev = temp2;
    free(temp);
    temp = NULL;
    return head;
}
int main() {
    Node *head = NULL;
    head = addToEmpty(head, 34);
    head = addAtEnd(head, 45);
    head = addAtEnd(head, 9);

    printf("Before Deletion: \n");
    print_list(head);

    // head = delFirst(head);
    // head = delLast(head);
    head = delAnyPos(head, 2);
    printf("After Deletion: \n");
    print_list(head);
    return 0;
}