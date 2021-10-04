#include <iostream>
#include "heap.h"

using namespace std;

int Parent(int i) {
	return (i - 1) / 2;
}; // індекс батьківського вузла

int Left(int i) {
	return (2 * i + 1);
}; // індекс лівого нащадка

int Right(int i) {
	return (2 * i + 2);
}; // індекс правого нащадка

/* функція, що змінює порядок сортування, при умові,
	що елемент є меншим ніж хоча б один з нащадків.
	після того, як в дереві буде знайдене порушення,
	елементи міняються місцями*/
void MaxHeapify(int* arr, int n, int i) {
	int largest = i;
	int l = Left(i);
	int r = Right(i);

	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, n, largest);
	}
	//for (int i = 0; i < sizeof(arr); i++) {
	//	cout << "maxheap: " << arr[i] << "\t";
	//}
	//cout << "\n";
};

/* функція, що змінює порядок сортування, при умові,
	що елемент є більшим ніж хоча б один з нащадків*/
void MinHeapify(int* arr, int n, int i) {
	int smallest = i;
	int l = Left(i);
	int r = Right(i);
	if (l < n && arr[l] < arr[smallest]) {
		smallest = l;
	}
	if (r < n && arr[r] < arr[smallest])
	{
		smallest = r;
	}
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		MinHeapify(arr, n, smallest);
	}
	//for (int i = 0; i < sizeof(arr); i++) {
	//	cout << "minheap: " << arr[i] << "\t";
	//}
	//cout << "\n";
};

/* метод, що будує незростаючу піраміду*/
void BuildMaxHeap(int* arr, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		MaxHeapify(arr, n, i);
	}
};

/* метод, що будує неспадну піраміду*/
void BuildMinHeap(int* arr, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		MinHeapify(arr, n, i);
	}
};

/* метод, що сортує масив в порядку зростання чи спадання*/
void HeapSort(int* arr, int n) {
	cout << "In which order implement sorting? : " << endl;
	cout << "1. Decreasing order \n";
	cout << "2. Ascending order \n";
	int k = 0;
	cin >> k;
	if (k == 1) {
		// перегруповуємо масив
		for (int i = n / 2 - 1; i >= 0; i--) {
			MinHeapify(arr, n, i);
		}
		// оброблюємо один за одним елементи з купи
		for (int i = n - 1; i >= 0; i--)
		{
			// корінь зміщуємо в кінець
			swap(arr[0], arr[i]);
			// ще раз сортуємо зменшену неспадну піраміду
			MinHeapify(arr, i, 0);
		}
	}
	if (k == 2) {
		for (int i = n / 2 - 1; i >= 0; i--)
			MaxHeapify(arr, n, i);
		for (int i = n - 1; i > 0; i--) {
			swap(arr[0], arr[i]);
			// ще раз сортуємо зменшену незростаючу піраміду
			MaxHeapify(arr, i, 0);
		}
	}
};

/* функція, що знаходить найбільший елемент*/
int HeapMax(int* arr, int n) {
	BuildMaxHeap(arr, n);
	return arr[0];
};

/* функція, що знаходить найменший елемент*/
int HeapMin(int* arr, int n) {
	BuildMinHeap(arr, n);
	return arr[0];
};

/* функція, що видаляє найбільший елемент*/
int HeapExtractMax(int* arr, int& n) {
	int max = HeapMax(arr, n);
	arr[0] = arr[n - 1];
	n--;
	MaxHeapify(arr, n, 0);
	return max;
};

/* функція, що видаляє найменший елемент*/
int HeapExtractMin(int* arr, int& n) {
	int min = HeapMin(arr, n);
	arr[0] = arr[n - 1];
	n--;
	MinHeapify(arr, n, 0);
	return min;
};

/* функція, що змінює обраний елемент на більший*/
void HeapIncreaseKey(int* arr, int i, int key) {
	arr[i] = key;
	while (i != 0 && arr[Parent(i) < arr[i]])
	{
		swap(arr[i], arr[Parent(i)]);
		i = Parent(i);
	}
};

/* функція, що змінює обраний елемент на менший*/
void HeapDecreaseKey(int* arr, int i, int key) {
	arr[i] = key;
	while (i != 0 && arr[Parent(i) > arr[i]])
	{
		swap(arr[i], arr[Parent(i)]);
		i = Parent(i);
	}
};

/* функція, що додає елемент до масиву*/
void HeapInsertion(int* arr, int& n, int key) {
	n++;
	arr[n - 1] = key;
	MaxHeapify(arr, n, n - 1);
};

/* відображення масиву*/
void displayArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
};