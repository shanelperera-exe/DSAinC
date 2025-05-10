#include <stdio.h>

#define MAX 10

void insert(void);
int delete(void);
int peek(void);
void display(void);

int queue[MAX];
int front = -1, rear = -1;

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

void insert(void) {
    int num;
    printf("Enter the number to be inserted into the queue: ");
    scanf("%d", &num);

    if (rear == MAX - 1) {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = num;
}

int delete(void) {
    int num;
    if (front == -1 || front > rear) {
        printf("UNDERFLOW\n");
        return -1;
    }
    else {
        num = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return num;
    }
}

int peek(void) {
    if (front == -1 || front > rear) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    else {
        return queue[front];
    }
}

void display(void) {
    if (front == -1 || front > rear) {
        printf("QUEUE IS EMPTY\n");
    }
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}