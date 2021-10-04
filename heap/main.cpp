#include <iostream>
#include "heap.h"

using namespace std;

int main() {
	//	int n = sizeof(arr) / sizeof(arr[0]);
		/*cout << "Input array" << endl;
		displayArray(arr, n);
		HeapSort(arr, n);
		cout << "Sorted array" << endl;
		displayArray(arr, n);
		return 0;*/
		//

	int arr[] = { 0 };
	int n = 0;
	cout << "Heap size is: ";
	cin >> n;
	cout << endl;
	cout << "Heap elements: " << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << endl;
	int choice = 0;
	do
	{
		cout << "Current heap: ";
		displayArray(arr, n);
		cout << "Choose: " << endl;
		cout << endl;
		cout << "1. Heap Sort" << endl;
		cout << "2. Max heap" << endl;
		cout << "3. Min heap" << endl;
		cout << "4. Heap maximum" << endl;
		cout << "5. Extract maximum" << endl;
		cout << "6. Increase key" << endl;
		cout << "7. Insertion" << endl;
		cout << "8. Heap minimum" << endl;
		cout << "9. Extract minimum" << endl;
		cout << "10. Decrease key" << endl;
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			HeapSort(arr, n);
			displayArray(arr, n);
			break;
		}
		case 2:
		{
			cout << "Max heap builded: ";
			BuildMaxHeap(arr, n);
			displayArray(arr, n);
			break;
		}
		case 3:
		{
			cout << "Min heap builded: ";
			BuildMinHeap(arr, n);
			displayArray(arr, n);
			break;
		}
		case 4:
		{
			cout << "Max: " << HeapMax(arr, n) << "\n";
			break;
		}
		case 5:
		{
			HeapExtractMax(arr, n);
			cout << "Heap with extracted maximum ";
			displayArray(arr, n);
			break;
		}
		case 6:
		{
			cout << "Enter index of element (starting from 0): ";
			int i;
			cin >> i;
			cout << endl;
			if (i >= n)
			{
				cout << "Element doesn't exist" << endl << endl;
				break;
			}
			else
			{
				cout << "Enter key: ";
				int key;
				cin >> key;
				if (key < arr[i])
				{
					cout << endl;
					cout << "Can't change. Elment is smaller" << endl << endl;
					break;
				}
				else
				{
					HeapIncreaseKey(arr, i, key);
					cout << endl;
					cout << "Heap is: ";
					displayArray(arr, n);
					break;
				}
			}
		}
		case 7:
		{
			cout << "Enter new key: ";
			int key;
			cin >> key;
			HeapInsertion(arr, n, key);
			cout << endl;
			cout << "Heap with new key: ";
			displayArray(arr, n);
			break;

		}
		case 8:
		{
			cout << "Min: " << HeapMin(arr, n) << endl << endl;
			break;

		}
		case 9:
		{
			HeapExtractMin(arr, n);
			cout << "Heap with extracted minimum ";
			displayArray(arr, n);
			break;
		}
		case 10:
		{
			cout << "Enter index of element (starting from 0): ";
			int i;
			cin >> i;
			cout << endl;
			if (i >= n)
			{
				cout << "Element doesn't exist" << endl << endl;
				break;
			}
			else
			{
				cout << "Enter key: ";
				int key;
				cin >> key;
				if (key > arr[i])
				{
					cout << endl;
					cout << "Can't change. Elment is bigger" << endl << endl;
					break;
				}
				else
				{
					HeapDecreaseKey(arr, i, key);
					cout << endl;
					cout << "Heap is: ";
					displayArray(arr, n);
					break;
				}
			}
		}
		default:
		{
			cout << "Try again!" << endl << endl;
			break;
		}
		}
	} while (choice != 11);
	return 0;
};