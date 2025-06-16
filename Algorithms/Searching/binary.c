#include <stdio.h>

int binarySearch(int data[], int size, int target);

int main(void) {
    int data[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(data) / sizeof(data[0]);
    int target;
    printf("Enter the value to be searched: ");
    scanf("%d", &target);

    int result = binarySearch(data, size, target);

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found.\n", target);

    return 0;
}

int binarySearch(int data[], int size, int target) {
    int beg = 0;
    int end = size - 1;
    int pos = -1;
    int mid;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (data[mid] == target) {
            pos = mid;
            break;
        } else if (data[mid] > target) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return pos;
}