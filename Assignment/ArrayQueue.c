//Implementaion of Queue using array
#include <stdio.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is empty
int isEmpty() {
    return front == rear;
}

// Check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Enqueue an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        
        queue[++rear] = data;
        printf("Inserted %d in queue\n", data);
    }
}

// Dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1; // Indicate error or use a different value
    } else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("Deleted %d from queue\n", data);
        return data;
    }
}

// Print the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}
