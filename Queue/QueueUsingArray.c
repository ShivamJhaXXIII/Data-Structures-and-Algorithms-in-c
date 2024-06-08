#include<stdio.h>
#define max 10

int queue[max];

int enque(int data, int rear) {
    if(rear < max - 1) {
        queue[++rear] = data;
        return rear;
    } else {
        printf("Queue oveflow");
        return rear;
    }
}

int deque(int front, int rear) {
    for(int i = front; i <= rear; i++) {
        queue[i] = queue[i+1];
    }
    --rear;
    return rear;
}

void print(int front, int rear) {
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int front = 0, rear = -1;
    rear = enque(45, rear);
    rear = enque(5, rear);
    rear = enque(55, rear);

    print(front, rear);

    rear = deque(front, rear);
    print(front, rear);
    return 0;
}