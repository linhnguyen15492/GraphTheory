// GraphTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include "factorial.h"
#include "loadGraph.h"
#include "algorithms.h"
#include "helper.h"

using namespace std;

#define V 100


//void danhSachKe()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		adjacencyList[x].push_back(y);
//		adjacencyList[y].push_back(x); // Nếu là đồ thị có hướng thì bỏ dòng này
//	}
//
//	memset(visited, false, sizeof(visited));
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i << " : ";
//		for (int x : adjacencyList[i])
//		{
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//}


class GFG {
public:
	// dfs Function to reach destination
	bool dfs(int curr, int des, vector<vector<int> >& adj,
		vector<int>& vis)
	{

		// If curr node is destination return true
		if (curr == des) {
			return true;
		}
		vis[curr] = 1;
		for (auto x : adj[curr]) {
			if (!vis[x]) {
				if (dfs(x, des, adj, vis)) {
					return true;
				}
			}
		}
		return false;
	}

	// To tell whether there is path from source to
	// destination
	bool isPath(int src, int des, vector<vector<int> >& adj)
	{
		vector<int> vis(adj.size() + 1, 0);
		return dfs(src, des, adj, vis);
	}

	// Function to return all the strongly connected
	// component of a graph.
	vector<vector<int> > findSCC(int n, vector<vector<int>>& a)
	{
		// Stores all the strongly connected components.
		vector<vector<int> > ans;

		// Stores whether a vertex is a part of any Strongly
		// Connected Component
		vector<int> is_scc(n + 1, 0);

		vector<vector<int> > adj(n + 1);

		for (int i = 0; i < a.size(); i++) {
			adj[a[i][0]].push_back(a[i][1]);
		}

		// Traversing all the vertices
		for (int i = 1; i <= n; i++) {

			if (!is_scc[i]) {

				// If a vertex i is not a part of any SCC
				// insert it into a new SCC list and check
				// for other vertices whether they can be
				// thr part of thidl ist.
				vector<int> scc;
				scc.push_back(i);

				for (int j = i + 1; j <= n; j++) {

					// If there is a path from vertex i to
					// vertex j and vice versa put vertex j
					// into the current SCC list.
					if (!is_scc[j] && isPath(i, j, adj)
						&& isPath(j, i, adj)) {
						is_scc[j] = 1;
						scc.push_back(j);
					}
				}

				// Insert the SCC containing vertex i into
				// the final list.
				ans.push_back(scc);
			}
		}
		return ans;
	}
};


// Number of vertices and edges
int graph[V][V];

// adjacency list
std::vector<int> adjacencyList[1001];
bool visited[100];

// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024\n";

	// Specify the file name
	string fileName1 = "example.txt";
	string fileName2 = "yeuCau2_1.txt";

	loadGraph(fileName2, adjacencyList);
	loadGraphAdjMatrix(graph, adjacencyList);
	printAdjacencyList(adjacencyList);
	printAdjacencyMatrix(graph);

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

	return 0;
}
