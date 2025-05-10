// Checks whether an expression has a balanced parenthesis using a stack.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200

void push(char st[], char c);
char pop(char st[]);
int is_full(char st[]);
int is_empty(char st[]);
int check_expression(char exp[]);

char stack[MAX_SIZE];
int top = -1;

int main(void) {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    
    fgets(exp, MAX_SIZE, stdin);
    exp[strcspn(exp, "\n")] = '\0';
    
    if (check_expression(exp)) {
        printf("Balanced\n");
    }
    else {
        printf("Not Balanced\n");
    }
    return 0;
}

int check_expression(char exp[]) {
    for(int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')') {
            if (is_empty(stack)) {
                return 0;
            }
            pop(stack);
        }
    }
    return is_empty(stack);
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