#include <iostream>
#include <Windows.h>
#include <time.h>

#include "sort.h"

using namespace std;

int main()
{
	int* A = new int[100];
	int length;
	int i, choose, t;
	do {
		cout << "Choose type of sorting: " << endl;
		cout << "\t1. QuickSort" << endl;
		cout << "\t2. RandomizedQuickSort" << endl;
		cout << "\t3. RandomizedSelect" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "Enter size of array: " << endl;
			std::cin >> length;
			cout << "Enter elements: " << endl;
			int p = 0, r = length - 1;
			for (int i = 0; i < length; i++) {
				cin >> A[i];
			}
			QuickSort(A, p, r);
			show(A, length);
		}
		break;
		case 2:
		{
			cout << "Enter size of array: " << endl;
			std::cin >> length;
			cout << "Enter elements: " << endl;
			int p = 0, r = length - 1;
			for (int i = 0; i < length; i++) {
				cin >> A[i];
			}
			RandomizedQuickSort(A, p, r);
			show(A, length);
		}
		break;
		case 3:
		{
			cout << "Enter size of array: " << endl;
			std::cin >> length;
			cout << "Enter elements: " << endl;
			int p = 0, r = length - 1;
			for (int i = 0; i < length; i++) {
				cin >> A[i];
			}
			RandomizedQuickSort(A, p, r);
			show(A, length);
			cout << "A[min] = " << A[0] << endl;
			cout << "A[max] = " << A[r] << endl;
			if (length % 2 == 0) {
				cout << "A[middle] = " << A[r / 2] << " , " << A[(r / 2) + 1] << endl;
			}
			else {
				cout << "A[middle] = " << A[r / 2] << endl;
			}
		}
		break;
		}
	} while (true);
	return 0;
}