#include <stdio.h>

#define MAX_VERTICES 100

void printAdjacencyMatrix(int matrix[][MAX_VERTICES], int vertices);

int main() {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, edges;
    int src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (format: source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    printAdjacencyMatrix(adjacencyMatrix, vertices);

    return 0;
}

void printAdjacencyMatrix(int matrix[][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
