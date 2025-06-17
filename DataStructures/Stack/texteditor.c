#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_LEN 100

char stack[MAX_SIZE][MAX_LEN];
int top = -1;

// Global variable to store last undone word
char last_word[MAX_LEN] = "";

// Push a string onto the stack
void push(char str[]) {
    if (top == MAX_SIZE - 1) {
        printf("STACK OVERFLOW\n");
    } else {
        top++;
        strcpy(stack[top], str);
    }
}

// Pop the top string from the stack
char* pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return NULL;
    } else {
        char *str = stack[top];
        top--;
        return str;
    }
}

// Peek at the top string
char* peek() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return NULL;
    }
    return stack[top];
}

// Undo the last word
void undo() {
    if (top == -1) {
        printf("Nothing to undo.\n");
        return;
    }
    strcpy(last_word, peek());
    pop();
    printf("Undo: '%s' removed\n", last_word);
}

// Repeat the last undone word
void repeat() {
    if (strlen(last_word) == 0) {
        printf("Nothing to repeat.\n");
        return;
    }
    push(last_word);
    printf("Repeat: '%s' retyped\n", last_word);
}

int main() {
    push("hello");
    push("world");
    printf("Top: %s\n", peek()); // Output: world

    undo();                      // Removes "world"
    printf("Top: %s\n", peek()); // Output: hello

    repeat();                    // Re-adds "world"
    printf("Top: %s\n", peek()); // Output: world

    return 0;
}
