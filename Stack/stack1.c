#include <stdio.h>

#define MAX 8

int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

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
        printf("\n");
        
        switch(option) {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
            case 2:
                val = pop(st);
                if(val != -1) {
                    printf("\n The value deleted from stack is: %d", val);
                    break;
                }
            case 3:
                val = peek(st);
                if(val != -1) {
                    printf("\n The value stored at top of stack is: %d", val);
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
    if (top == MAX - 1) {
        printf("STACK OVERFLOW\n");
    }
    else {
        top++;
        st[top] = val;
    }
}

int pop(int st[]) {
    int val;
    if (top == -1) {
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
    if (top == -1) {
        printf("STACK IS EMPTY\n");
        return -1;
    }
    else {
        return (st[top]);
    }
}

void display(int st[]) {
    if (top == -1) {
        printf("STACK IS EMPTY\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", st[i]);
        }
    }
}