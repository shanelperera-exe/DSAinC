#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int index = 0, i = 0, n;
    int ans;

    int *marks; // this marks pointer hold the base address of  the block created

    marks = (int*)malloc(sizeof(int));

    if (marks == NULL) {
        printf("memory cannot be allocated");
    }
    else {
        // memory has successfully allocated
        printf("Memory has been successfully allocated by using malloc.");
        printf("\nMarks = %pc\n", marks); // print the base or beginning address of allocated memory

        do {
            printf("\nEnter Marks: ");
            scanf("%d", &marks[index]); // Get the marks
            printf("Would you like to add more(1/0): ");
            scanf("%d", &ans);

            if (ans == 1) {
                index++;
                marks = (int*)realloc(marks,(index + 1)* sizeof(int)); // Dynamically reallocate memory by using realloc

                if (marks == NULL) {
                    printf("memory cannot be allocated");
                }
                else {
                    printf("\nMemory has been successfully reallocated using realloc.\n");
                    printf("Base address of marks are:%pc", marks); //print the base or beginning address of allocated memory
                }
            }
        } while(ans == 1);

        printf("\n");
        // print the marks of the students
        for (i = 0; i <= index; i++) {
            printf("Marks of students %d are: %d\n", i,
                   marks[i]);
        }
        free(marks);
    }
    return 0;
}