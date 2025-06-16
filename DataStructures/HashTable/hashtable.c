#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TABLE_SIZE 10

// Node for Chaining
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash Table Structures
int openAddressingTable[TABLE_SIZE];        // For Open Addressing
Node* chainingTable[TABLE_SIZE];            // For Chaining

// Initialize tables
void initTables() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        openAddressingTable[i] = -1;  // -1 means empty
        chainingTable[i] = NULL;
    }
}

// Hash Functions
int hashDivision(int key) {
    return key % TABLE_SIZE;
}

int hashMultiplication(int key) {
    float A = 0.6180339887;  // Knuth's suggestion
    float frac = fmod(key * A, 1);
    return (int)(TABLE_SIZE * frac);
}

int hashMidSquare(int key) {
    int square = key * key;
    square = (square / 10) % 100;  // Extract middle 2 digits
    return square % TABLE_SIZE;
}

int hashFolding(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 100;  // Fold every 2 digits
        key /= 100;
    }
    return sum % TABLE_SIZE;
}

// ----------------------
// OPEN ADDRESSING INSERT
// ----------------------
void insertOpenAddressing(int key, int (*hashFunc)(int)) {
    int index = hashFunc(key);
    int originalIndex = index;
    int i = 0;

    while (openAddressingTable[index] != -1) {
        index = (originalIndex + ++i) % TABLE_SIZE;
        if (i >= TABLE_SIZE) {
            printf("Open Addressing Table is full!\n");
            return;
        }
    }
    openAddressingTable[index] = key;
}

// ----------------------
// CHAINING INSERT
// ----------------------
void insertChaining(int key, int (*hashFunc)(int)) {
    int index = hashFunc(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = chainingTable[index];
    chainingTable[index] = newNode;
}

// ----------------------
// DISPLAY TABLES
// ----------------------
void displayOpenAddressing() {
    printf("\nOpen Addressing Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (openAddressingTable[i] != -1)
            printf("[%d] => %d\n", i, openAddressingTable[i]);
        else
            printf("[%d] => NULL\n", i);
    }
}

void displayChaining() {
    printf("\nChaining Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] => ", i);
        Node* curr = chainingTable[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// ----------------------
// MENU FOR DEMO
// ----------------------
void demo(int (*hashFunc)(int), const char* name) {
    initTables();
    int keys[] = {123, 432, 213, 654, 892, 345, 657, 234, 891, 333, 777};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("\n=== Using %s ===\n", name);
    for (int i = 0; i < n; i++) {
        insertOpenAddressing(keys[i], hashFunc);
        insertChaining(keys[i], hashFunc);
    }

    displayOpenAddressing();
    displayChaining();
}

// ----------------------
// MAIN
// ----------------------
int main() {
    demo(hashDivision, "Division Method");
    demo(hashMultiplication, "Multiplication Method");
    demo(hashMidSquare, "Mid-Square Method");
    demo(hashFolding, "Folding Method");

    return 0;
}
