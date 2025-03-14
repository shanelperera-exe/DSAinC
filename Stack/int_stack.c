#include <stdio.h>

#define MAX 8

int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int isEmpty();
int isFull();

int main(int argc, char *argv[]) {
    int val, option;
    do {
        printf("\n***** MAIN MENU ****** ");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nEnter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
            case 2:
                val = pop(st);
                if(val != -1) {
                    printf("\nThe value deleted from stack is: %d", val);
                    break;
                }
            case 3:
                val = peek(st);
                if(val != -1) {
                    printf("\nThe value stored at top of stack is: %d", val);
                    break;
                }
            case 4:
                display(st);
                break;
        }
    } while (option != 5);
    return 0;
}

void push(int st[], int val) {
    if (isFull()) {
        printf("STACK OVERFLOW\n");
    }
    else {
        top++;
        st[top] = val;
    }
}

int pop(int st[]) {
    int val;
    if (isEmpty()) {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else {
        val = st[top];
        top--;
        return val;
    }
}

int peek(int st[]) {
    if (isEmpty()) {
        printf("STACK IS EMPTY\n");
        return -1;
    }
    else {
        return (st[top]);
    }
}

void display(int st[]) {
    if (isEmpty()) {
        printf("STACK IS EMPTY\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", st[i]);
        }
    }
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}