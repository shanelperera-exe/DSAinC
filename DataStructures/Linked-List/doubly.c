#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;  // Data field
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
} Node;
// Shortening the Node Declaration


Node *create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    // Initially assigning the next and prev pointers to NULL
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}


int main(void) {
    // Create and initialize nodes
    Node *head = create_node(10);
    Node *second = create_node(20);
    Node *third = create_node(30);

    // Linking the nodes
    head->next = second; // This will create: 10 <->
    second->prev = head;
    second->next = third; // This will create: 10 <-> 20 <-> 30
    third->prev = second;

    printf("Doubly Linked List: ");
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}