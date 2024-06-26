#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

void print_list(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data); // Print data value
        ptr = ptr->link;
    }
}

struct Node* del_first(struct Node *head)
{
    if(head == NULL){
        printf("List is Epty");
    }
    else 
    {
        struct Node *temp = head;
        head = head -> link;
        free(temp);
        temp = NULL;
    }
    return head;
}

struct Node *del_last(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is empty");
    }
    else if(head -> link == NULL)
    {
        free(head);
        head = NULL;
    }
    else 
    {
        struct Node *temp = head;
        struct Node *temp2 = head;
        while( temp -> link != NULL)
        {
            temp2 = temp;
            temp = temp -> link;
        }
        temp2 -> link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

void del_any_pos(struct Node **head, int pos) 
{
    struct Node *previous = head;
    struct Node *current = head;
    if(*head == NULL) {
        printf("List is Empty");
    } 
    else if( pos == 1 )
    {
        *head = current -> link;
        free(current);
        current = NULL;
    }
    else 
    {
        while(pos != 1)
        {
            previous = current;
            current = current -> link;
            pos--;
        }
        previous -> link = current -> link;
        free(current);
        current = NULL;
    } 
    return 0;
}

struct Node *del_list(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL) {
        temp = temp -> link;
        free(head);
        head = temp;
    }
    return head;
}


int main() {
    struct Node* elem1 = malloc(sizeof(struct Node)); // Allocate for Node
    struct Node* elem2 = malloc(sizeof(struct Node));
    struct Node* elem3 = malloc(sizeof(struct Node));

    elem1->data = 45;
    elem2->data = 98;
    elem3->data = 3; 

    elem1->link = elem2;
    elem2->link = elem3;
    elem3->link = NULL;

    struct Node* head = elem1;

    print_list(head);

    //head = del_first(head);
    
    //print_list(head);

    head = del_last(head);

    print_list(head);

    free(elem1); // Free allocated memory (repeat for elem2 and elem3)
    free(elem2);
    free(elem3);

    return 0;
}
