#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *addToEmpty(int data) {
    node *temp = malloc(sizeof(node));
    if(temp == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    temp -> data = data;
    temp -> prev = temp;
    temp -> next = temp;
    return temp;
}

node *addAtBeg(node *tail, int data)
{
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = NULL;
    
    temp -> next = tail -> next;
    temp -> prev = tail;
    tail -> next = temp;
    return tail;
}

node *addAtEnd(node *tail, int data) 
{
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = NULL;

    if(tail == NULL) {
        temp -> prev = temp;
        temp -> next = temp;
        return temp;
    }

    temp -> prev = tail;
    temp -> next = tail -> next;
    
    tail -> next -> prev = temp;
    tail -> next = temp;
    tail = temp;
    return tail;
}

node *addAtAnyPos(node *tail, int data, int pos) {
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(tail == NULL) {
        if(pos == 1) {
            temp -> next = temp;
            temp -> prev = temp;
            return temp;
        } else {
            printf("Invalid  position\n");
            free(temp);
            return NULL;
        }
    }


    node *ptr = tail -> next;

    if(pos == 1) {
        temp -> next = ptr;
        temp -> prev = tail;
        tail -> next -> prev = temp;
        tail -> next = temp;
        return tail;
    }

    while(pos > 2 && ptr -> next != tail -> next) {
        ptr = ptr -> next;
        pos--;
    }

    temp -> prev = ptr;
    temp -> next = ptr -> next;
    ptr -> next -> prev = temp;
    ptr -> next = temp;

    if(ptr == tail) {
        tail = temp;
    }
    return tail;

}

void print(node *tail) {
    if(tail == NULL) {
        printf("List is empty\n");
        return;
    }
    node *ptr = tail -> next;
    do
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != tail -> next);
    printf("\n");
}

int main() {
    node *tail = NULL;
    tail = addToEmpty(45);
    tail = addAtBeg(tail, 54);
    
    tail = addAtEnd(tail, 3);

    tail = addAtAnyPos(tail, 9, 4);
    print(tail);
    return 0;
}