#pragma region Yêu cầu 2

vector<string> inputList = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt" };

void yeuCau2()
{
	cout << "Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;

	for (string v : inputList)
	{
		// load graph
		loadGraph(v);

		// in ra ma trận kề
		printGraph(adjacencyMatrix, n);

		//printGraph(undirected_adjacencyList, n);

		// kiểm tra đồ thị có hướng
		string s = isUndirectedGraph(adjacencyMatrix, n) ? "Do thi vo huong" : "Do thi co huong";
		cout << s << endl;


		// kiểm tra đồ thị không có cạnh bội và không có cạnh khuyên


		// kiểm tra đồ thị có liên thông không
		int i = connectedComponents(undirected_adjacencyList, n);
		string check = i > 1 ? "Do thi khong lien thong" : "Do thi lien thong";
		cout << check << endl;


		// xác định thành phần liên thông mạnh
		//stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
	}
}

#pragma endregion