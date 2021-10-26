#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	int choose, length;
	cout << "Enter your choice:" << endl;
	cout << "\t1. Counting sort" << endl;
	cout << "\t2. Radix sort" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		cout << "Enter size of array: " << endl;
		cin >> length;
		int* A = new int[length];
		int p = 0, r = length - 1;
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < length; i++) {
			cin >> A[i];
		}
		countingSort(A, length);
	}
	break;
	case 2:
	{
		cout << "Enter size of array: " << endl;
		cin >> length;
		int* A = new int[length];
		int p = 0, r = length - 1;
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < length; i++) {
			cin >> A[i];
		}
		radixSort(A, length);
	}
	break;
	}
	return 0;
}