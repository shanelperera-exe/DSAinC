#include <stdio.h>

int linear_search(int arr[], int size, int target);

int main(void) {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int num_arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &num_arr[i]);
    }

    printf("Enter the target value to be searched: ");
    scanf("%d", &target);

    int result = linear_search(num_arr, n, target);

    if (result != -1) {
        printf("Value %d is present at index %d.\n", target, result);
    } else {
        printf("Value %d is not present in the array.\n", target);
    }

    return 0;
}

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
