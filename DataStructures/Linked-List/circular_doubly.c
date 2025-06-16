#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// Insert at the beginning
void insertBeginning(int data) {
    insertEnd(data);
    head = head->prev; // Move head to the newly inserted node
}

// Delete a node with given data
void deleteNode(int key) {
    if (head == NULL)
        return;

    Node* current = head;
    Node* toDelete = NULL;

    // Search the node
    do {
        if (current->data == key) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (toDelete == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Only one node
    if (toDelete->next == toDelete && toDelete->prev == toDelete) {
        head = NULL;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        if (toDelete == head)
            head = toDelete->next;
    }

    free(toDelete);
}

// Display list forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Forward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Display list in reverse
void displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* tail = head->prev;
    Node* temp = tail;

    printf("Reverse: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

// Driver program
int main() {
    insertEnd(10);
    insertEnd(20);
    insertBeginning(5);
    insertEnd(30);

    displayForward();
    displayReverse();

    deleteNode(20);
    displayForward();

    deleteNode(5);
    displayForward();

    deleteNode(100); // Not in list

    return 0;
}
