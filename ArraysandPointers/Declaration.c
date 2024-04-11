#include<stdio.h>
int main() {
    int a[] = {6,2,4,3,0};  // Taking an array during compile time

    printf("%d", a[2]);
    printf("\n");

    int b[5],i;
    printf("Enter the elements of the array :");
    for (i = 0; i<5; i++) {                             // Declaration of the array at runtime by the user
        
        scanf("%d", & b[i]);
    }
    printf("The elemnets of the array are ");
    for(i = 0; i<5; i++) {
        printf("%d, ", b[i]);
    }

}