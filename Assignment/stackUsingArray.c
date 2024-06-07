//Implementaion of stack using array
#include<stdio.h>

int stack[10];
int top = -1;

void push(int data) {
    if(top > 9) {
        printf("Stack overflow");
        return;
    }
    else {
        stack[++top] = data;
    }
}

void pop() {
    int data;
    if(top == -1) {
        printf("Stack Underflow");
        return;
    }
    else {
        data = stack[top];
        stack[top] = 0;
        printf("%d is popped\n", data);
        top--;
    }
}

void print() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]); // Print from top to bottom
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int data;
    while(1) { 
    printf("press 1 for push, 2 for pop, 3 to print the stack, 4 to exit program");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {  
        printf("Enter the data you want to push\n");
        scanf("%d", &data);
        push(data);
        break;
        }
        case 2: {
            pop();
            break;
        }
        case 3:{ 
        print();
        break;
        }

        case 4: { 
        exit(1);
        break;
        }

        default :
        printf("Incorrect choice\n");
    }
    }
    return 0;
}