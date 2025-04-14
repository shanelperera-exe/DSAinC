#include <stdio.h>
#define MAX 100

// Two stacks
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
void push1(int val) {
    if (top1 >= MAX - 1) {
        printf("Stack1 Overflow\n");
    }
    else {
        top1++;
        stack1[top1] = val;
    }
}

int pop1(void) {
    if (top1 < 0) {
        printf("Stack1 Underflow\n");
        return -1;
    }
    else {
        int val = stack1[top1];
        top1--;
        return val;
    }
}

void push2(int val) {
    if (top2 >= MAX - 1) {
        printf("Stack2 Overflow\n");
        return;
    }
    else {
        top2++;
        stack2[top2] = val;
    }
}

int pop2() {
    if (top2 < 0) {
        printf("Stack2 Underflow\n");
        return -1;
    }
    else {
        int val = stack2[top2];
        top2--;
        return val;
    }
}

// Queue operations
void enqueue(int val) {
    push1(val);
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    int val;

    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1) {
        int a;
        while (top1 != -1) {
            a = pop1();
            push2(a);
        }
    }

    val = pop2();
    printf("Dequeued: %d\n", val);
    return val;
}

// Main function to test
int main() {
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
