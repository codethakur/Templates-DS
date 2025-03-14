#pragma once
#include "Graph.h"

using namespace AdjacencyMatrix;

bool DFS(Graph* graph, int node, int destination, std::vector<bool>& visited) {
    if (node == destination) return true;

    visited[node] = true;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[node][i] && !visited[i]) {
            if (DFS(graph, i, destination, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool HasSimplePath(Graph* graph, int source, int destination)
{
    std::vector<bool> visited(graph->V, false);
    return DFS(graph, source, destination, visited);
}

#if 0
bool HasSimplePath(Graph* graph, int source, int destination) {
    std::vector<bool> visited(graph->V, false); // Track visited nodes
    std::stack<int> s;  // Stack to simulate recursion

    s.push(source); // Start DFS from source

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (node == destination) return true;  //  Found path

        if (!visited[node]) {
            visited[node] = true;  //  Mark node as visited

            //  Push all unvisited neighbors to the stack
            for (int i = 0; i < graph->V; i++) {
                if (graph->adjMatrix[node][i] && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }

    return false;  // No path found
}
#endif
