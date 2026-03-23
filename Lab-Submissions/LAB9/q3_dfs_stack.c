#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void dfsStack(int start) {
    push(start);

    printf("DFS Traversal Order (Stack): ");

    while (!isEmpty()) {
        int current = pop();

        if (visited[current])
            continue;

        visited[current] = 1;
        printf("%d ", current);

        struct Node* temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                push(temp->vertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges, src, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dfsStack(src);

    return 0;
}
