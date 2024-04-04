#pragma region yêu cầu 5

void yeuCau5()
{
	cout << "Yeu cau 5: Tim chu trinh hoac duong di Euler" << endl;

	//string filename = "yeuCau5_1.txt";
	//loadGraph(filename);
	//printGraph(adj, n);

	string filename = "yeuCau5_3.txt";
	loadGraph(filename);
	printGraph(adj, n);
	printDegree(degree, n);
	cout << "Is euler circuit " << isEulerCircuit(degree, n) << endl;
	cout << "Is euler path " << isEulerPath(degree, n) << endl;

	euler(3);
}

#pragma endregion
