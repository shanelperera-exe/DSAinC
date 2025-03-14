// Parenthesis checker to handle ‘(‘ , ‘{‘ and ‘[‘ parenthesis.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200

void push(char st[], char c);
char pop(char st[]);
char peek(char stack[]);
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
    for (int i = 0; i < strlen(exp); i++) {
        char current = exp[i];
        if (current == '(' || current == '{' || current == '[') {
            push(stack, current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (is_empty(stack)) {
                return 0;
            }
            char top_char = peek(stack);
            if ((current == ')' && top_char == '(') || (current == '}' && top_char == '{') || (current == ']' && top_char == '[')) {
                pop(stack);
            }
            else {
                return 0;
            }
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

char peek(char stack[]) {
	if (is_empty(stack)) {
		printf("STACK IS EMPTY\n");
	}
	else {
		return stack[top];
	}
}

int is_full(char stack[]) {
    return top == MAX_SIZE - 1;
}

int is_empty(char stack[]) {
    return top == -1;
}