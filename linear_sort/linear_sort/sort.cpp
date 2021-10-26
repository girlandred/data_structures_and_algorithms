#include "Sort.h"
#include <iostream>
using namespace std;

/* функція, що відображає масив */
void show(int A[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

/* функція, що імплементує сортування підрахунком */
void countingSort(int A[], int length)
{
	cout << " Entered array" << endl;
	show(A, length);
	int max = A[0];
	for (int i = 1; i < length; i++)
		if (A[i] > max) max = A[i];
	int* C = new int[max + 1];
	for (int j = 0; j <= max + 1; j++)
		C[j] = 0;
	for (int i = 0; i < length; i++)
		C[A[i]]++;
	cout << "Additional array" << endl;
	show(C, max + 1);
	int i = 0;
	for (int k = 0; k <= max; k++)
		for (int d = k;C[d] > 0; C[d]--)
		{
			A[i] = k;i++;
		}
	cout << " Sorted array" << endl;
	show(A, length);
}

/* функція, що здійснює сортування за розрядами */
void radixSort(int A[], int length)
{
	cout << " Entered array" << endl;
	show(A, length);
	int max = A[0];
	for (int i = 1; i < length; i++)
		if (A[i] > max) max = A[i];
	for (int i = 1; max / i > 0;i *= 10) {
		countingSort1(A, length, i);
	}
	cout << " Sorted array" << endl;
	show(A, length);
}

void countingSort1(int A[], int length, int  e)
{
	int* output_b = new int[length];
	int max = A[0];
	for (int i = 1; i < length; i++)
		if (A[i] > max) max = A[i];
	int k = max;
	int* C = new int[k] {};
	for (int i = 0;i < length; i++) {
		C[(A[i] / e) % 10]++;
	}
	for (int i = 1;i <= k; i++) {
		C[i] += C[i - 1];
	}
	for (int i = length - 1;i >= 0; i--) {
		output_b[C[(A[i] / e) % 10] - 1] = A[i];
		C[(A[i] / e) % 10]--;
	}
	for (int i = 0;i < length; i++) {
		A[i] = output_b[i];
	}
}