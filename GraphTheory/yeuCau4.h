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

	// print graph
	printGraph(adjacencyMatrix, n);
	transformGraph(adjacencyMatrix);
	//printGraph(adjacencyMatrix, n);

	// kiểm tra đồ thị có trọng số dương
	string s = isPositiveWeight(degrees) ? "Do thi co trong so duong" : "Khong phai do thi co trong so duong";
	cout << s << endl;

	// tìm đường đi ngắn nhất bằng thuật toán Floyd Warshall
	floydWarshall(adjacencyMatrix);

	cout << endl;
}

#pragma endregion
