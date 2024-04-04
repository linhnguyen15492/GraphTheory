#pragma region Yêu cầu 2

vector<string> inputList = { "yeuCau2_1.txt", "yeuCau2_2.txt","yeuCau2_3.txt", "yeuCau2_4.txt", "yeuCau3.txt" };

void yeuCau2()
{
	cout << "Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;

	for (string v : inputList)
	{
		// load graph
		loadGraph(v);

		printGraph(adjacencyMatrix, n);

		// kiểm tra đồ thị có hướng
		if (!isUndirectedGraph(adjacencyMatrix, n))
		{
			cout << "Day la do thi co huong" << endl;
		}
		else {
			cout << "Day la do thi vo huong" << endl;
		}

		// kiểm tra đồ thị không có cạnh bội và không có cạnh khuyên


		// kiểm tra đồ thị có liên thông không

		// xác định thành phần liên thông mạnh
		//stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
	}
}

#pragma endregion