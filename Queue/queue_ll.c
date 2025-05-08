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

void create_queue(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

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
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr = q->front;
    if (q->front == NULL) {
        printf("UNDERFLOW\n");
    }
    else {
        q->front = q->front->next;
        printf("The value being deleted is: %d\n", ptr->data);
        free(ptr);
    }
}

int peekFront(struct queue *q) {
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY\n");
    }
    return q->front->data;
} 

void display_queue(struct queue *q) {
    struct node *ptr;
    ptr = q->front;
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("Front value: %d\n", peekFront(q));
                break;
            case 4:
                display_queue(q);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}