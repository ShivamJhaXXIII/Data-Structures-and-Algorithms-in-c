#include <stdio.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (isEmpty) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1; // Indicate error or special value
    }

    int data = queue[front];

    if (front == rear) {
        front = rear = -1; // Reset if only one element
    } else {
        front++;
    }

    return data;
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: Queue elements: 10 20 30

    printf("Dequeued element: %d\n", dequeue()); // Output: Dequeued element: 10
    display(); // Output: Queue elements: 20 30

    return 0;
}
