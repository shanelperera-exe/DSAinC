#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert_beg(struct node *head);
struct node *insert_end(struct node *head);
struct node *insert_after(struct node *head);
struct node *insert_before(struct node *head);
struct node *delete_beg(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_after(struct node *head);
struct node *display_list(struct node *head);

int main(void) {
    struct node *head = NULL;
    int choice;

    while (1) {
        printf("\n*** MAIN MENU ***\n");
        printf("[1] Insert at beginning\n");
        printf("[2] Insert at end\n");
        printf("[3] Insert after a specific element\n");
        printf("[4] Insert before a specific element\n");
        printf("[5] Delete the first element\n");
        printf("[6] Delete the last element\n");
        printf("[7] Delete after a specific element\n");
        printf("[8] Display list\n");
        printf("[9] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert_beg(head);
                break;
            case 2:
                head = insert_end(head);
                break;
            case 3:
                head = insert_after(head);
                break;
            case 4:
                head = insert_before(head);
                break;
            case 5:
                head = delete_beg(head);
                break;
            case 6:
                head = delete_end(head);
                break;
            case 7:
                head = delete_after(head);
                break;
            case 8:
                head = display_list(head);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

struct node *display_list(struct node *head) {
    struct node *ptr = head;
    if (head == NULL) {
        printf("The list is empty.\n");
    }
    else {
        printf("\nThe linked list: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
        return head;
    }
}

struct node *insert_beg(struct node *head) {
    struct node *new_node;
    int num;
    printf("Enter the number to be insereted: ");
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
    printf("Enter the number to be insereted: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}

struct node *insert_after(struct node *head) {
    struct node *ptr = head;
    int num, key;

    if (head == NULL) {
        printf("The list is empty. Cannot insert after a specific element.\n");
        return head;
    }

    printf("Enter the number to be inserted: ");
    scanf("%d", &num);
    printf("Enter the value after which the new number should be inserted: ");
    scanf("%d", &key);

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Target value %d not found in the list.\n", key);
        return head;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = num;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return head;
}

struct node *insert_before(struct node *head) {
    struct node *ptr, *prev;
    int num, key;

    ptr = head;
    prev = NULL;

    if (head == NULL) {
        printf("The list is empty. Cannot insert before a specific element.\n");
        return head;
    }

    printf("Enter the number to be inserted: ");
    scanf("%d", &num);
    printf("Enter the value before which the new number should be inserted: ");
    scanf("%d", &key);

    if (head->data == key) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }
        new_node->data = num;
        new_node->next = head;
        head = new_node;
        return head;
    }

    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Target value %d not found in the list.\n", key);
        return head;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->data = num;
    new_node->next = ptr;
    prev->next = new_node;

    return head;
}

struct node *delete_beg(struct node *head) {
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *delete_end(struct node *head) {
    struct node *ptr, *preptr;
    ptr = head;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return head;
}

struct node *delete_after(struct node *head) {
    struct node *ptr, *temp;
    int key;

    if (head == NULL) {
        printf("The list is empty. Cannot delete after a specific element.\n");
        return head;
    }

    printf("Enter the value after which the node should be deleted: ");
    scanf("%d", &key);

    ptr = head;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists after the given value %d.\n", key);
        return head;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}