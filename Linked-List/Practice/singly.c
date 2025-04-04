#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void) {
    struct node *head = NULL;
}

struct node *insert_beg(struct node *head) {
    struct node *new_node;
    int num;
    printf("Enter the data to be insertered: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = head;
    head = new_node;
    return head;
}

struct node *insert_end(struct node *head) {
    struct node *ptr, *new_node;
    int num;
    printf("Enter the data to be insertered: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}