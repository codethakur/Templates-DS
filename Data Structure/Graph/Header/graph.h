#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include<vector>
struct ListNode {
    int vertex;
    ListNode* next;
};

struct Graph {
    int V; // Number of vertices// || Nodes
    int e; // Number of edges
    int** adjMatrix;
        /*int *AdjancencyList[] not support in C++ and avoid this ListNode * *adjList;*/
    std::vector<ListNode*> adjList; // Using vector for adjacency list
};

struct Edge {
    int source;
    int destination;
};

namespace AdjacencyMatrix {
    void rand_int() {
        srand((unsigned)time(NULL));
    }

    Graph* createGraph(const int numVertices) {
        assert(numVertices > 0); // Ensure valid number of vertices

        Graph* graph = new Graph();
        graph->V = numVertices;
        graph->e = 0;

        
        graph->adjMatrix = new int* [numVertices];// Allocate memory for adjacency matrix

        for (int i = 0; i < numVertices; i++) {
            graph->adjMatrix[i] = new int[numVertices](); // () Initializes to 0
        }

        return graph;
    }

    void displayEdge(Graph* graph) {
        int v = graph->V; // Fixed: Use 'V' correctly

        std::cout << "Edges in Graph:\n";
        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) { // Avoid duplicate edges
                if (graph->adjMatrix[i][j] == 1) {
                    std::cout << "Edge between: " << i << " - " << j << std::endl;
                }
            }
        }
    }

    void printGraph(Graph* graph) {
        if (!graph) return;
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < graph->V; i++) {
            for (int j = 0; j < graph->V; j++) {
                std::cout << graph->adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void insertEdge(Graph* graph, const Edge* E) {
        int x = E->source;
        int y = E->destination;

        if (x >= graph->V || y >= graph->V) {
            throw std::runtime_error("Error when adding edge: Out of bounds.");
        }

        if (graph->adjMatrix[x][y] == 0) {
            graph->adjMatrix[x][y] = 1;  // Mark edge from x -> y
            graph->adjMatrix[y][x] = 1;  // Mark edge from y -> x (for undirected graph)
            (graph->e)++;  // Increment edge count
        }
    }

    void removeEdge(Graph* graph, const Edge* E) {
        int x = E->source;
        int y = E->destination;

        if (x >= graph->V || y >= graph->V) {
            throw std::runtime_error("Error when removing edge: Out of bounds.");
        }

        if (graph->adjMatrix[x][y] == 1) {
            graph->adjMatrix[x][y] = 0;
            graph->adjMatrix[y][x] = 0;
            (graph->e)--;
        }
    }

    struct Edge newEdge(int x, int y) {
        Edge e;
        e.source = x;
        e.destination = y;
        return e;
    }

    // Function to generate a random graph
    Graph* randomGraph(const int N, const float p) {
        Graph* graph = createGraph(N);
        rand_int();  // Seed the random number generator

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) { // Ensures no self-loops and avoids duplicate edges
                if (rand() < p * RAND_MAX) {
                    Edge e = newEdge(i, j);
                    insertEdge(graph, &e);
                }
            }
        }

        return graph;
    }

    void deleteGraph(Graph* graph) {
        if (!graph) return;
        for (int i = 0; i < graph->V; i++) {
            delete[] graph->adjMatrix[i];
        }
        delete[] graph->adjMatrix;
        delete graph;
    }
}


namespace AdjancencyList
{
    int insertEdges(Graph* graph, const Edge* E) {
        int n = graph->V;
        int from = E->source;
        int to = E->destination;

        if (0 > from || from >= n || 0 > to || to >= n) return -1;

        ListNode* prev = nullptr;
        ListNode* ptr = graph->adjList[from];
        while (ptr != nullptr) {
            if (ptr->vertex == to) return 0; // Edge already exists
            prev = ptr;
            ptr = ptr->next; 
        }

        //  Now properly inserting at the end
        ListNode* newNode = new ListNode();
        newNode->vertex = to;
        newNode->next = nullptr;
        if (prev == nullptr) {
            graph->adjList[from] = newNode; 
        }
        else {
            prev->next = newNode;
        }

        return 1;
    }

    int removeEdge(Graph* graph, const Edge* E)
    {
        int n = graph->V;
        int from = E->source;
        int to = E->destination;

        if (from < 0 || from >= n || to < 0 || to >= n)
        {
            throw std::runtime_error("Error when removing edge: Out of bounds.");
        }

        ListNode* prev = nullptr;
        ListNode* ptr = graph->adjList[from];

        while (ptr != nullptr)
        {
            if (ptr->vertex == to)
            {
                if (prev == nullptr)
                {
                    graph->adjList[from] = ptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                }
                delete ptr;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }

        //  Also remove edge in reverse direction (for undirected graph)
        prev = nullptr;
        ptr = graph->adjList[to];

        while (ptr != nullptr)
        {
            if (ptr->vertex == from)
            {
                if (prev == nullptr)
                {
                    graph->adjList[to] = ptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                }
                delete ptr;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }

        return 1;
    }

}
