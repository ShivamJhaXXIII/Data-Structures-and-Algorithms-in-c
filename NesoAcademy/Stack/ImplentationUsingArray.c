#include<stdio.h>
#include<stdlib.h>
#define max 10

int stack[max];
int top = -1;

void push(int data) {
    
    if(top == max - 1) {
        printf("Stack overflow\n");
        return;
    } else {
        top++;
        stack[top] = data;
    }
    
}

void pop() {
    if(top >= 0) {
        int value = stack[top];
        
        printf("%d is popped\n", stack[top]);
        stack[top] = 0;
        top--;
    }
    else {
        printf("Stack underflow");
        
    }
    
}

void print_stack() {
    printf("Elements in stack are: ");
    for(int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while(1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the elements of stack\n");
        printf("4. Quit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
            printf("Enter the element you want to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

            case 2: 
            pop();
            break;

            case 3: 
            print_stack();
            break;

            case 4: 
            exit(1);
            break;

            default:
            printf("Wrong choice");
        }
    }  
    return 0;

}