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

node *createDoublyList(node *tail) {
    
    int data; int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(tail == NULL) {
        printf("Enter the 1 element: ");
        scanf("%d", &data);
        tail = addToEmpty(data);
    }

    for(int i = 1; i < n; i++) {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
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
node *delFirst(node *tail) {
    if(tail == NULL) {
        printf("No nodes to delete\n");
        return tail;
    }
    if(tail -> next == tail) {
        free(tail);
        return NULL;
    }
    node *temp = tail -> next;
    tail -> next = temp -> next;
    temp -> next -> prev = tail;
    free(temp);
    return tail;
}

node *delLast(node *tail) {
    if(tail == NULL) {
        printf("No nodes to delete");
        return tail;
    }
    if(tail -> next == tail)
    {
        free(tail);
        return NULL;
    }
    node *temp = tail -> prev;
    temp -> next = tail -> next;
    tail -> next -> prev = temp;
    free(tail);
    tail = temp;
    return tail;
}

node *delAnyPos(node *tail, int pos) {
    if(tail == NULL){
        printf("No nodes to delete");
        return NULL;
    }
    node *temp = tail -> next;
    while(pos > 1) {
        temp = temp -> next;
        pos--;
    }
    node *temp2 = temp -> prev;
    temp2 -> next = temp -> next;
    temp -> next -> prev = temp2;
    free(temp);
    if(temp == tail) {
        tail = temp2;
    }
    return tail;
}

int main() 
{
    node *tail;
    tail = addToEmpty(45);
    tail = addAtEnd(tail, 54);
    tail = addAtEnd(tail, 6);

    print(tail);

    //tail = delFirst(tail);
    //tail = delLast(tail);
    tail = delAnyPos(tail, 3);
    print(tail);
    return 0;
}

