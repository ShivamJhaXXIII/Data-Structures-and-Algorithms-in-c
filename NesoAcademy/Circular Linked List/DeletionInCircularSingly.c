#include<stdio.h>
#include<stdlib.h>

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

node *createCircularSinglyList(node *tail) {
    int n = 0; int i; int data;
    printf("Enter the number of nodes you want: ");
    scanf("%d", &n);

    if(n == 0) {
        printf("No nodes added");
        return tail;
    }
    else 
    {
        printf("Enter the data for 1 node: ");
        scanf("%d", &data);
        tail = addToEmpty(data);

        for(i = 1; i < n; i++) {
            printf("Enter the data for %d node: ",(i + 1));
            scanf("%d", &data);
            tail = addAtEnd(tail, data);
            }
    }
    return tail;
}

void print(node *tail) 
{
    node *ptr = tail -> next;
    printf("Elements of the node are: ");
    do
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != tail -> next);
    printf("\n");
}

node *delFirst(node *tail)
{
    if(tail == NULL) 
    {
        return tail;
    }
    if(tail -> next == NULL) {
        free(tail);
        tail = NULL;
        return tail;
    }
    node *temp = tail -> next;
    tail -> next = temp -> next;
    free(temp);
    temp = NULL;
    return tail;
}

int main () 
{
    node *tail;
    tail = createCircularSinglyList(tail);
    print(tail);

    tail = delFirst(tail);

    print(tail);
}