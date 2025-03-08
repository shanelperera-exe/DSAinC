#include <stdio.h>
#include <stdlib.h>


// Define the Node structure to represent the singly linked list
struct Node {
    int data;  // Data field - can be of any type and count
    struct Node* next;  // Pointer to the next node
};


// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


// Function to insert a new element at the beginning of the singly linked list
void insert_at_first(struct Node** head, int data) {
    struct Node* new_node = create_node(data);  // Create a new node.
    // If the linked list is empty set the new node as the Head  and return.
    new_node->next = *head;  // Connect the next pointer of this new node to the Head of the linked list.
    *head = new_node;  // Update the Head pointer and make it points to the new node
}


// Function to insert a new element at the end of the singly linked list
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);  // Create a new Node.
    if (*head == NULL) {   // If the list is empty
        *head = new_node;  // update the Head pointer to be this new node
        return;  // and then return
    }
    // Otherwise traverse till the last node of the singly linked list.
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;  // Connect next pointer of the last node to the new node.
}


// Function to insert a new element at a specific position in the singly linked
void insert_at_position(struct Node** head, int data, int position) {
    struct Node* new_node = create_node(data); // Create a new node.
    if (position == 0) {  // Check if the position is 0.
        insert_at_first(head, data);  // If it is 0, call the insert_at_first function to insert the node at the first position of the list.
        return;
    }
    // Initialize a counter variable and a temporary pointer to traverse the linked list.
    struct Node* temp = *head;
    // Iterate over the linked list to find the node before the insertion point (position - 1).
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    // If the temporary pointer becomes NULL before reaching the desired position, the position is out of range. Return.
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;  // Point the next pointer of the new node to the node present just after the temporary pointer.
    temp->next = new_node;  // Point the next pointer of the temporary node to the new node and return.
}


// Function to delete the first node of the singly linked list
void delete_from_first(struct Node** head) {
    // Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;  // Create a temporary pointer and point it to the current Head of the list.
    *head = temp->next;  // Update the current head of the singly linked list to the next node.
    // Point the next pointer of the temporary node to NULL to detach it from the singly linked list.
    free(temp);  // Delete the temporary node.
} 


// Function to delete the last node of the singly linked list
void delete_from_end(struct Node** head) {
    // Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {  // If the singly linked list has only one node
        free(temp);  // delete the head node 
        *head = NULL;  // and point the head pointer to NULL.
        return;
    }
    while (temp->next->next != NULL) {  // Traverse till the second last node of the singly linked list.
        temp = temp->next;  // Store the next node of the second last node in a temporary pointer.
    }
    free(temp->next);  // Delete the last node represented by the temporary pointer.
    temp->next = NULL;  //  Connect the next pointer of the second last node to NULL.
}


void delete_at_position(struct Node** head, int position) {
    // Check if the head pointer of the linked list is NULL.
    if (*head == NULL) {
        printf("List is empty.\n");
        return;  // If it is NULL, the linked list is empty, so return.
    }
    struct Node* temp = *head;
    if (position == 0) {  // Check if the position is 0.
        delete_from_first(head);  // If it is 0, call the deleteFromFirst function to delete the first node.
        return;
    }
    // Initialize a counter variable and a temporary pointer to traverse the linked list.
    for (int i = 0; temp != NULL && i < position - 1; i++) {  // Iterate the linked list to find the node before the deletion point (position - 1).
        temp = temp->next;  // Store the next node of the temporary pointer in a temporary pointer.
    }
    // If the temporary pointer becomes NULL before reaching the desired position the position is out of range. Return
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* next = temp->next->next;  // Update the next pointer of the temporary pointer to the next pointer of the node to be deleted.
    free(temp->next);  // Delete the node represented by the temporary pointer.
    temp->next = next;
}


// Function to print the LinkedList
void print(struct Node* head) {
    // Check if the HEAD of the singly linked is is NULL or not. If NULL return back.
    struct Node* temp = head;  // Set a temp pointer to the head of the singly linked list.
    while (temp != NULL) {  // While temp pointer != NULL:
        printf("%d -> ", temp->data);  // Print temp->data.
        temp = temp->next;  // Move temp to temp->next
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    
    insert_at_first(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head); 
    
    printf("Linked list after inserting the node:20 at the end \n");
    insert_at_end(&head, 20);
    print(head); 
    
    printf("Linked list after inserting the node:5 at the end \n");
    insert_at_end(&head, 5);
    print(head); 
    
    printf("Linked list after inserting the node:30 at the end \n");
    insert_at_end(&head, 30);
    print(head); 
    
    printf("Linked list after inserting the node:15 at position 2 \n");
    insert_at_position(&head, 15, 2);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    delete_from_first(&head);
    print(head); 
    
    printf("Linked list after deleting the last node: \n");
    delete_from_end(&head);
    print(head); 
    
    printf("Linked list after deleting the node at position 1: \n");
    delete_at_position(&head, 1);
    print(head); 

    return 0;
}