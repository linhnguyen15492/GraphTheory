
#pragma region Yêu cầu 1


void yeuCau1()
{
	cout << "Yeu cau 1: Nhan dien mot so dang do thi dac biet" << endl;

	string filename = "yeuCau1_2.txt";

	if (loadGraph(filename) == 1)
	{
		cout << "Loi khi load file " << filename << endl;
		cout << endl;
		return;
	}

	printGraph(adjacencyMatrix, n);

	int res = isWindmillGraph_Wd3n(adjacencyMatrix);

	string v = res > 0 ? "Wd(3," + to_string(res) + ")" : "Khong";

	if (res == 0)
	{
		cout << "Do thi coi xay gio: " << v << endl;
	}
	else
	{
		cout << "Do thi coi xay gio: " << v << endl;
	}

	cout << endl;
}

#pragma endregion
