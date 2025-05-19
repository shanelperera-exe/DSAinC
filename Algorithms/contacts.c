#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_CONTACTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} contact;

void add_contact();
void sort_contacts();
int binary_search(char *search_name);

contact directory[MAX_CONTACTS];
int contact_count = 0;

int main() {
    int choice;
    char search_name[MAX_NAME_LEN];

    while (1) {
        printf("\nDirectory Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Sort Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                sort_contacts();
                break;
            case 3:
                if (contact_count == 0) {
                    printf("Directory is empty.\n");
                    break;
                }
                printf("Enter name to search: ");
                fgets(search_name, MAX_NAME_LEN, stdin);
                search_name[strcspn(search_name, "\n")] = '\0';
                int index = binary_search(search_name);
                if (index != -1) {
                    printf("\nContact found:\nName: %s\nPhone: %s\n",
                           directory[index].name, directory[index].phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printf("Exiting the directory. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Directory is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(directory[contact_count].name, MAX_NAME_LEN, stdin);
    directory[contact_count].name[strcspn(directory[contact_count].name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(directory[contact_count].phone, MAX_PHONE_LEN, stdin);
    directory[contact_count].phone[strcspn(directory[contact_count].phone, "\n")] = '\0';

    contact_count++;
}


void sort_contacts() {
    for (int i = 0; i < contact_count - 1; i++) {
        for (int j = 0; j < contact_count - i - 1; j++) {
            if (strcmp(directory[j].name, directory[j + 1].name) > 0) {
                contact temp = directory[j];
                directory[j] = directory[j + 1];
                directory[j + 1] = temp;
            }
        }
    }
    printf("Contacts sorted alphabetically.\n");
}

int binary_search(char *search_name) {
    int left = 0, right = contact_count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(search_name, directory[mid].name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
