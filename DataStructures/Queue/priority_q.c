#include <stdio.h>
#define SIZE 100

int pq[SIZE], count = 0;

void insert(int x) {
    if (count == SIZE) {
        printf("Queue Full\n");
        return;
    }

    int i = count - 1;
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    count++;
}

void deleteMin() {
    if (count == 0) {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted: %d\n", pq[0]);
    for (int i = 1; i < count; i++)
        pq[i - 1] = pq[i];
    count--;
}

void display() {
    printf("Priority Queue: ");
    for (int i = 0; i < count; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    display();
    deleteMin();
    display();
    return 0;
}
