#include <stdio.h>
#include "loadGraphs.h"
#include "algorithms.h"
using namespace std;

#define V 100

// graph adjacency matrix
int directedGraph[V][V];
int unDirectedGraph[V][V];

// graph adjacency list
vector<int> directedAdjacencyList[V], r_directedAdjacencyList[V];
vector<int> undirectedAdjacencyList[V];

vector<string> yeuCau2 = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt" };

// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024\n";

	int n; // số đỉnh

	// Specify the file name
	string example = "example.txt";
	string yeuCau2_1 = "yeuCau2_1.txt";
	string yeuCau2_2 = "yeuCau2_2.txt";
	string yeuCau2_3 = "yeuCau2_3.txt";
	string yeuCau2_4 = "yeuCau2_4.txt";

	for (string v : yeuCau2)
	{
		n = loadDirectedGraph(v, directedAdjacencyList, r_directedAdjacencyList);
		stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

		// clear adjacency list
		for (int i = 0; i < n; i++)
		{
			directedAdjacencyList[i].clear();
			r_directedAdjacencyList[i].clear();

		}
	}

	//n = loadDirectedGraph(yeuCau2_4, directedAdjacencyList, r_directedAdjacencyList);
	//printAdjacencyList(directedAdjacencyList, n);
	//printAdjacencyList(r_directedAdjacencyList, n);

	//stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

	cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
