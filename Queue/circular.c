#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
void display(void);
int delete(void);
int peek(void);

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

    if (front == 0 && rear == MAX - 1) {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX -1 && front != 0) {
        rear = 0;
        queue[rear] = num;
    }
    else {
        rear++;
        queue[rear] = num;
    }
}

int delete(void) {
    int val;
    if (front == -1 && rear == -1) {
        printf("UNDERFLOW\n");
        return -1;
    }

    val = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        if (front == MAX -1) {
            front = 0;
        }
        else {
            front++;
        }
    }
    return val;
}

int peek(void) {
    if (front == -1 && rear == -1) {
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