#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
#include<vector>
#include"stackArray.h"
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
        int v = graph->V; 

        std::cout << "Edges in Graph:\n";
        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) { // Avoiding duplicate edges
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
    void DFS_itreative(Graph* graph, int startVertex)
    {
        std::vector<bool> visited(graph->V, false);
        //std::stack<int> st;
        using namespace StackArray;
        Stack<int>st(10);
    
        st.Push(startVertex);
        visited[startVertex] = true;
    
        while (!st.isEmpty())
        {
            int vertix = st.Pop();
    
            std::cout << vertix << " ";
            for (int i = graph->V; i >= 0; i--)
            {
                if (graph->adjMatrix[vertix][i] == 1 && !visited[i])
                {
                    st.Push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void DFS_Recursion(Graph *graph, int startVertex, std::vector<bool> &visited)
    {
        visited[startVertex] = true;
        std::cout << startVertex << " ";

        for (int i = 0; i < graph->v; i++)
        {
            if (graph->adjacencyMatrix[startVertex][i] == 1 && !visited[i])
            {
                DFS_Recursion(graph, i, visited);
            }
        }
    }
     void BFS(Graph* graph, DynamicQueueModule::Queue<int>* q, std::vector<bool>& visited) {
         using namespace DynamicQueueModule;
    
         if (isEmpty(q))
             return; // Base case: Stop when queue is empty
    
         int vertex = frontElement(q);
         deQueue(q);
         std::cout << vertex << " ";
    
         for (int i = 0; i < graph->V; i++) {
             if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
                 enQueue(q, i);
                 visited[i] = true;
             }
         }
    
         // Recursive call
         BFS(graph, q, visited);
     }
     void BFS_Recursion(Graph* graph, int startVertex) {
         using namespace DynamicQueueModule;
    
         std::vector<bool> visited(graph->V, false);
         DynamicQueueModule::Queue<int>* q = DynamicQueueModule::createQueue<int>(graph->V);
         // Create a custom queue
    
         enQueue(q, startVertex);
         visited[startVertex] = true;
    
         BFS(graph, q, visited);
    
         destroyQueue(q);  // Clean up memory after BFS is complete
     }
}




namespace AdjancencyList
{
    Graph* createGraph(const int numVertices) {
        assert(numVertices > 0); // Ensure valid number of vertices

        Graph* graph = new Graph();
        graph->V = numVertices;
        graph->e = 0;

        // Initialize adjacency list with nullptrs
        graph->adjList.resize(numVertices, nullptr);

        return graph;
    }

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

    void printGraph(Graph* graph) {
        for (int i = 0; i < graph->V; i++) {
            std::cout << i << " -> ";
            ListNode* temp = graph->adjList[i]; 
            while (temp) {
                std::cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";  // End of adjacency list for this vertex
        }
    }
    void deleteGraph(Graph* graph) {
        if (!graph) return;  // Handle null pointer

        // Iterate over each adjacency list and delete all nodes
        for (int i = 0; i < graph->V; i++) {
            ListNode* temp = graph->adjList[i];
            while (temp) {
                ListNode* next = temp->next;  // Store next node
                delete temp;  // Free current node
                temp = next;  // Move to next node
            }
        }

        // No need to delete std::vector because it handles memory itself
        delete graph;  // Free the graph structure itself
    }


    void BFS_iteration(Graph* graph, int startVertex)
    {
        using namespace DynamicQueueModule;
        std::vector<int>visited(graph->V, false);
        Queue<int>* q = createQueue<int>(10);

        enQueue(q, startVertex);
        visited[startVertex] = true;

        while (!isEmpty(q))
        {
            int vertex = deQueue(q);
            std::cout << vertex << " ";

            ListNode* temp = graph->adjList[vertex];
            while (temp)
            {
                if (!visited[temp->vertex]) {
                    enQueue(q, temp->vertex);
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
    }
    using namespace DynamicQueueModule;
    void BFS(Graph* graph, DynamicQueueModule::Queue<int>* q, std::vector<bool>& visited)
    {

        if (isEmpty(q)) return;

        int vertex = deQueue(q);
        std::cout << vertex << " ";

        ListNode* temp = graph->adjList[vertex];
        while (temp)
        {
            if (!visited[temp->vertex]) {
                enQueue(q, temp->vertex);
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
        BFS(graph, q, visited);
    }
    void BFS_ReCursion(Graph* graph, int startVertex)
    {
        //using namespace DynamicQueueModule;

        std::vector<bool>visited(graph->V, false);
        DynamicQueueModule::Queue<int>* q = 
            DynamicQueueModule::createQueue<int>(graph->V);

        visited[startVertex] = true;
        enQueue(q, startVertex);

        BFS(graph, q, visited);
    }

}
using namespace DynamicQueueModule;
std::vector<int>topologySort_BFS(Graph* graph)
{
    std::vector<int>inDegree(graph->V, 0);
    Queue<int>* q = createQueue<int>(graph->V);
    std::vector<int>topologySort;

    // Compute in-degree of each vertex
    for (int i = 0; i < graph->V; i++) {
        ListNode* temp = graph->adjList[i];
        while (temp) {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }
    /* //Corrected In-Degree Calculation for Adjacency Matrix
        for (int i = 0; i < graph->v; i++) {  // i is the destination vertex
        for (int j = 0; j < graph->v; j++) {  // j is the source vertex
            if (graph->adjMatrix[j][i] == 1) { // Only count incoming edges
                inDegree[i]++;
            }
        }
    }*/
    
    // Push all vertices with in-degree 0 into queue
    for (int i = 0; i < graph->V; i++) {
        if (inDegree[i] == 0) {
            enQueue(q, i);
        }
    }

    // Process vertices
    while (!isEmpty(q))
    {
        int vertex = deQueue(q);

        topologySort.push_back(vertex);
        // Reduce in-degree of adjacent nodes
        ListNode* temp = graph->adjList[vertex];
        while (temp)
        {
            inDegree[temp->vertex]--;
            if (inDegree[temp->vertex] == 0) {
                enQueue(q, temp->vertex);
            }
            temp = temp->next;
        }

    }
    // If topological sort is not possible (cycle exists)
    if (topologySort.size() != graph->V) {
        throw std::runtime_error("Graph has a cycle, topological sort not possible!");
    }

    return topologySort;

}
void topo_DFS_Help(Graph* graph, int vertex, std::vector<bool>& visited, std::stack<int>& st) {
    visited[vertex] = true;
    ListNode* temp = graph->adjList[vertex];

    while (temp) {
        if (!visited[temp->vertex]) {
            topo_DFS_Help(graph, temp->vertex, visited, st);
        }
        temp = temp->next;
    }
    st.push(vertex);  // Push vertex after visiting all adjacent nodes
}

std::vector<int> topologySort_DFS(Graph* graph) {
    std::vector<bool> visited(graph->V, false);
    std::stack<int> st;
    std::vector<int> topoSort;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) { // Call DFS only if not visited
            topo_DFS_Help(graph, i, visited, st);
        }
    }

    while (!st.empty()) {
        int vertex = st.top();
        st.pop();
        topoSort.push_back(vertex);
    }

    return topoSort;
}
