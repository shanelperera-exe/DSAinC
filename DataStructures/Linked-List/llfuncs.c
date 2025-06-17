#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertEnd(struct Node** head, int data);
void insertAtPos(struct Node** head, int pos, int data);
void deleteByValue(struct Node** head, int value);
void display(struct Node* head);
void reverseList(struct Node** head);
void sortList(struct Node* head);
int detectLoop(struct Node* head);
struct Node* mergeLists(struct Node* l1, struct Node* l2);
void findMiddle(struct Node* head);
int countNodes(struct Node* head);
int isPalindrome(struct Node* head);

// Main menu function
int main() {
    struct Node* head = NULL;
    struct Node* otherList = NULL;

    int choice, data, pos, value;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Position\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Reverse List\n");
        printf("6. Sort List\n");
        printf("7. Detect Loop\n");
        printf("8. Merge with Another List\n");
        printf("9. Find Middle Element\n");
        printf("10. Count Nodes\n");
        printf("11. Check Palindrome\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &data);
                insertAtPos(&head, pos, data);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                reverseList(&head);
                printf("List Reversed.\n");
                break;
            case 6:
                sortList(head);
                printf("List Sorted.\n");
                break;
            case 7:
                if (detectLoop(head))
                    printf("Loop detected!\n");
                else
                    printf("No loop detected.\n");
                break;
            case 8:
                otherList = NULL;
                printf("Enter 5 sorted values for second list:\n");
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &data);
                    insertEnd(&otherList, data);
                }
                head = mergeLists(head, otherList);
                printf("Lists merged.\n");
                break;
            case 9:
                findMiddle(head);
                break;
            case 10:
                printf("Node count: %d\n", countNodes(head));
                break;
            case 11:
                if (isPalindrome(head))
                    printf("List is a palindrome.\n");
                else
                    printf("List is not a palindrome.\n");
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function Definitions

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPos(struct Node** head, int pos, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node** head, int value) {
    struct Node *temp = *head, *prev = NULL;

    if (temp && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    printf("List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }

    return 0;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct Node* result = NULL;

    if (l1->data < l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }

    return result;
}

void findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow)
        printf("Middle element: %d\n", slow->data);
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int isPalindrome(struct Node* head) {
    int arr[MAX_SIZE], i = 0;
    struct Node* temp = head;

    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    for (int j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1])
            return 0;
    }

    return 1;
}
