#pragma once
#include <stdexcept>

#include <vector>

#include <iostream>

struct WeightedListNode
{
    int vertex;
    int weight;
    WeightedListNode* next;
};
struct WeightedEdge
{
    int source;
    int destination;
    int weight;
};

struct WeightedGraph
{
    int V;
    int e;
    std::vector<WeightedListNode*> adjList;
    std::vector<WeightedEdge> edges;  //  Add this to store all edges

};
namespace weightedGraph
{
    int insertEdge(WeightedGraph* graph, WeightedEdge* E)
    {
        int n = graph->V;
        int from = E->source;
        int to = E->destination;
        int weight = E->weight;

        if (from < 0 || from >= n || to < 0 || to >= n)
        {
            throw std::runtime_error("out of bound");
        }
        WeightedListNode* ptr = graph->adjList[from];

        WeightedListNode* newNode = new WeightedListNode{ to, weight, ptr };
        graph->adjList[from] = newNode;
        graph->edges.push_back({ from, to, weight });  //  Store edge for Kruskal’s Algorithm
        return 1;
    }

    WeightedGraph* CreateGraph(int numVertex)
    {
        WeightedGraph* graph = new WeightedGraph();
        graph->V = numVertex;
        graph->e = 0;
        graph->adjList.resize(numVertex, nullptr);
        return graph;
    }

    void deleteGraph(WeightedGraph* graph) {
        if (!graph) return;  // Handle null pointer

        // Iterate through each adjacency list and delete all nodes
        for (int i = 0; i < graph->V; i++) {
            WeightedListNode* temp = graph->adjList[i];
            while (temp) {
                WeightedListNode* next = temp->next;  // Store next node
                delete temp;  // Free current node
                temp = next;  // Move to next node
            }
        }

        delete graph;  // Free the graph structure itself
        graph = nullptr;
    }

    void printGraph(WeightedGraph* Graph)
    {
        if (!Graph)
        {
            throw std::runtime_error("weighted graph not found");
        }

        for (int i = 0; i < Graph->V; i++)
        {
            std::cout << i << " -> ";
            WeightedListNode* temp = Graph->adjList[i];
            while (temp)
            {
                std::cout << temp->vertex << "(w: " << temp->weight << ") -> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";
        }
    }


}
