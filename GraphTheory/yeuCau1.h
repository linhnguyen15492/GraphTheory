
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

	// kiểm tra đồ thị cối xay gió
	int r1 = isWindmillGraph_Wd3n(adjacencyMatrix);

	string s1 = r1 > 0 ? "Wd(3," + to_string(r1) + ")" : "Khong";

	if (r1 == 0)
	{
		cout << "Do thi coi xay gio: " << s1 << endl;
	}
	else
	{
		cout << "Do thi coi xay gio: " << s1 << endl;
	}

	// kiểm tra đồ thị Barbell


	// đồ thị k-phan

	cout << endl;
}

#pragma endregion
