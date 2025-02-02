#include <stdio.h>

int main(void) {
    int m;

    printf("Enter an Integer for variable m: ");
    scanf("%d", &m);

    int *ptr = &m;

    printf("The Value of Variable m is: %d\n", *ptr);
    printf("The Memory Address of Variable m is: %p\n", ptr);

    ptr++;
    printf("The Memory Address of the next Memory Block: %p\n", ptr);

    return 0;
}