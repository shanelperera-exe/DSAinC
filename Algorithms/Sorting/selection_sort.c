#include <stdio.h>

void selectionSort(int array[], int size);

int main(void) {
    int num_of_nums = 10;
    int num_arr[num_of_nums];

    for (int i = 0; i < num_of_nums; i++) {
        printf("Enter a number: ");
        scanf("%d", &num_arr[i]);
    }

    selectionSort(num_arr, num_of_nums);
    printf("Sorted Array: ");
    for (int i = 0; i < num_of_nums; i++) {
        printf("%d ", num_arr[i]);
    }
    printf("\n");
    return 0;
}

void selectionSort(int array[], int size) {
    int smallest, temp;
    for (int j = 0; j < size - 1; j++) {
        smallest = j;
        for (int i = j + 1; i < size; i++) {
            if (array[i] < array[smallest]) {
                smallest = i;
            }
        }
        temp = array[j];
        array[j] = array[smallest];
        array[smallest] = temp;
    }
}