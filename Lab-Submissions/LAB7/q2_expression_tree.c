#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

struct Node* buildExpressionTree(char* postfix) {
    struct Node* node;
    struct Node* left;
    struct Node* right;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (ch == ' ')
            continue;

        node = createNode(ch);

        if (isOperator(ch)) {
            right = pop();
            left = pop();
            node->right = right;
            node->left = left;
        }

        push(node);
    }

    return pop();
}

void prefixTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%c", root->data);
    prefixTraversal(root->left);
    prefixTraversal(root->right);
}

void infixTraversal(struct Node* root) {
    if (root == NULL)
        return;
    if (isOperator(root->data))
        printf("(");
    infixTraversal(root->left);
    printf("%c", root->data);
    infixTraversal(root->right);
    if (isOperator(root->data))
        printf(")");
}

int main() {
    char postfix[100];
    printf("Enter postfix expression (e.g., ab+cd-*): ");
    scanf("%s", postfix);

    struct Node* root = buildExpressionTree(postfix);

    printf("\nPrefix Expression:  ");
    prefixTraversal(root);

    printf("\nInfix Expression:   ");
    infixTraversal(root);

    printf("\n");
    return 0;
}
