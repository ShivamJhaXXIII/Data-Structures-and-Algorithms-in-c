#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} node;

node *push(node *head){
    int n; int data;
    printf("Enter how many elements you want to push: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter the element for %d index: ", i);
        scanf("%d", &data);

        node *temp = malloc(sizeof(node));
        if(temp == NULL) {
            printf("Memory allocation failed");
            return head;
        }
        temp -> data = data;
        temp -> link = NULL;

        if(head == NULL) {
            head = temp;
        } 
        else{  
        node *ptr = head;
        while(ptr -> link != NULL) {
            ptr = ptr -> link;
        }
    
        ptr -> link = temp;
        }
        printf("%d pushed successfully\n", data);
    
    }
    
    return head;
}

void print(node *head) {
    node *ptr = head;
    printf("The elements in the stack are: ");
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
    printf("\n");
}


int main() {
    node *head = NULL;
    head = push(head);

    print(head);

     node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
    
}