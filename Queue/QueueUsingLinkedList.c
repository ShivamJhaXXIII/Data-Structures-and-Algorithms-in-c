#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *front = NULL, *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int data) {
    node *temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> link = NULL;
    if(isEmpty) {
        front = temp;
        rear = temp;
    } 
    rear -> link = temp;
    rear = temp;
}

void dequeue() {
    if(isEmpty) {
        printf("Queue is Empty");
    }
    node *ptr = front;
    front = front -> link;
    printf("%d is dequeued\n", ptr -> data);
    free(ptr);
}

void display() {
    if(isEmpty) {
        printf("No elements to display");
    }
    node *ptr = front;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
}

int main() {
    //enqueue(10);
    enqueue(20);
    //enqueue(30);
    display(); // Output: Queue elements: 10 20 30

    dequeue();
    display(); // Output: Queue elements: 20 30

    return 0;
}