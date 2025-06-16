#include <stdio.h>
#include <stdlib.h>

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
    printf("Sum of the array elements: %d\n", sum_arr);
    
    free(arr);    
    return 0;
}