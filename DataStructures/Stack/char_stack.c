#include <stdio.h>

#define MAX_SIZE 10

char stack[MAX_SIZE];
int top = -1;

void push(char stack[], char c);
char pop(char stack[]);
char peek(char stack[]);
int isEmpty(char stack[]);
int isFull(char stack[]);
void display(char stack[]);

int main(void) {
	int option;
	char c;
	
	do {
		printf("\nMAIN MENU\n");
		printf("[1] Push\n");
		printf("[2] Pop\n");
		printf("[3] Peek\n");
		printf("[4] Display\n");
		printf("[5] Exit\n");
		
		printf("Enter an option: ");
		scanf("%d", &option);
		
		switch(option) {
			case 1:
				printf("Enter the character to be pushed on stack: ");
				scanf(" %c", &c);
				push(stack, c);
				break;
			case 2:
				c = pop(stack);
				if (c != -1) {
					printf("Character removed from the stack: %c\n", c);
				}
				break;
			case 3:
				c = peek(stack);
				printf("Character stored at top of the stack: %c\n", c);
				break;
			case 4:
				display(stack);
				break;
	}
	
	} while(option != 5);
	return 0;
}

void push(char stack[], char c) {
	if (isFull(stack)) {
		printf("STACK OVERFLOW\n");
	}
	else {
		top++;
		stack[top] = c;
	}
}

char pop(char stack[]) {
	char c;
	if (isEmpty(stack)) {
		printf("STACK UNDERFLOW\n");
	}
	else {
		c = stack[top];
		top--;
		return c;
	}
}

char peek(char stack[]) {
	if (isEmpty(stack)) {
		printf("STACK IS EMPTY\n");
	}
	else {
		return stack[top];
	}
}

int isEmpty(char stack[]) {
	return top == -1;
}

int isFull(char stack[]) {
	return top == MAX_SIZE - 1;
}

void display(char stack[]) {
	if (isEmpty(stack)) {
		printf("STACK IS EMPTY\n");
	}
	else {
		printf("Stack elements are:\n");
		for(int i = top; i >= 0; i--) {
			printf("%c\n", stack[i]);
		}
	}
}
