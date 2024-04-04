#pragma region Yêu cầu 3

void yeuCau3()
{
	cout << "Yeu cau 3: Tim cay khung lon nhat" << endl;

	string filename = "yeuCau3.txt";
	loadEdges(filename);

	kruskal();

	prim();
}


#pragma endregion
