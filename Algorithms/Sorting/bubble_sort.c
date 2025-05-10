#include <stdio.h>

void bubbleSort(int array[], int size);

int main(void) {
    int num_of_nums = 10;
    int num_arr[num_of_nums];

    for (int i = 0; i < num_of_nums; i++) {
        printf("Enter a number: ");
        scanf("%d", &num_arr[i]);
    }

    bubbleSort(num_arr, num_of_nums);
    printf("Sorted Array: ");
    for (int i = 0; i < num_of_nums; i++) {
        printf("%d ", num_arr[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int array[], int size) {
    int temp;
    for (int pass = 0; pass < (size - 1) - 1; pass++) {
        for (int i = 0; i < (size - 1- pass); i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}