#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

// Find the vertex with the minimum distance value from the set of vertices not yet processed
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm function
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Output array. dist[i] holds the shortest distance from src to i
    int visited[V];   // visited[i] is true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); // Pick the minimum distance vertex
        visited[u] = 1;

        // Update dist[v] only if it's not visited, there's an edge from u to v,
        // and total weight of path from src to v through u is smaller than current value of dist[v]
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

// Example usage
int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    printf("Dijkstra's shortest paths from vertex 0:\n");
    dijkstra(graph, 0);

    return 0;
}
