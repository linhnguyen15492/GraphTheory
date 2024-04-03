#include <stdio.h>
#include "loadGraphs.h"
#include "algorithms.h"
using namespace std;

vector<string> inputList = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt", "yeuCau3.txt" };

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

	for (string v : inputList)
	{
		//n = loadDirectedGraph(v, directedAdjacencyList, r_directedAdjacencyList);
		//loadDirectedGraph(v);
		//print(directedAdjacencyList, n);


		//int c = connectedComponents(directedAdjacencyList, n);
		//cout << "So thanh phan lien thong: " << c << endl;

		//stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

		//cout << endl;

		loadGraph(v);
		printGraph(adjacencyList, n);
		printGraph(adjacencyMatrix, n);
		printGraph(adj, n);

		bool a = isUndirectedGraph(adjacencyMatrix, n);
		cout << "Is undirected graph: " << a << endl;

		resetGraph();
	}
}

void yeuCau3()
{
	cout << "Yeu cau 3: Tim cay khung lon nhat" << endl;

	string filename = "yeuCau3.txt";
	loadEdges(filename);

	kruskal();
}


// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024\n";

	yeuCau2();

	//n = loadDirectedGraph(yeuCau2_4, directedAdjacencyList, r_directedAdjacencyList);
	//printAdjacencyList(directedAdjacencyList, n);
	//printAdjacencyList(r_directedAdjacencyList, n);

	//stronglyConnectedComponents(directedAdjacencyList, r_directedAdjacencyList, n);

	//yeuCau3();

	//prim();

	//printGraph(adj, n);

	cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
