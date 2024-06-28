#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} node;

node *create() {
    int x;
    
    printf("Enter the value(or -1 for no node): ");
    scanf("%d", &x);
    if (x == -1){
        return NULL;
    }
    node *newNode = malloc(sizeof(node));
    newNode -> value = x;
    printf("left child of %d ", x);
    newNode -> left = create();

    printf("right child of %d ", x);
    newNode -> right = create();
    return newNode;
}

void inOrder(node *root) {// Left Root Right
    if(root == NULL) {
        return;
    } 
    inOrder(root -> left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void preOrder(node *root) { // Root Left Right
    if(root == NULL) {
        return;
    } 
    printf("%d ", root -> value);
    preOrder(root->left);
    preOrder(root->right);
} 

void postOrder(node *root) {// Left Right Root
    if(root == NULL) {
        return;
    } 
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}

// Function to search for a value in the tree
int search(node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        return 1;
    }
    int foundInLeft = search(root->left, value);
    if (foundInLeft) {
        return 1;
    }
    return search(root->right, value);
}

// Function to free the allocated memory for the tree
void freeTree(node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Declare the root of the binary tree
    node *root = NULL;

    // Create the binary tree and assign its root to 'root'
    root = create();

    // Perform in-order traversal
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // Perform pre-order traversal
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    // Perform post-order traversal
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    // Search for a value in the tree
    int valueToSearch = 5; // Change this value to search for different nodes
    if (search(root, valueToSearch)) {
        printf("Value %d found in the tree.\n", valueToSearch);
    } else {
        printf("Value %d not found in the tree.\n", valueToSearch);
    }

    // Free the allocated memory
    freeTree(root);

    return 0;
}