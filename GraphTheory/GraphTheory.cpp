#include "loadGraphs.h"
#include "algorithms.h"
#include "yeuCau1.h"
#include "yeuCau2.h"
#include "yeuCau3.h"
#include "yeuCau4.h"
#include "yeuCau5.h"
using namespace std;


int welcome()
{
	cout << "Do an Ly thuyet do thi - HK2/2023-2024 - Nhom DA-01" << endl;
	cout << "1. Yeu cau 1: Nhan dien mot so dang do thi dac biet" << endl;
	cout << "2. Yeu cau 2: Xac dinh thanh phan lien thong manh" << endl;
	cout << "3. Yeu cau 3: Tim cay khung lon nhat" << endl;
	cout << "4. Yeu cau 4: Tim duong di ngan nhat bang thuat toan Floyd Warshall" << endl;
	cout << "5. Yeu cau 5: Tim chu trinh hoac duong di Euler" << endl;
	cout << "6. Thoat chuong trinh" << endl;

	string choice;
	bool flag = true;
	do
	{
		cout << "Chon yeu cau: ";

		int v;
		cin >> choice;
		try {
			v = stoi(choice);
			cout << "Ban da chon: " << v << endl;

			flag = v < 1 || v > 6;
			//cout << "flag: " << flag << endl;
			if (flag)
			{
				cout << "Yeu cau khong hop le!" << endl;
			}
			else
			{
				cout << "Yeu cau hop le!" << endl;
				cout << "--------------------------------" << endl;
				return v;
			}
		}
		catch (exception e)
		{
			cout << "Yeu cau khong hop le!" << endl;
		}
	} while (flag);
}


// Driver Code
int main()
{
	int choice;
	do
	{
		choice = welcome();

		switch (choice)
		{
		case 1:
			yeuCau1();
			break;
		case 2:
			yeuCau2();
			break;
		case 3:
			yeuCau3();
			break;
		case 4:
			yeuCau4();
			break;
		case 5:
			yeuCau5();
			break;
		case 6:
			cout << "Ket thuc chuong trinh!" << endl;
			break;
		default:
			//cout << "Yeu cau khong hop le!" << endl;
			break;
		}
	} while (choice != 6);

	return 0;
}
