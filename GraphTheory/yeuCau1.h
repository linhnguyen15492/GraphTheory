#pragma region Yêu cầu 1


void yeuCau1()
{
	cout << "Yeu cau 1: Nhan dien mot so dang do thi dac biet" << endl;

	string filename = "yeuCau1_1.txt";

	if (loadGraph(filename) == 1)
	{
		cout << "Loi khi load file " << filename << endl;
		cout << endl;
		return;
	}

	printGraph(adjacencyMatrix, n);


	cout << endl;
}

#pragma endregion
