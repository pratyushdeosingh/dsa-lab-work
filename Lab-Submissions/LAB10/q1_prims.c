#include <stdio.h>
#include <limits.h>

#define MAX 100

int vertices;
int adjMatrix[MAX][MAX];
int key[MAX];
int parent[MAX];
int inMST[MAX];

int minKey() {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < vertices; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST() {
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey();
        inMST[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    printf("\nMST Edges (Prim's Algorithm):\n");
    printf("Edge\t\tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d\t\t%d\n", parent[i], i, adjMatrix[parent[i]][i]);
        totalCost += adjMatrix[parent[i]][i];
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    int edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    primMST();

    return 0;
}
