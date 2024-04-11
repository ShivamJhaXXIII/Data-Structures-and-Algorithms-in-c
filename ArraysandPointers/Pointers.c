#include<stdio.h>
int main() {
    int a[] = {6,5,4,3,2,1};
    int b = 10;
    int *p;
    p = a; // In p we are storing the base address of the array
    printf("%d \n", b); // this prints the integer value of b
    printf("%d \n", &b); // this prints the address of b in hexadecimal
    p++;// this increments the address held by hte pointet according to the byte size of the data type 
    printf("%p \n", a); // this will print the base address of the array
    printf("%p \n", p);

    printf("%p \n", &p); // this will give the address of the pointer p

    // & operator is called the address of operator

    printf("%d\n", a[2]);// this should print 4
    printf(("%p\n", *(a+2)));// this should also print 4
}