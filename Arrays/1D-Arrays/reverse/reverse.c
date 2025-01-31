#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, int size);

int main(void) {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) { 
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    int sum_arr = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter the array items: ");
        scanf("%d", &arr[i]);
        sum_arr += arr[i];
    }

    reverse_array(arr, n);

    printf("New Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}

void reverse_array(int *arr, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}