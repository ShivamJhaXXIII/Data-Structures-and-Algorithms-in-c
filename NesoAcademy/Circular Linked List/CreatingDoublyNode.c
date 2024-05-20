#include<Stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *circularSingly(int data) {
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = temp;
    temp -> prev = temp;
    return temp;
}

int main() 
{
    int data = 45;
    node *tail;
    tail = circularSingly(data);
    
    printf("%d ", tail -> data);
    return 0;
}