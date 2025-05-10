#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top1 = NULL;
struct node *top2 = NULL;

struct node *push1(struct node *top, int val);
struct node *pop1(struct node *top, int *val);
struct node *push2(struct node *top, int val);
struct node *pop2(struct node *top, int *val);
void enqueue(int val);
void dequeue(void);

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue(); // 10
    enqueue(40);
    dequeue(); // 20
    dequeue(); // 30
    dequeue(); // 40
    dequeue(); // Queue is empty
    return 0;
}

void enqueue(int val) {
    top1 = push1(top1, val);
    printf("Enqueued: %d\n", val);
}

void dequeue(void) {
    int val;
    if (top2 == NULL) {
        while (top1 != NULL) {
            top1 = pop1(top1, &val);
            top2 = push2(top2, val);
        }
    }

    if (top2 == NULL) {
        printf("Queue Underflow\n");
    } else {
        top2 = pop2(top2, &val);
        printf("Dequeued: %d\n", val);
    }
}

struct node *push1(struct node *top, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = top;
    return new_node;
}

struct node *pop1(struct node *top, int *val) {
    if (top == NULL) {
        printf("Stack Underflow (pop1)\n");
        return NULL;
    }
    *val = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

struct node *push2(struct node *top, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = top;
    return new_node;
}

struct node *pop2(struct node *top, int *val) {
    if (top == NULL) {
        printf("Stack Underflow (pop2)\n");
        return NULL;
    }
    *val = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return top;
}
