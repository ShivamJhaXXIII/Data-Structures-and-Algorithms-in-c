// // Implementation using array

// #include<stdio.h>
// #define N 5
// int stack[N];
// int top = -1;

// int push(int x) {
    
    
    
//     if( top == N - 1) {
//         printf("Overflow condition");
//     }
//     else {
//         top++;
//         stack[top] = x; 
//     }
//     return 0;
// }

// int pop() {
//     int item;
//     if(top == -1) {
//         printf("Underflow");
//     }
//     else {
//         item = stack[top];
//         top--;
//     }
//     return 0;
// }

// int peek() {
//     if(top == -1) {
//         printf("No data");
//     }
//     else {
//         printf("%d", stack[top]);
//     }
//     return 0;
// }

// int display() {
//     int i;
//     for(i = top; i>=0; i--) {
//         printf("%d", stack[i]);

//     }
//     return 0;
// }

// int main() {
//     int ch = 1;
//     while (ch!=0){
//     printf("Enter 1 for push, Enter 2 for peek, Enter 3 for pop, Enter 4 to display, Enter 0 to exit");
//     scanf("%d", &ch);

//     switch(ch)
//     {
//         case 1 :
//         {
//             int x;
//             printf("Enter the number you want to push");
//             scanf("%d", &x);
//             push(x);
//             break;
//         }
//         case 2: {
//             peek();
//             break;
//         }
//         case 3: {
//             pop();
//             break;
//         }
//         case 4: {
//             display();
//             break;
//         }
//         default: {
//             printf("Invalid choice");
//         }


//     }
//     }
//     return 0;
// }







#include<stdio.h>
#define N 5
int stack[N];
int top = -1;

int push(int x) {
    if (top == N - 1) {
        printf("Overflow condition\n");
        return -1; // Indicate failure to push
    } else {
        top++;
        stack[top] = x;
        return 0; // Indicate successful push
    }
}

int pop() {
    int item;
    if (top == -1) {
        printf("Underflow\n");
        return -1; // Indicate failure to pop
    } else {
        item = stack[top];
        top--;
        return item; // Return the popped item
    }
}

void peek() {
    if (top == -1) {
        printf("No data\n");
    } else {
        printf("%d\n", stack[top]);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch = -1; // Initialize ch to a value outside the valid menu options
    while (ch != 0) {
        printf("Enter 1 for push, Enter 2 for peek, Enter 3 for pop, Enter 4 to display, Enter 0 to exit: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int x;
                printf("Enter the number you want to push: ");
                scanf("%d", &x);
                if (push(x) == -1) {
                    printf("Failed to push. Stack is full.\n");
                }
                break;
            }
            case 2: {
                peek();
                break;
            }
            case 3: {
                int popped = pop();
                if (popped != -1) {
                    printf("Popped item: %d\n", popped);
                } else {
                    printf("Failed to pop. Stack is empty.\n");
                }
                break;
            }
            case 4: {
                display();
                break;
            }
            case 0: {
                printf("Exiting the program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    return 0;
}
