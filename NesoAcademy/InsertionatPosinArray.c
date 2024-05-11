#include <stdio.h>

void  add_at_pos(int arr[], int arr2[], int n, int data, int pos)
{
    int i;
    int index = pos - 1;
    for(i = 0; i < index; i++) {
        arr2[i] = arr[i];
    }
    arr2[index] = data;
    int j;
    for(i = index + 1, j = index; i < n+1, j < n ; i++, j++) {
        arr2[i] = arr[j];
    }

}

int main() {
    int arr[] = {2,34,5,6,98,50};
    int pos, data,i;
    printf("Enter the data and then the position");
    scanf("%d%d", &data, &pos);
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr2[size + 1];
    add_at_pos(arr, arr2, size, data, pos);
    for ( i = 0; i < size+1; i++) {
        printf("%d", arr2[i]);
    }
}