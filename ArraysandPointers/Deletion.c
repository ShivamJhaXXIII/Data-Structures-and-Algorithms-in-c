#include<stdio.h>
int main() {
    int b[50],i, pos, size;
    printf("Enter the size of the array");
    scanf("%d", &size);
    
    printf("Enter the elements of the array :");
    for (i = 0; i<size; i++) {                             // Declaration of the array at runtime by the user
        
        scanf("%d", & b[i]);
    }
    printf("The elemnets of the array are ");
    for(i = 0; i<size; i++) {
        printf("%d ", b[i]);
    }

    printf("Enter the position from where you want to delete the element");
    scanf("%d", &pos);

    for(i = pos - 1; i < size; i++) {
        b[i] = b[i + 1];
    }
    size--;
    

    printf("The elemnets of the array are ");
    for(i = 0; i<5; i++) {
        printf("%d ", b[i]);
    }
}