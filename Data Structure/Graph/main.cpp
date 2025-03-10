#include"Graph.h"
#include<iostream>

// Example Usage

int main()
{
    using namespace adjacencyMatrix;
    Graph *graph = adjacencyMatrix::createGraph(5);

    insertEdge(graph, new Edge{0, 1});
    insertEdge(graph, new Edge{0, 4});
    insertEdge(graph, new Edge{1, 2});
    insertEdge(graph, new Edge{1, 3});
    insertEdge(graph, new Edge{1, 4});

    PrintGraph(graph);
    std::cout << "\n------adjencyList-----\n";

    using namespace adjacencyList;
    Graph *graph = adjacencyList::CreateGraph(5);

    adjacencyList::insertEdge(graph, new Edge{0, 1});
    adjacencyList::insertEdge(graph, new Edge{0, 4});
    adjacencyList::insertEdge(graph, new Edge{1, 2});
    adjacencyList::insertEdge(graph, new Edge{1, 3});
    adjacencyList::insertEdge(graph, new Edge{1, 4});
    adjacencyList::deleteGraph(graph);

    adjacencyList::printGraph(graph);
    adjacencyList::deleteGraph(graph);
    adjacencyList::printGraph(graph);

    return 0;
}
