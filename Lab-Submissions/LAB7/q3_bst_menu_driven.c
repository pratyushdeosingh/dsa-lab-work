#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Value %d already exists in BST.\n", value);
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Value %d not found in BST.\n", value);
        return root;
    }
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("Deleted successfully.\n");
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("Deleted successfully.\n");
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void search(struct Node* root, int value) {
    if (root == NULL) {
        printf("Value %d not found in BST.\n", value);
        return;
    }
    if (value == root->data) {
        printf("Value %d found in BST.\n", value);
        return;
    }
    if (value < root->data)
        search(root->left, value);
    else
        search(root->right, value);
}

int kthMinCount = 0;

void kthMin(struct Node* root, int k) {
    if (root == NULL || kthMinCount >= k)
        return;
    kthMin(root->left, k);
    kthMinCount++;
    if (kthMinCount == k) {
        printf("%dth Minimum element: %d\n", k, root->data);
        return;
    }
    kthMin(root->right, k);
}

int kthMaxCount = 0;

void kthMax(struct Node* root, int k) {
    if (root == NULL || kthMaxCount >= k)
        return;
    kthMax(root->right, k);
    kthMaxCount++;
    if (kthMaxCount == k) {
        printf("%dth Maximum element: %d\n", k, root->data);
        return;
    }
    kthMax(root->left, k);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, value, k;

    while (1) {
        printf("\n===== BST Menu =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Kth Minimum\n");
        printf("5. Kth Maximum\n");
        printf("6. Display (Inorder)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 4:
                printf("Enter k for Kth Minimum: ");
                scanf("%d", &k);
                kthMinCount = 0;
                kthMin(root, k);
                break;

            case 5:
                printf("Enter k for Kth Maximum: ");
                scanf("%d", &k);
                kthMaxCount = 0;
                kthMax(root, k);
                break;

            case 6:
                printf("Inorder (sorted): ");
                inorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
