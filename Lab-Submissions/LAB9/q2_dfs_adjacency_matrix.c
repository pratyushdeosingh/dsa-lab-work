#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int vertices;

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void dfs(int src) {
    visited[src] = 1;
    printf("%d ", src);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[src][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, src;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    printf("DFS Traversal Order: ");
    dfs(src);
    printf("\n");

    return 0;
}
