// Convert an infix expression into postfix expression

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200

void push(char st[], char c);
char pop(char st[]);
int is_full(char st[]);
int is_empty(char st[]);
void infix_to_postfix(char stack[], char exp[]);

char stack[MAX_SIZE];
int top = -1;

int main(void) {
    char infix_exp[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(infix_exp, MAX_SIZE, stdin);
    infix_exp[strcspn(infix_exp, "\n")] = '\0';
    infix_to_postfix(stack, infix_exp);
    return 0;
}

void infix_to_postfix(char stack[], char exp[]) {
    char postfix[MAX_SIZE];
    
    strcat(exp, ")");
    push(stack, '(');

    for(int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            push(stack, '(');
        }
    }
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