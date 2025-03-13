#include "weightedGraph.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace weightedGraph;

void BellmanFordAlgo(WeightedGraph* graph, int startVertex)
{
    if (!graph || startVertex < 0 || startVertex >= graph->V) {
        throw std::runtime_error("Invalid graph or start vertex");
    }

    const int INF = std::numeric_limits<int>::max();
    std::vector<int> distance(graph->V, INF);
    std::vector<int> parent(graph->V, -1);

    distance[startVertex] = 0;

    // **Relax all edges V-1 times**
    for (int i = 0; i < graph->V - 1; i++) {
        for (int u = 0; u < graph->V; u++) {
            WeightedListNode* temp = graph->adjList[u];
            while (temp) {
                int v = temp->vertex;
                int weight = temp->weight;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
                temp = temp->next;
            }
        }
    }

    // **Check for negative weight cycles**
    for (int u = 0; u < graph->V; u++) {
        WeightedListNode* temp = graph->adjList[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                std::cout << "Graph contains a negative weight cycle!" << std::endl;
                return;
            }
            temp = temp->next;
        }
    }

    // **Print shortest distances**
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < graph->V; i++) {
        std::cout << i << "\t" << (distance[i] == INF ? -1 : distance[i]) << "\n";
    }
}
