#pragma region Yêu cầu 2

vector<string> inputList = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt" };

void yeuCau2()
{
	cout << "Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;

	for (string filename : inputList)
	{
		cout << "Do thi file " << filename << ":\n";

		// load graph
		if (loadGraph(filename) == 1)
		{
			cout << "Loi khi load file " << filename << endl;
			cout << endl;
			return;
		}

		// in ra ma trận kề
		printGraph(adjacencyList, n);
		printGraph(adjacencyMatrix, n);

		//printGraph(undirected_adjacencyList, n);

		// kiểm tra đồ thị có hướng
		string s = isUndirectedGraph(adjacencyMatrix, n) ? "Do thi vo huong" : "Do thi co huong";
		cout << s << endl;

		// kiểm tra đồ thị không có cạnh bội và không có cạnh khuyên
		string s1 = isLoopEdges(adjacencyMatrix, n) ? "Do thi co canh khuyen" : "Do thi khong co canh khuyen";
		cout << s1 << endl;


		// kiểm tra đồ thị có liên thông không
		int i = connectedComponents(undirected_adjacencyList, n);
		if (i > 1)
		{
			stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
			cout << "Do thi khong lien thong" << endl;
		}
		else
		{
			int j = connectedComponents(adjacencyList, n);
			if (j == 1)
			{
				// xác định thành phần liên thông mạnh
				int c = stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
				string result = c > 1 ? "Do thi lien thong tung phan" : "Do thi lien thong manh";
				cout << result << endl;
			}
			else
			{
				stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
				cout << "Do thi lien thong yeu" << endl;
			}
		}

		cout << endl;
	}
}

#pragma endregion