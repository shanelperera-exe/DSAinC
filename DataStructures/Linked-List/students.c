#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 25

typedef struct node {
	int id;
	char name[NAME_LENGTH];
	struct node *next;
} node;

node *create_list(void);
node *create_node(int id, char name[]);
void display_list(node *head);
node *insert_at_beg(node *head, int id, char name[]);
node *delete_at_beg(node *head);
node *delete_all_nodes(node *head);

int main(void) {
	node *node1, *node2, *node3;
	node *head;

	// Creating 3 initial nodes and linking them in order
	node1 = create_node(100, "Gihan");
	node2 = create_node(101, "Chathurika");
	node3 = create_node(102, "Kishi");
	
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	// Create an empty linked list
	head = create_list();
	head = node1;
	
	// Displaying the initial linked list
	printf("*** Initial List ***\n");
	display_list(head);

	// Adding 2 more nodes to the linked-list
	head = insert_at_beg(head, 103, "Ruwan");
	head = insert_at_beg(head, 104, "Nethmi");

	// Displaying the updated linked-list
	printf("\n*** Updated List ***\n");
	display_list(head);

	// Delete all the nodes in the linked list.
	head = delete_all_nodes(head);

	// Sisplaying the list after deleting all nodes.
	printf("\n*** Updated List ***\n");
	display_list(head);
	
	return 0;
}

node *create_list(void) {
	return NULL;
}

node *create_node(int id, char name[]) {
	node *new_node;
	new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL) {
		printf("Memory Allocation Failed.\n");
		exit(1); // Exit if memory allocation fails
	}
	new_node->id = id;
	strcpy(new_node->name, name);
	new_node->next = NULL;
	return new_node;
}

void display_list(node *head) {
	node *ptr = head;
	if (ptr == NULL) {
		printf("List is empty.\n");
		return;
	}
	while (ptr != NULL) {
		printf("ID: %d | Name: %s\n", ptr->id, ptr->name);
		ptr = ptr->next;
	}
}

node *insert_at_beg(node *head, int id, char name[]) {
	node *new_node = create_node(id, name);
	new_node->next = head;
	head = new_node;
	return head;
}

node *delete_at_beg(node *head) {
	if (head == NULL) {
		printf("List is already empty.\n");
		return NULL;
	}
	node *ptr = head;
	head = head->next;
	free(ptr);
	return head;
}

node *delete_all_nodes(node *head) {
	node *ptr;
	ptr = head;
	
	if (ptr == NULL) {
		printf("List is empty.\n");
	}
	while (ptr != NULL) {
		node *temp = ptr; 
		ptr = ptr->next;  
		free(temp);
	}
	head = NULL;
	return head;
}
