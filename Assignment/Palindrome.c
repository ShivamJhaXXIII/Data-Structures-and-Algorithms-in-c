#include<stdio.h>

// #define max_size 10

int main() {
    int n;
    
    printf("Enter the no. of elements in list");
    scanf("%d", &n);

    int data[n];

    for(int i = 0; i < n; i++) {
        printf("Enter the element");
        scanf("%d", &data[i]);
    }
    
    int isPalindrome = 1;
    for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        if(data[i] != data[j]) {
            isPalindrome = 0;
        }
    }

    if(isPalindrome) {
        printf("This is a palindrome list");
    } else {
        printf("This is not a palindrome list");
    }
    return 0;
}
