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
  if (temp == NULL) {
    printf("Memory allocation failed!\n");
    return head;
  }

  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  }

  // Added for clarity: return the newly created node if list was empty
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

Node *addAtAnyPos(Node *head, int data, int pos) {
    Node *newP = NULL;
    Node *temp = NULL;
    Node *temp2 = NULL;
    newP = addToEmpty(newP, data);

    while (pos != 1) {
        temp = temp -> next;
        pos--;
    }

    if(temp -> next == NULL){
        temp -> next = newP;
        newP -> prev = temp;
        newP -> next = NULL;
    }
    else {
        temp2 = temp -> next;
        temp -> next = newP;
        temp2 -> prev = newP;
        newP -> next = temp2;
        newP -> prev = temp;
    }
    return head;

}

Node *reversal(Node *head) {
    Node *ptr1 = head;
    Node *ptr2 = ptr1 -> next;
    ptr1 -> next = NULL;
    ptr1 -> prev = ptr2;
    while(ptr2 != NULL) {
        ptr2 -> prev = ptr2 -> next;
        ptr2 -> next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2 -> prev;
    }
    head = ptr1;
    return head;
    
}

int main () {
    Node *head = NULL;

    head = addToEmpty(head, 45);

    head = addAtBeg(head, 34);

    head  = addAtEnd(head, 75);
    head = reversal(head);

    print_list(head);
    printf("\n");

    // head = addAtAnyPos(head, 9, 1);

    

    // print_list(head);
    // printf("\n");

    return 0;
}