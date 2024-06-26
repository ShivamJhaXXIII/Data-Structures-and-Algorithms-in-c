#include<stdio.h>
#include<Stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *addToEmpty(int data) 
{
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}

node *addAtBeg(node *tail, int data) 
{
    node *newP = malloc(sizeof(node));
    newP -> data = data;
    newP -> next = tail -> next;
    tail -> next = newP;
    return tail;
}

node *addAtEnd(node *tail, int data)
{
    node *newP = malloc(sizeof(node));
    newP -> data = data;
    newP -> next = NULL;

    newP -> next = tail -> next;
    tail -> next = newP;
    tail = newP;
    return tail;
}

node *addAtAnyPos(node *tail, int data, int pos) 
{
    node *newP = malloc(sizeof(node));
    newP -> data = data;
    newP -> next = NULL;

    node *ptr = tail -> next;

    while (pos > 1) {
        ptr = ptr -> next;
        pos--;
    }

    if(ptr == tail) {
        newP -> next = tail -> next;
        tail -> next = newP;
        tail = tail -> next;
    } else {
        newP -> next = ptr -> next;
        ptr -> next = newP;
    }
    return tail;
}

void print(node *tail) 
{
    node *ptr = tail -> next;
    do
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != tail -> next);
    printf("\n");
}



int main() 
{
    node *tail;
    tail = addToEmpty(45);
    tail = addAtBeg(tail, 34);
    tail = addAtEnd(tail, 6);
    tail = addAtEnd(tail, 56);
    
    print(tail);

    tail = addAtAnyPos(tail, 66, 4);

    print(tail);
    return 0;
}