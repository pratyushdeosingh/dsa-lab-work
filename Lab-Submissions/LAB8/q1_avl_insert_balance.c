#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
};

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else {
        printf("Duplicate value %d not allowed.\n", value);
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
        return rotateRight(root);

    if (balance < -1 && value > root->right->data)
        return rotateLeft(root);

    if (balance > 1 && value > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && value < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderWithBalance(struct Node* root) {
    if (root == NULL)
        return;
    inorderWithBalance(root->left);
    printf("Node: %d | Balance Factor: %d\n", root->data, getBalance(root));
    inorderWithBalance(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal with Balance Factors:\n");
    inorderWithBalance(root);

    return 0;
}
