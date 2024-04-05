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
	int choice;


	cout << "Do an Ly thuyet do thi - HK2/2023-2024 - Nhom DA-01" << endl;
	cout << "1. Yeu cau 1: Kiem tra do thi co phai la do thi vo huong hay khong?" << endl;
	cout << "2. Yeu cau 2: Kiem tra do thi co phai la do thi vo huong co huong hay khong?" << endl;
	cout << "3. Yeu cau 3: Kiem tra do thi co phai la do thi co huong hay khong?" << endl;
	cout << "4. Yeu cau 4: Kiem tra do thi co phai la do thi vo huong co trong so hay khong?" << endl;
	cout << "5. Yeu cau 5: Kiem tra do thi co phai la do thi co huong co trong so hay khong?" << endl;
	cout << "6. Thoat chuong trinh" << endl;
	cout << "Chon yeu cau: ";

	cin >> choice;
	bool flag = choice < 1 || choice > 6;
	while (flag)
	{
		cout << "Yeu cau khong hop le" << choice << endl;
		cout << "Chon yeu cau: ";
		cin >> choice;

		flag = choice < 1 || choice > 6;
	}


	return choice;
}

/*
switch(expression) {
  case x:
	// code block
	break;
  case y:
	// code block
	break;
  default:
	// code block
}
*/


// Driver Code
int main()
{
	//cout << "Do an Ly thuyet do thi - HK2/2023-2024 - Nhom DA-01" << endl;

	//int choice = welcome();


	char guess;
	do
	{
		cout << "Guess a number between 1 and 10 ? " << endl;

		cin >> guess;

		guess = int(guess);

		cout << "You guessed: " << guess << endl;

	} while (guess < 1 || guess > 10);

	//bool flag = true;
	//while (true)
	//{
	//	int choice = welcome();
	//	switch (choice)
	//	{
	//	case 1:
	//		yeuCau1();
	//		break;
	//	case 2:
	//		yeuCau2();
	//		break;
	//	case 3:
	//		yeuCau3();
	//		break;
	//	case 4:
	//		yeuCau4();
	//		break;
	//	case 5:
	//		yeuCau5();
	//		break;
	//	case 6:
	//		cout << "Ket thuc chuong trinh!" << endl;
	//		flag = false;
	//		break;
	//	default:
	//		cout << "Yeu cau khong hop le!" << endl;
	//		break;
	//	}
	//}

	//yeuCau1();

	//yeuCau2();

	//yeuCau3();

	//yeuCau4();

	//yeuCau5();

	//cout << "Ket thuc chuong trinh!" << endl;

	return 0;
}
