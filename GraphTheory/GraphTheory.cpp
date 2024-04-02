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

// visited array
bool visited[V];


vector<string> yeuCau2 = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt" };

// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024\n";

	memset(visited, false, sizeof(visited));

	// Specify the file name
	string example = "example.txt";
	string yeuCau2_1 = "yeuCau2_1.txt";
	string yeuCau2_2 = "yeuCau2_2.txt";
	string yeuCau2_3 = "yeuCau2_3.txt";
	string yeuCau2_4 = "yeuCau2_4.txt";

	//for (string v : yeuCau2) {
	//	loadDirectedGraph(v, directedAdjacencyList);
	//	//loadGraphAdjMatrix(v, graph);
	//	printAdjacencyList(directedAdjacencyList);
	//	//printAdjacencyMatrix(graph);

	//	int n = connectedComponents(directedAdjacencyList);
	//	cout << "so thanh phan lien thong: " << n << endl;

	//	// clear adjacency list
	//	for (int i = 0; i < V; i++) {
	//		directedAdjacencyList[i].clear();
	//	}
	//}

	loadDirectedGraph(yeuCau2_2, directedAdjacencyList, r_directedAdjacencyList);
	printAdjacencyList(directedAdjacencyList);
	printAdjacencyList(r_directedAdjacencyList);

	//loadUndirectedGraph(yeuCau2_3, undirectedAdjacencyList);
	//loadGraphAdjMatrix(yeuCau2_3, graph);
	//printAdjacencyMatrix(graph);
	//printAdjacencyList(undirectedAdjacencyList);

	//int n = connectedComponents(directedAdjacencyList);
	//cout << "so thanh phan lien thong: " << n << endl;

	//int m = connectedComponents(undirectedAdjacencyList);
	//cout << "so thanh phan lien thong: " << m << endl;

	//checkConnected(graph, n);

	// Number of nodes
	//int n = 3;

	// Given Path Matrix
	//int graph[V][V] = {
	//	{ 0, 1, 1 },
	//	{ 0, 0, 1 },
	//	{ 0, 0, 0 },
	//};

	// Function Call
	//checkConnected(graph, n);

	//// Driver Code Starts
	//GFG obj;
	////int V = 5;
	//vector<vector<int> > edges{
	//	{ 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }
	//};
	//vector<vector<int> > ans = obj.findSCC(V, edges);
	//cout << "Strongly Connected Components are:\n";
	//for (auto x : ans) {
	//	for (auto y : x) {
	//		cout << y << " ";
	//	}
	//	cout << "\n";
	//}


	cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
