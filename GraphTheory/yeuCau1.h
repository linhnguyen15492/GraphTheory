
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

	printGraph(adjacencyList, n);

	// kiểm tra đồ thị cối xay gió
	int r1 = isWindmillGraph_Wd3n();
	string s1 = r1 > 0 ? "Wd(3," + to_string(r1) + ")" : "Khong";

	cout << "Do thi coi xay gio: " << s1 << endl;

	// kiểm tra đồ thị Barbell
	int r2 = isBarbellGraph();
	string s2 = r2 > 0 ? "Bac " + to_string(r2) : "Khong";

	cout << "Do thi Barbell: " << s2 << endl;

	// đồ thị k-phan
	cout << "Do thi k-phan: ";
	kParite();

	cout << endl;
}

#pragma endregion
