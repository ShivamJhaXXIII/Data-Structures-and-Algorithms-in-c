// https://www.youtube.com/watch?v=6wXZ_m3SbEs&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=10
#include<stdio.h>
#include<stdlib.h>
// This is user defined data type for storing the data and a pointer
int main() {  
    struct node {
    int data;// this will store the integer value
    struct node *next;// this shall store the address to next element in list
};

struct node *head, *newnode, *temp;// here head will store the address of the first element of the list
// newnode will store the address of newly formed nodes
// temp will take the address from newnode and give it to struct node *next
head = NULL;
int choice = 1;

while (choice == 1)
{
    newnode = (struct node *)malloc(sizeof(struct node));// malloc function is used to assign the memory using dyanamic memory allocation
// we use malloc to assign the memory of size struct node data type which stores integer value and a pointer value
// (struct node*) before malloc is type casting malloc to return the value of struct node data type instead of void data type
// which is then stored in newnode variable
printf("Enter data");
scanf("%d", & newnode -> data);// newnode -> data means we want to store the data in the node at which newnode pointer is pointing
// we have stored the data entered by the user at runtime in the data variable of struct node
    newnode -> next = 0;// in this line we are giving initial value to the pointer part of struct node
if(head == NULL) {  // This if block is to give the pointer head the address of first node of the linked list instead of null
    head = temp = newnode;// for the first time when node is made in above code the newcode pointer holds the address to newly formed node which is here assigned to head.
}
else {
    temp -> next = newnode;// in this line when next will be storing the address of newnode
    temp = newnode;
}
printf("Do you want to continue (0,1)?");// This is to let user decide how many nodes they want to make.
scanf("%d", &choice);
}



temp = head;
while(temp!=0) {
    printf("%d", temp -> data);
    temp = temp ->next;
}
return 0;
} 