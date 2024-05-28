#include<stdio.h>
#include<stdlib.h>
#define max 10

int stack[max];

int push(int top, int data) {
    
    if(top == max - 1) {
        top++;
        stack[top] = data;
    } else {
        printf("Stack overflow");
    }
    return top;
}

int pop(int top) {
    if(top >= 0) {
        stack[top] = 0;
        top--;
    }
    else {
        printf("Stack underflow");
    }
    return top;
}

void print_stack(int top) {
    printf("Elements in stack are: ");
    for(int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int top = -1;
    int op = 3, data;
    while(op != 2) {
        printf("What operation do you want to perform press 1 for push and 0 for pop or press 2 to exit: ");
        scanf("%d", &op);
        if(op == 1) {
            printf("Enter the data you want to push: ");
            scanf("%d", &data);
            
            top = push(top, data);
        }
        if(op == 0) {
            top = pop(top);
        }

    }


    print_stack(top);
    
    return 0;

}