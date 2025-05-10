#include <stdio.h>

#define MAX 10

void insert(int num);
void add_numbers(void);
void find_number(void);
void display_numbers(void);

int queue[MAX];
int front = -1, rear = -1;

int main(void) {
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
                add_numbers();
                break;
            case 2:
                find_number();
                break;
            case 3:
                display_numbers();
                break;
        }

        if (option > 4) {
            printf("Invalid option.Please try again.\n");
        }
    } while(option != 4);
    return 0;
}

void insert(int num) {
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

void add_numbers(void) {
    int n;
    do {
        printf("Enter the number of elements to be stored in the queue: ");
        scanf("%d", &n);

        if (n >= MAX) {
            printf("Queue size is insufficient. The number of elements should be less than %d.\n", MAX);
        }

        if (rear + n >= MAX) {
            printf("Not enough space in the queue to add %d elements.\n", n);
        }
    } while(n < 0 || rear + n >= MAX);

    for (int i = 1; i <= n; i++) {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        insert(num);
    }
    printf("Numbers added successfully.\n");
}

void find_number(void) {
    int num;
    printf("Enter the number to be searched: ");
    scanf("%d", &num);

    int number_found = 0;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == num) {
            number_found = 1;
            break;
        }
    }

    if (number_found) {
        printf("Number %d found in the queue.\n", num);
    } else {
        printf("Number %d not found in the queue.\n", num);
    }
}

void display_numbers(void) {
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