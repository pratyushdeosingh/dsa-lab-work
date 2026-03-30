#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX * MAX];
struct Edge mst[MAX];
int parent[MAX];
int rank[MAX];
int edgeCount = 0;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (rank[px] < rank[py])
        parent[px] = py;
    else if (rank[px] > rank[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int vertices, numEdges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = w;
    }

    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstEdges = 0;
    int totalCost = 0;

    for (int i = 0; i < numEdges && mstEdges < vertices - 1; i++) {
        int pu = find(edges[i].src);
        int pv = find(edges[i].dest);

        if (pu != pv) {
            mst[mstEdges++] = edges[i];
            totalCost += edges[i].weight;
            unionSets(pu, pv);
        }
    }

    printf("\nMST Edges (Kruskal's Algorithm):\n");
    printf("Edge\t\tWeight\n");
    for (int i = 0; i < mstEdges; i++) {
        printf("%d - %d\t\t%d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
    printf("Total Cost of MST: %d\n", totalCost);

    return 0;
}
