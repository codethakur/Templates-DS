#include"weightedGraph.h"
#include"KruskalMST.h"
#include"PrimMST.h"

int main() 
{
    using namespace weightedGraph;

    WeightedGraph* graph = CreateGraph(5);

    insertEdge(graph, new WeightedEdge{ 0, 1, 10 });
    insertEdge(graph, new WeightedEdge{ 0, 4, 20 });
    insertEdge(graph, new WeightedEdge{ 1, 2, 30 });
    insertEdge(graph, new WeightedEdge{ 1, 3, 40 });
    insertEdge(graph, new WeightedEdge{ 1, 4, 50 });
    insertEdge(graph, new WeightedEdge{ 3, 2, 60 });
    insertEdge(graph, new WeightedEdge{ 3, 4, 70 });

    printGraph(graph);

    std::cout << "\nKruskalMST: \n";
    KruskalMST(graph);


    std::cout << "\nPrimMST: \n";
    PrimMST(graph, 0);


    deleteGraph(graph);


    system("pause>0");
    return 0;
}
