#pragma region Yêu cầu 3

void yeuCau3()
{
	cout << "Yeu cau 3: Tim cay khung lon nhat" << endl;

	// load graph


	// kiểm tra đồ thị vô hướng 


	// kiểm tra đồ thị liên thông



	string filename = "yeuCau3.txt";
	loadEdges(filename);

	// tìm cây khung lớn nhất bằng thuật toán Prim
	prim();

	// tìm cây khung lớn nhất bằng thuật toán Kruskal
	kruskal();
}


#pragma endregion
