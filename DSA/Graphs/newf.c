#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // For memset

// Using a sufficiently large static size is common in C for competitive programming
#define MAXN 100005

// --- Adjacency List & Visited Array ---
// Using a simple array of vectors is not possible in C.
// We'll create a dynamic adjacency list.
typedef struct {
    int* neighbors;
    int count;      // How many neighbors are currently stored
    int capacity;   // How much memory is allocated
} Node;

Node adj[MAXN];
bool visited[MAXN];

// Function to add a neighbor to a node's adjacency list
void add_neighbor(int u, int v) {
    // If the list is full, double its capacity
    if (adj[u].count == adj[u].capacity) {
        adj[u].capacity = adj[u].capacity == 0 ? 4 : adj[u].capacity * 2;
        adj[u].neighbors = (int*)realloc(adj[u].neighbors, adj[u].capacity * sizeof(int));
        if (adj[u].neighbors == NULL) {
            // Handle memory allocation failure
            exit(1);
        }
    }
    adj[u].neighbors[adj[u].count++] = v;
}

// Standard DFS function to traverse a component
void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < adj[u].count; ++i) {
        int v = adj[u].neighbors[i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// Function to free allocated memory
void free_graph(int n) {
    for (int i = 1; i <= n; ++i) {
        if (adj[i].neighbors != NULL) {
            free(adj[i].neighbors);
            adj[i].neighbors = NULL; // Good practice
        }
    }
}

int main() {
    // Note: C does not have fast I/O like C++. Standard printf/scanf are usually fine.
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    // --- State Initialization/Reset ---
    // Initialize adjacency list capacities and counts to 0
    for (int i = 1; i <= n; ++i) {
        adj[i].count = 0;
        adj[i].capacity = 0;
        adj[i].neighbors = NULL;
    }
    // Initialize visited array to false
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Add edges in both directions for an undirected graph
        add_neighbor(u, v);
        add_neighbor(v, u);
    }
    
    // --- Core Logic: Find Connected Components ---
    
    // Store representative cities in a dynamic array
    int* representatives = NULL;
    int components_count = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // Found a new component
            components_count++;
            representatives = (int*)realloc(representatives, components_count * sizeof(int));
            if (representatives == NULL) {
                exit(1); // Handle memory allocation failure
            }
            representatives[components_count - 1] = i;
            
            // Traverse the component
            dfs(i);
        }
    }

    // --- Output the Result ---
    
    int roads_needed = components_count > 0 ? components_count - 1 : 0;
    
    printf("%d\n", roads_needed);
    
    for (int i = 0; i < roads_needed; ++i) {
        printf("%d %d\n", representatives[i], representatives[i + 1]);
    }
    
    // --- Clean up ---
    free(representatives);
    free_graph(n);

    return 0;
}   