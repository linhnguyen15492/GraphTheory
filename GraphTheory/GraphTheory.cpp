#include <stdio.h>
#include "loadGraphs.h"
#include "algorithms.h"
#include "yeuCau1.h"
#include "yeuCau2.h"
#include "yeuCau3.h"
#include "yeuCau4.h"
#include "yeuCau5.h"
using namespace std;

// Driver Code
int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2/2023-2024 - Nhom DA-01\n";

	yeuCau2();

	//loadGraph(yeuCau2_1);
	//printGraph(adjacencyList, n);
	//printGraph(r_adjacencyList, n);
	//printGraph(adjacencyMatrix, n);
	//printGraph(undirected_adjacencyList, n);
	//printGraph(adj, n);
	//printDegree(degree, n);

	//bool a = isUndirectedGraph(adjacencyMatrix, n);
	//cout << "Is undirected graph: " << a << endl;

	//int c = connectedComponents(adjacencyList, n);
	//cout << "So thanh phan lien thong: " << c << endl;

	//stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);

	yeuCau3();


	//printGraph(adj, n);

	yeuCau5();

	cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
