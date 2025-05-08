#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Manually construct the tree based on the image
    struct Node* root = createNode(77);
    
    root->left = createNode(64);
    root->right = createNode(91);

    root->left->left = createNode(8);
    root->left->right = createNode(72);
    
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(40);
    root->left->left->left->left = createNode(1);
    root->left->left->left->right = createNode(7);
    
    root->left->left->right->left = createNode(34);
    root->left->left->right->left->right = createNode(58);
    root->left->left->right->left->right->right = createNode(69);

    root->left->right->left = createNode(70);
    root->left->right->right = createNode(74);
    root->left->right->right->left = createNode(73);

    root->right->left = createNode(86);
    root->right->left->right = createNode(85);
    root->right->left->right->left = createNode(80);

    root->right->right = createNode(96);
    root->right->right->right = createNode(92);

    // Print traversals
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
