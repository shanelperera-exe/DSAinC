#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_DATA 20

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *root;

node *create_node(int data);
void inorder_traversal(node *root);
void preorder_traversal(node *root);
void postorder_traversal(node *root);
struct node *insert_element(struct node *root, int val);

int main(void) {
    int data[] = {77, 64, 91, 8, 72, 86, 96, 3, 40, 70, 74, 85, 92, 1, 7, 34, 58, 69, 73, 80};
    for (int i = 0; i < NUM_OF_DATA; i++) {
        root = insert_element(root, data[i]);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    return 0;
}

node *create_node(int data) {
    node *new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

struct node *insert_element(struct node *root, int val) {
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (root == NULL) {
        root = ptr;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        parentptr = NULL;
        nodeptr = root;

        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }

        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return root;
}
