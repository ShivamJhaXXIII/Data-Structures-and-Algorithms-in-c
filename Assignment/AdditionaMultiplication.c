#include<stdio.h>


int main() {
    int row,column;
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &row, &column);
    int first[row][column];
    for(int i  = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("Enter the element: ");
            scanf("%d", &first[i][j]);
        }
    }
    
    // printf("First matrix:\n");
    // for(int i = 0; i < column; i++) {
    //     for(int j = 0; j < row; j++) {
    //         printf("%d ", first[i][j]);
    //     }
    //     printf("\n");
    // }
    
    
    printf("Enter the Element of second matrix\n");
    int second[row][column];
    for(int i  = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("Enter the element: ");
            scanf("%d", &second[i][j]);
        }
    }
    
    // printf("Second matrix:\n");
    // for(int i = 0; i < column; i++) {
    //     for(int j = 0; j < row; j++) {
    //         printf("%d ", first[i][j]);
    //     }
    //     printf("\n");
    // }
    // int add[row][column];
    // for(int i = 0; i < row; i++) {
    //     for(int j = 0; j < column; j++) {
    //         add[i][j] = first[i][j] + second[i][j];
    //     }
    // }

    int mult[row][column];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            mult[i][j] = first[i][j] * second[i][j];
        }
    }

    printf("Multiplication of the two matrix is:\n");
    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}