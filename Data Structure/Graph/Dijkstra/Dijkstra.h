#pragma once
#include "weightedGraph.h"
#include<queue>
#include<vector>
#include<climits>

void Dijkstra(WeightedGraph* graph, int startVertex)
{
	if (!graph || startVertex<0 || startVertex>graph->V) {
		throw std::runtime_error("Invalid graph or start vertex");
	}
	const int INF = std::numeric_limits<int>::max();
	std::vector<int>distance(graph->V, INF);

	std::vector<int>parent(graph->V, -1);
	distance[startVertex] = 0;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>pq;

	pq.push({ 0, startVertex });

	while (!pq.empty())
	{
		int currDist = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		WeightedListNode* temp = graph->adjList[u];
		while (temp)
		{
			int v = temp->vertex;
			int weight = temp->weight;

			if (distance[u] + weight < distance[v]) {
				distance[v] = distance[u] + weight;
				parent[v] = u;
				pq.push({ distance[v], v });
			}
			temp = temp->next;

		}
	}
	// Print shortest distances
	std::cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < graph->V; i++)
	{
		std::cout << i << "\t" << (distance[i] == INF ? -1 : distance[i]) << "\n";
	}
	std::cout << "\nShortest Path Tree (Parent Array):\n";
	for (int i = 0; i < graph->V; i++)
	{
		std::cout << "Parent of " << i << ": " << parent[i] << "\n";
	}
}


#if 0
#include"weightedGraph.h"
#include"Dijkstra.h"

int main() {
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

	std::cout << "\n";

	Dijkstra(graph, 0);
	deleteGraph(graph);

	system("pause>0");
	return 0;
}
#endif
