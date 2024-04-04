#pragma region Yêu cầu 5

void yeuCau5()
{
	cout << "Yeu cau 5: Tim chu trinh hoac duong di Euler" << endl;

	//loadGraph(filename);


	// kiểm tra đồ thị vô hướng


	// kiểm tra đồ thị liên thông


	// kiểm tra đồ thị có chu trình hoặc đường đi euler 


	// xác định chu trình hoặc đường đi euler


	string filename = "yeuCau5_3.txt";
	loadGraph(filename);
	printGraph(adj, n);
	printDegree(degree, n);
	cout << "Is euler circuit " << isEulerCircuit(degree, n) << endl;
	cout << "Is euler path " << isEulerPath(degree, n) << endl;

	euler(3);

	cout << endl;
}

#pragma endregion
