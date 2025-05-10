#include <stdio.h>

int main(void) {
    char str[50];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    char* ptr = str;

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}