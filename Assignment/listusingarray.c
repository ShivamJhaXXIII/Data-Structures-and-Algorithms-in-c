#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int data[MAX_SIZE];
    int size = 0;

    // Insert elements
    if (size < MAX_SIZE) {
        data[size++] = 10;
    } else {
        printf("List is full.\n");
    }

    if (size < MAX_SIZE) {
        data[size++] = 20;
    } else {
        printf("List is full.\n");
    }

    if (size < MAX_SIZE) {
        data[size++] = 30;
    } else {
        printf("List is full.\n");
    }

    // Display elements
    if (size == 0) {
        printf("List is empty.\n");
    } else {
        printf("After inserting elements:\nList: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    // Delete element 20
    if (size == 0) {
        printf("List is empty.\n");
    } else {
        int element = 20;
        int i;
        for (i = 0; i < size; i++) {
            if (data[i] == element) {
                break;
            }
        }

        if (i == size) {
            printf("Element not found.\n");
        } else {
            for (; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    // Display elements after deletion
    if (size == 0) {
        printf("List is empty.\n");
    } else {
        printf("After deleting element 20:\nList: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    return 0;
}
