#pragma region Yêu cầu 5


vector<string> filename_yeuCau5 = { "yeuCau5_1.txt", "yeuCau5_2.txt", "yeuCau5_3.txt" };

void yeuCau5()
{
	cout << "Yeu cau 5: Tim chu trinh hoac duong di Euler" << endl;

	string filename = "yeuCau5_3.txt";

	//loadGraph(filename);
	if (loadGraph(filename) == 1)
	{
		cout << "Loi khi load file " << filename << endl;
		cout << endl;
		return;
	}

	// in ra đồ thị danh sách kề
	printGraph(adj, n);
	printDegree(degree, n);

	// kiểm tra đồ thị vô hướng
	string s = isUndirectedGraph(adjacencyMatrix, n) ? "Do thi vo huong" : "Do thi co huong";
	cout << s << endl;

	// kiểm tra đồ thị liên thông
	int i = connectedComponents(undirected_adjacencyList, n);
	if (i > 1)
	{
		stronglyConnectedComponents(adjacencyList, r_adjacencyList, n);
		cout << "Do thi khong lien thong" << endl;
	}
	else
	{
		cout << "Do thi lien thong" << endl;
	}

	// kiểm tra đồ thị có chu trình hoặc đường đi euler 
	bool eulerCircuit = isEulerCircuit(degree, n);
	bool eulerPath = false;

	if (eulerCircuit)
	{
		cout << "Do thi Euler" << endl;
	}
	else
	{
		eulerPath = isEulerPath(degree, n);

		if (eulerPath)
			cout << "Do thi nua Euler" << endl;
		else
			cout << "Do thi khong Euler" << endl;
	}

	// xác định chu trình hoặc đường đi euler
	int source;
	if (eulerCircuit || eulerPath)
	{
		cout << "Nhap dinh bat dau: ";
		cin >> source;

		int deg = getDegree(source);
		if (eulerPath && deg % 2 == 0)
		{
			cout << "euler path " << eulerPath << endl;
			cout << "Khong co loi giai" << endl;
		}
		else
		{
			euler(source);
		}
	}

	cout << endl;
}

#pragma endregion
