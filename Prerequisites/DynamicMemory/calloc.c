#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // This pointer will hold the base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d",&n);

    // Dynamically allocate memory using calloc()
    ptr = (int*) calloc(n, sizeof(int));

    // Check if the memory has been successfully allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n");
    }

    free(ptr);
    printf("Allocated Memory Successfully freed.\n");

    return 0;
}


/* calloc()

“calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory 
of the specified type. it is very much similar to malloc() but has two different points and these are:
It initializes each block with a default value ‘0’.
It has two parameters or arguments as compare to malloc().

Syntax of calloc() in C:
ptr = (cast-type*)calloc(n, element-size);

here, n is the no. of elements and element-size is the size of each element.

For Example: 
ptr = (float*) calloc(25, sizeof(float));
This statement allocates contiguous space in memory for 25 elements each with the size of the float.

*/