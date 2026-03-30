#include <stdio.h>
#include <limits.h>

#define MAX 100

int vertices;
int adjMatrix[MAX][MAX];
int dist[MAX];
int visited[MAX];
int prev[MAX];

int minDist() {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int dest) {
    if (prev[dest] == -1) {
        printf("%d", dest);
        return;
    }
    printPath(prev[dest]);
    printf(" -> %d", dest);
}

void dijkstra(int src) {
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDist();
        if (u == -1)
            break;
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                prev[v] = u;
            }
        }
    }
}

int main() {
    int edges, u, v, w, src, dest;

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

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    printf("\nShortest distances from vertex %d:\n", src);
    printf("Vertex\t\tDistance\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\t\tINFINITY\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }

    printf("\nEnter destination vertex: ");
    scanf("%d", &dest);

    if (dist[dest] == INT_MAX) {
        printf("No path from %d to %d.\n", src, dest);
    } else {
        printf("Shortest Path from %d to %d: ", src, dest);
        printPath(dest);
        printf("\nTotal Distance: %d\n", dist[dest]);
    }

    return 0;
}
