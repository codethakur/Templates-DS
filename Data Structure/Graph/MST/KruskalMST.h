#pragma once
#include"weightedGraph.h"
#include"DisjointSet.h"
#include<algorithm>

void KruskalMST(WeightedGraph* graph)
{
		std::vector<WeightedEdge> mst;

		// Step 1: Sort edges by weight
		std::sort(graph->edges.begin(), graph->edges.end(),
			[](const  WeightedEdge& a, const  WeightedEdge& b) {
				return a.weight < b.weight;
			});
		// Step 2: Initialize Disjoint Set for `V` vertices
		DisjointSet ds(graph->V);

		// Step 3: Process edges and add to MST if no cycle is formed

		for (const auto& edge : graph->edges)
		{
			if (ds.find(edge.source) !=  ds.find(edge.destination)) {
				mst.push_back(edge);
				ds.unionSets(edge.source, edge.destination);
			}
		}

		std::cout << "Minimum Spannning Tree Edges:\n";
		for (const auto& edge : mst)
		{
			std::clog << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
		}


}
