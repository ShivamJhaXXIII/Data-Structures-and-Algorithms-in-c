// https://www.youtube.com/watch?v=T_UXDTy23DQ&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=31

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = 0;

int push(int x) {
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode -> data = x;
    newnode -> next = top;
    top = newnode;
}

int display() {
    struct node *temp;
    if(top == 0) {
        printf("No data to be displayed");
    }
    else {
        while (temp != 0) {
            printf("%d", temp -> data);
        }
    }
}