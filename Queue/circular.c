#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(int c)

int main(void) {
    int option, val;
    do {
        printf("\n***** MAIN MENU *****\n");
        printf("[1] Insert an element\n");
        printf("[2] Delete an element\n");
        printf("[3] Peek\n");
        printf("[4] Display the Queue\n");
        printf("[5] Exit\n");
        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                insert();
                break;
            case 2:
                val = delete();
                if (val != -1) {
                    printf("The value deleted from the queue: %d\n", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("The first value in the queue: %d\n", val);
                }
                break;
            case 4:
                display();
                break;
        }
    } while(option != 5);
    return 0;
}

void insert(int c) {
    int num;
    
    if (front == 0 && rear == MAX - 1) {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear = MAX -1 && front != 0) {
        rear = 0;
        queue[rear] = num;
    }
    else {
        rear++;
        queue[rear] = num;
    }
}

