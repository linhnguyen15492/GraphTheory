#pragma region Yêu cầu 3

void yeuCau3()
{
	cout << "Yeu cau 3: Tim cay khung lon nhat" << endl;

	string filename = "yeuCassu3.txt";

	// load graph
	if (loadGraph(filename) == 1)
	{
		cout << "Loi khi load file " << filename << endl;
		cout << endl;
		return;
	}

	// in danh sách kề
	printGraph(adjacencyList, n);
	printGraph(adjacencyMatrix, n);
	//printGraph(undirected_adjacencyList, n);
	printGraph(edges);

	// kiểm tra đồ thị vô hướng 
	string s = isUndirectedGraph(adjacencyMatrix, n) ? "Day la do thi vo huong" : "Day la do thi co huong";
	cout << s << endl;

	// kiểm tra đồ thị liên thông
	int i = connectedComponents(undirected_adjacencyList, n);
	string check = i > 1 ? "Day la do thi khong lien thong" : "Day la do thi lien thong";
	cout << check << endl;

	// tìm cây khung lớn nhất bằng thuật toán Prim
	prim();

	// tìm cây khung lớn nhất bằng thuật toán Kruskal
	kruskal();

	cout << endl;
}


#pragma endregion
