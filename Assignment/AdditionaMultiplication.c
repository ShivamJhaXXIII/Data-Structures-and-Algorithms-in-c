#include<stdio.h>


int main() {
    int row,column,row1,column1;
    printf("Enter the order of first matrix: ");
    scanf("%d %d", &row, &column);
    int first[row][column];
    for(int i  = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("Enter the element: ");
            scanf("%d", &first[i][j]);
        }
    }

    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            printf("%d ", first[i][j]);
        }
        printf("\n");
    }

    printf("Enter the order o")
    int second[row1][column1];
    for(int i  = 0; i < row1; i++) {
        for(int j = 0; j < column1; j++) {
            printf("Enter the element: ");
            scanf("%d", &second[i][j]);
        }
    }

}