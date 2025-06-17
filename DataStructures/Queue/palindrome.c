// Check for Palindrome using Queue

#include <stdio.h>
#include <string.h>
#define SIZE 100

char queue[SIZE], stack[SIZE];
int front = -1, rear = -1, top = -1;

void enqueue(char c) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = c;
}

char dequeue() {
    if (front == -1 || front > rear) return '\0';
    return queue[front++];
}

void push(char c) {
    if (top == SIZE - 1) return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int main() {
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        enqueue(str[i]);
        push(str[i]);
    }

    int isPalindrome = 1;
    for (int i = 0; i < len; i++) {
        if (dequeue() != pop()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}
