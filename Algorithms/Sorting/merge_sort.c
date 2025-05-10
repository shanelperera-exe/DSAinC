#include <stdio.h>
#include <limits.h>

void mergeSort(int arr[], int beg, int end);
void merge(int arr[], int left, int mid, int right);

int main(void) {
    int num_of_nums = 10;
    int num_arr[num_of_nums];

    for (int i = 0; i < num_of_nums; i++) {
        printf("Enter a number: ");
        scanf("%d", &num_arr[i]);
    }

    mergeSort(num_arr, 0, num_of_nums - 1);
    printf("Sorted Array: ");
    for (int i = 0; i < num_of_nums; i++) {
        printf("%d ", num_arr[i]);
    }
    printf("\n");
    return 0;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];        
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
    }
}

void mergeSort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}