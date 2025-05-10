#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *q;

struct queue *enqueue(struct queue *q, int val) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    if (q->front == NULL) {
        q->front = q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}

struct queue *dequeue(struct queue *q) {
    struct node *ptr;
    ptr = q->front;
    if (q->front == NULL) {
        printf("UNDERFLOW\n");
    }
    else {
        q->front = q->front->next;
        printf("Value deleted from the queue: %d\n", ptr->data);
        free(ptr);
    }
    return q;
}

int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY.\n");
    }
    else {
        return q->front->data;
    }
}

void display_queue(struct queue *q) {
    struct node *ptr;
    ptr = q->front;
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY.\n");
        return;
    }

    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(void) {
    int option, val;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;

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
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                q = enqueue(q, val);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                val = peek(q);
                if (q->front != NULL) {
                    printf("The first value in the queue: %d\n", val);
                }
                break;
            case 4:
                display_queue(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(option != 5);

    // Free the queue memory
    while (q->front != NULL) {
        q = dequeue(q);
    }
    free(q);

    return 0;
}