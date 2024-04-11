#include<stdio.h>
int main() {
    int a[] = {6,2,4,3,0};  // Taking an array during compile time
    int i;
    a[2] = 10;// Here you can see we replaced the value of the array of index 2 i.e. the third element from 4 to 10.
    // But in this scenario the 4 is lost
    printf("The elemnets of the array are ");
    for(i = 0; i<5; i++) {
        printf("%d, ", a[i]);
    }
    // What if we need to add an element at specific position but also require all the other elements

    int b[50],size, num, pos;
     printf("Enter the size of the array");
    scanf("%d", &size);

    printf("Enter the elements of the array :");
        for(i = 0; i < size; i++) {
        scanf("%d" , & b[i]);
    }

     

    // Now we want to add 2 to index no 3 while keeping all the other elements

    printf("Enter the element you want to add");
    scanf("%d", &num);
    printf("Enter the position ");
    scanf("%d", &pos);

    for (i = size - 1; i >= pos - 1; i-- ) { 
        b[i + 1] = b[i];
        
    }
    b[pos] = num;
    size++;
    printf("The elements of the array are :");

    for(i = 0; i< size; i++) {  // This block prints the elements of the array
        printf("%d, ", b[i]);
    }

}