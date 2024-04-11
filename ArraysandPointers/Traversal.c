/*Array traversal is the process of accessing and examining each element in an array.
 It allows you to perform operations on every element or search for specific values within the array.*/
#include<stdio.h>
int main() {
    int a[50], size,i;
    printf("Enter the size of the array");
    scanf("%d", &size);  //Tsking the size of the array from the user

    if(size > 50){  
        /*This block is important because
        if the person enters size of the 
        array to be greater than 50 they
        can enter the elements more than
        50 but the memory allocated for 
        this array atmost can be 50.
        Thus, the program will crash*/
        printf("Size of the array cannot be greater than 50");
    }
    else{
        /*In this block we are accepting 
        the elements of the array one by one
        from user.*/
        printf("Enter the elements of the array :");
        for(i = 0; i < size; i++) {
        scanf("%d" , & a[i]);
    }
    printf("The elements of the array are :");

    for(i = 0; i< size; i++) {  // This block prints the elements of the array
        printf("%d, ", a[i]);
    }
    }
    
}