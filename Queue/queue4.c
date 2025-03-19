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
void insert(queue *q, int num);
void add_numbers(queue *q);
void find_number(queue *q);
void display_numbers(queue *q);

int main(void) {
    queue q;
    create_queue(&q);

    int option;
    do {
        printf("\n***** MAIN MENU *****\n");
        printf("[1] Add numbers\n");
        printf("[2] Find a number\n");
        printf("[3] Display numbers\n");
        printf("[4] Exit\n");
        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_numbers(&q);
                break;
            case 2:
                int num;
                find_number(&q);
                break;
            case 3:
                display_numbers(&q);
                break;
        }

        if (option > 4) {
            printf("Invalid option.Please try again.\n");
        }
    } while(option != 4);
    return 0;
}

void create_queue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void insert(queue *q, int num) {
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

void add_numbers(queue *q) {
    int n;
    do {
        printf("Enter the number of elements to be stored in the queue: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Invalid Input.Please try again.\n");
        }
    } while(n <= 0);

    for (int i = 1; i <= n; i++) {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        insert(q, num);
    }
    printf("Numbers added successfully.\n");
}

void find_number(queue *q) {
    node *ptr = q->front;

    int num;
    printf("Enter the number to be searched: ");
    scanf("%d", &num);

    int number_found = 0;

    while (ptr != NULL) {
        if (ptr->data == num) {
            number_found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (number_found) {
        printf("Number %d found in the queue.\n", num);
    } else {
        printf("Number %d not found in the queue.\n", num);
    }
}

void display_numbers(queue *q) {
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