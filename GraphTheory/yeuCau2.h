#pragma region yêu cầu 2


vector<string> inputList = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt", "yeuCau3.txt" };

void yeuCau2()
{
	//int n; // số đỉnh

	cout << "Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;

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
		//printGraph(adjacencyList, n);
		//printGraph(adjacencyMatrix, n);
		//printGraph(undirected_adjacencyList, n);
		//printGraph(adj, n);
		//printDegree(degree, n);

		//bool a = isUndirectedGraph(adjacencyMatrix, n);
		//cout << "Is undirected graph: " << a << endl;

		//int c = connectedComponents(adjacencyList, n);
		//cout << "So thanh phan lien thong: " << c << endl;

		stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
	}
}

#pragma endregion