#pragma region Yêu cầu 4


void yeuCau4()
{
	cout << "Yeu cau 4: Tim duong di ngan nhat bang thuat toan Floyd Warshall" << endl;

	string filename = "yeuCau4.txt";

	// load graph
	if (loadGraph(filename) == 1)
	{
		cout << "Loi khi load file " << filename << endl;
		cout << endl;
		return;
	}

	printGraph(adjacencyMatrix, n);

	transformGraph(adjacencyMatrix);

	printGraph(adjacencyMatrix, n);

	floydWarshall(adjacencyMatrix);

	cout << endl;
}

#pragma endregion
