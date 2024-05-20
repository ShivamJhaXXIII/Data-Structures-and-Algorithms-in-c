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

void print(node *tail) 
{
    node *ptr = tail -> next;
    do
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != tail -> next);
}

int main() 
{
    node *tail;
    tail = addToEmpty(45);
    tail = addAtBeg(tail, 34);
    
    print(tail);
    return 0;
}