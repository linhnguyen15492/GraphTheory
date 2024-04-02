#include <stdio.h>
#include "loadGraphs.h"
#include "algorithms.h"
using namespace std;

#define V 100

// graph adjacency matrix
//int directedGraph[V][V];
//int unDirectedGraph[V][V];

// graph adjacency list
//vector<int> directedAdjacencyList[V], r_directedAdjacencyList[V];
//vector<int> undirectedAdjacencyList[V];

vector<string> yeuCau2_deBai = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt" };

void resetGraph()
{
	// clear adjacency list
	for (int i = 0; i < n; i++)
	{
		directedAdjacencyList[i].clear();
		r_directedAdjacencyList[i].clear();
	}

	fill_n(directedGraph[0], V * V, 0);
	fill_n(unDirectedGraph[0], V * V, 0);
}


void yeuCau2()
{
	//int n; // số đỉnh

	cout << "Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;

	// Specify the file name
	string example = "example.txt";
	string yeuCau2_1 = "yeuCau2_1.txt";
	string yeuCau2_2 = "yeuCau2_2.txt";
	string yeuCau2_3 = "yeuCau2_3.txt";
	string yeuCau2_4 = "yeuCau2_4.txt";

	for (string v : yeuCau2_deBai)
	{
		//n = loadDirectedGraph(v, directedAdjacencyList, r_directedAdjacencyList);
		//loadDirectedGraph(v);
		//print(directedAdjacencyList, n);


		//int c = connectedComponents(directedAdjacencyList, n);
		//cout << "So thanh phan lien thong: " << c << endl;

		//stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

		//cout << endl;
		resetGraph();
	}
}

void yeuCau3()
{
	string filename = "yeuCau3.txt";
	loadEdges(filename);

	kruskal();
}


// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024\n";

	//yeuCau2();

	//n = loadDirectedGraph(yeuCau2_4, directedAdjacencyList, r_directedAdjacencyList);
	//printAdjacencyList(directedAdjacencyList, n);
	//printAdjacencyList(r_directedAdjacencyList, n);

	//stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

	yeuCau3();

	cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
