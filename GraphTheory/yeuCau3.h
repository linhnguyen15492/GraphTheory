#pragma region Yêu cầu 3

void yeuCau3()
{
	cout << "Yeu cau 3: Tim cay khung lon nhat" << endl;

	string filename = "yeuCau3.txt";

	// load graph
	loadEdges(filename);

	// kiểm tra đồ thị vô hướng 



	// kiểm tra đồ thị liên thông
	string v = isConnected(undirected_adjacencyList, n) ? "Do thi lien thong" : "Do thi khong lien thong";
	cout << v << endl;

	// tìm cây khung lớn nhất bằng thuật toán Prim
	prim();

	// tìm cây khung lớn nhất bằng thuật toán Kruskal
	kruskal();
}


#pragma endregion
