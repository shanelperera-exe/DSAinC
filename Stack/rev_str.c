// Reverse a string using a stack

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200

void push(char st[], char c);
char pop(char st[]);
int is_full(char st[]);
int is_empty(char st[]);
void reverse(char st[]);

char stack[MAX_SIZE];
int top = -1;

int main(void) {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    reverse(str);
    return 0;
}

void reverse(char st[]) {
    int i = 0;
    char a[MAX_SIZE];

    while (st[i] != '\0') {
        push(stack, st[i]);
        i++;
    }

    i = 0;
    while (!is_empty(stack)) {
        a[i] = pop(stack);
        i++;
    }

    a[i] = '\0';
    printf("Reversed string: %s\n", a);
}

void push(char stack[], char c) {
    if (is_full(stack)) {
        printf("STACK OVERFLOW\n");
    } else {
        top++;
        stack[top] = c;
    }
}

char pop(char st[]) {
    char c;
    if (is_empty(stack)) {
        printf("STACK UNDERFLOW\n");
    } else {
        c = stack[top];
        top--;
        return c;
    }
}

int is_full(char stack[]) {
    return top == MAX_SIZE - 1;
}

int is_empty(char stack[]) {
    return top == -1;
}