#include <stdio.h>
#include <limits.h>  // For using INT_MAX

int cost[10][10], n, t[10][2], sum;
void prims(int cost[10][10], int n);

int main() {
    int i, j;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix (graph cost)
    printf("Enter the cost adjacency matrix (use a large value like 999 for no connection):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Call Prim's algorithm
    prims(cost, n);

    // Output the edges of the minimal spanning tree
    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    // Output the sum of the MST
    printf("Sum of minimal spanning tree: %d\n", sum);

    return 0;
}

void prims(int cost[10][10], int n) {
    int i, j, u, v;
    int min, source;
    int p[10], d[10], s[10];

    // Initialize the arrays
    for (i = 0; i < n; i++) {
        d[i] = INT_MAX;  // Set initial distance to "infinity"
        s[i] = 0;        // Set all vertices as not included in MST
        p[i] = -1;       // Parent array to store the MST structure
    }

    // Start from vertex 0
    source = 0;
    d[source] = 0;  // Distance to itself is 0
    sum = 0;        // Initialize MST sum to 0

    // Find MST
    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        u = -1;

        // Find the vertex with minimum distance that is not yet in MST
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        // If we found a valid vertex u, include it in MST
        if (u != -1) {
            s[u] = 1;  // Mark vertex u as included in MST
            sum += min; // Add the edge's weight to the MST sum

            // Store the edge in the MST result array
            if (p[u] != -1) {
                t[i][0] = p[u];
                t[i][1] = u;
            }

            // Update distances of the adjacent vertices
            for (v = 0; v < n; v++) {
                // Only update if v is not yet included in MST and there's an edge
                if (s[v] == 0 && cost[u][v] < d[v] && cost[u][v] != 0) {
                    d[v] = cost[u][v];
                    p[v] = u;
                }
            }
        }
    }
}
