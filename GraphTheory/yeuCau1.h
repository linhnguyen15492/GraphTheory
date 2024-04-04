#pragma region Yêu cầu 1


void yeuCau1()
{
	cout << "Yeu cau 1: Nhan dien mot so dang do thi dac biet" << endl;

	string filename = "yeuCau1_1.txt";

	loadGraph(filename);

	printGraph(adjacencyMatrix, n);


	cout << endl;
}

#pragma endregion
