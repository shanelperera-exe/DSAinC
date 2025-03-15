// Convert Infix expressions (A-B) * (C+D) to Postfix Expressions AB-CD+*

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200

void push(char stack[], char c);
char pop(char stack[]);
char peek(char stack[]);
int is_empty(char stack[]);
int is_full(char stack[]);
void infix_to_postfix(char exp[]);
int precedence(char operator);

char stack[MAX_SIZE];
int top = -1;

int main(void) {
    char infix_exp[MAX_SIZE];

    printf("Infix expression: ");
    fgets(infix_exp, MAX_SIZE, stdin);
    infix_exp[strcspn(infix_exp, "\n")] = '\0';

    infix_to_postfix(infix_exp);

    return 0;
}

void infix_to_postfix(char exp[]) {
    int i = 0;
    char postfix[MAX_SIZE];

    strcat(exp, ")");  // Step 1: Add ")" to the end of the infix expression
    push(stack, '(');  // Step 2: Push "(" onto the stack

    // Step 3
    int j = 0; 
    while (exp[i] != '\0') { // Iterate through the infix expression until each character in the infix notation is scanned
        if (exp[i] == ' ') {  // Skip spaces
            i++;
            continue;
        }
        if (exp[i] == '(') {
            push(stack, exp[i]);  // Push '(' to the stack
        }
        else if (isalnum(exp[i])) {  // If an operand (digit or character) is encountered
            postfix[j] = exp[i]; // Add the operand to the postfix expression.
            j++;
        }
        else if (exp[i] == ')') {  // Handle closing parenthesis
            // Repeatedly pop from stack and add it to the postfix expression until a "(" is encountered.
            while (peek(stack) != '(') {
                postfix[j] = pop(stack);
                j++;
            }
            pop(stack);  // Discard the '(' from the stack
        }
        else {
            while (!is_empty(stack) && precedence(peek(stack)) >= precedence(exp[i])) {
                postfix[j] = pop(stack);  // Pop operators of higher or equal precedence
                j++;
            }
            push(stack, exp[i]);  // Push the current operator onto the stack
        }
        i++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

void push(char stack[], char c) {
	if (is_full(stack)) {
		printf("STACK OVERFLOW\n");
	}
	else {
		top++;
		stack[top] = c;
	}
}

char pop(char stack[]) {
	char c;
	if (is_empty(stack)) {
		printf("STACK UNDERFLOW\n");
	}
	else {
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

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}