#include <iostream>
#include <vector>
#include <queue>
#include <climits>
// struct WeightedEdge {
//     int source, destination, weight;
// };

void PrimMST(WeightedGraph* graph, int startVertex)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::vector<WeightedEdge> mst;           //  Only store final MST edges
    std::vector<int> key(graph->V, INT_MAX); //  Stores min weight for each vertex

    pq.push({ 0, startVertex });
    key[startVertex] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        //  Instead of `visited[]`, check if already in MST
        if (key[u] < weight)
            continue;

        //  Store the selected edge in MST (skip first vertex)
        if (u != startVertex && !pq.empty())
        { // ✅ Check if pq is not empty before accessing pq.top()
            mst.push_back({ u, pq.top().second, weight });
        }

        //  Traverse neighbors
        for (WeightedListNode* neighbor = graph->adjList[u]; neighbor; neighbor = neighbor->next)
        {
            int v = neighbor->vertex;
            int w = neighbor->weight;

            if (w < key[v])
            { //  Update if smaller weight found
                key[v] = w;
                pq.push({ w, v });
            }
        }
    }

    // Print the MST edges like Kruskal’s Algorithm
    std::cout << "Minimum Spanning Tree Edges:\n";
    for (const auto& edge : mst)
    {
        std::cout << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
    }
}
