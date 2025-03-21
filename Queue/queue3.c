#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void create_queue(queue *q);
void *insert(queue *q, int num);
void *delete(queue *q);
int peek(queue *q);
void display_queue(queue *q);

int main(void) {
    queue q;
    create_queue(&q);

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
                printf("Enter the number to insert: ");
                scanf("%d", &val);
                insert(&q, val);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                val = peek(&q);
                if (val != -1) {
                    printf("The first number in the queue: %d\n", val);
                }
                break;
            case 4:
                display_queue(&q);
                break;
        }
    } while(option != 5);
    
    return 0;
}

void create_queue(queue *q) {
    q->rear = NULL;
    q->front = NULL;
}

void *insert(queue *q, int num) {
    node *ptr;
    ptr = (node*) malloc(sizeof(node));
    ptr->data = num;

    if (q->front == NULL) {
        q->front = q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL; 
    }
}

void *delete(queue *q) {
    node *ptr;
    ptr = q->front;

    if (q->front == NULL) {
        printf("UNDERFLOW\n");
    }
    else {
        q->front = q->front->next;
        printf("The number being deleted: %d\n", ptr->data);
        free(ptr);
    }
}

int peek(queue *q) {
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    } 
    else {
        return q->front->data;
    }
}

void display_queue(queue *q) {
    node *ptr = q->front;
    if (ptr == NULL) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}