#include<stdio.h> 

int main() {
    int row, column;
    
    printf("Enter the order of the matrix");
    scanf("%d %d", &row, &column);
    

    int data[row][column];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("Enter the element: ");
            scanf("%d", &data[i][j]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}