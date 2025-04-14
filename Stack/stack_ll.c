#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10;

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *push(struct node *top, int val);
struct node *pop(struct node *top);
int peek(struct node *top);
void display(struct node *top);

int main(void) {
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
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if(val != -1) {
                    printf("\nThe value stored at top of stack is: %d\n", val);
                    break;
                }
            case 4:
                display(top);
                break;
        }
    } while (option != 5);
    return 0;
}

struct node *push(struct node *top, int val) {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;

    if (top == NULL) {
        new_node->next = NULL;
        top = new_node;
    }
    else {
        new_node->next = top;
        top = new_node;
    }
    return top;
}

struct node *pop(struct node *top) {
    struct node *ptr;
    if (top == NULL) {
        printf("STACK UNDERFLOW!\n");
    }
    else {
        ptr = top;
        top = top->next;
        printf("\nThe value deleted from stack is: %d\n", ptr->data);
        free(ptr);
    }

    return top;
}

int peek(struct node *top) {
    if (top == NULL) {
        printf("STACK IS EMPTY.\n");
        return -1;
    }
    else {
        return top->data;
    }
}

void display(struct node *top) {
    struct node *ptr;
    ptr = top;
    if (top == NULL) {
        printf("STACK IS EMPTY.\n");
    }
    else {
        printf("\n");
        while (ptr != NULL) {
            printf("|  %d  |\n", ptr->data);
            ptr = ptr->next;
        }
        printf("-------\n");
        //printf("NULL\n");
    }
}