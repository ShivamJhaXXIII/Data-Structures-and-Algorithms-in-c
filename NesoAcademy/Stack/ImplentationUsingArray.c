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
    
    //int op = 3, data;
    int value = 0;

    push(45);
    push(56);
    push(78);

    pop();
    // while(op != 2) {
    //     printf("What operation do you want to perform press 1 for push and 0 for pop or press 2 to exit: ");
    //     scanf("%d", &op);
    //     if(op == 1) {
    //         printf("Enter the data you want to push: ");
    //         scanf("%d", &data);
            
    //         top = push(top, data);
    //     }
    //     if(op == 0) {
    //         top = pop(top);
    //     }

    // }


    print_stack(top);
    
    return 0;

}