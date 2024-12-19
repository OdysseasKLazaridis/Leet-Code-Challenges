#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Helper function to add an edge in the adjacency list
void add_edge(int graph[MAX_NODES][MAX_NODES], int start, int end) {
    graph[start][end] = 1;
}

// Depth-First Search to find Eulerian path
int dfs(int graph[MAX_NODES][MAX_NODES], int node, int *path, int *index, int visited[MAX_NODES]) {
    visited[node] = 1;  // Mark node as visited
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] == 1 && !visited[i]) {  // If an edge exists and node is unvisited
            // Explore the edge
            dfs(graph, i, path, index, visited);
        }
    }
    path[(*index)++] = node;  // Add node to path in reverse order
    return 0;
}

void find_valid_arrangement(int pairs[][2], int size) {
    int graph[MAX_NODES][MAX_NODES] = {0};  // Initialize the graph with all zeros
    int visited[MAX_NODES] = {0};  // Initialize visited array
    
    int in_degree[MAX_NODES] = {0};  // Count the in-degree of each node
    int out_degree[MAX_NODES] = {0};  // Count the out-degree of each node
    int nodes[MAX_NODES] = {0};  // Track all unique nodes
    
    // Map the pairs into a graph and count degrees
    for (int i = 0; i < size; i++) {
        int start = pairs[i][0];
        int end = pairs[i][1];
        add_edge(graph, start, end);
        out_degree[start]++;
        in_degree[end]++;
        nodes[start] = nodes[end] = 1;  // Mark nodes that are involved in the pairs
    }

    // Find the starting node (where out-degree is greater than in-degree)
    int start_node = -1;
    for (int i = 0; i < MAX_NODES; i++) {
        if (out_degree[i] - in_degree[i] == 1) {
            start_node = i;
            break;
        }
    }
    
    // If no such start node is found, choose any node involved in the pairs
    if (start_node == -1) {
        for (int i = 0; i < MAX_NODES; i++) {
            if (nodes[i] == 1) {
                start_node = i;
                break;
            }
        }
    }

    // Find the Eulerian path using DFS
    int path[MAX_NODES];  // To store the Eulerian path
    int path_index = 0;
    
    dfs(graph, start_node, path, &path_index, visited);

    // The path is in reverse order, print it in the correct order
    for (int i = path_index - 1; i >= 0; i--) {
        printf("%d -> ", path[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1
    printf("Test Case 1: [[5, 1], [4, 5], [11, 9], [9, 4]]\n");
    int pairs1[4][2] = {
        {5, 1}, 
        {4, 5}, 
        {11, 9}, 
        {9, 4}
    };
    int size1 = 4;
    find_valid_arrangement(pairs1, size1);
    
    // Test case 2
    printf("Test Case 2: [[1, 3], [3, 2], [2, 1]]\n");
    int pairs2[3][2] = {
        {1, 3},
        {3, 2},
        {2, 1}
    };
    int size2 = 3;
    find_valid_arrangement(pairs2, size2);
    
    return 0;
}
