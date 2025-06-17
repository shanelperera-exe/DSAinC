//  For each element in an array, find the next greater element to the right.

#include <stdio.h>

#define MAX 100

void nextGreater(int arr[], int n) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[stack[top]]) {
            int index = stack[top--];
            printf("%d -> %d\n", arr[index], arr[i]);
        }
        stack[++top] = i;
    }

    while (top != -1)
        printf("%d -> -1\n", arr[stack[top--]]);
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}
