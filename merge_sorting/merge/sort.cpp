#include <iostream>
#include "sort.h"

/* функція, що виконує злиття підмасивів в один відсортований */

void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* array = new int[100];

	//знаходження середини масиву
    middle = (first + last) / 2;
    start = first;

	// доки не досягнемо кінець, то обираємо ті елементи, що є найбільшими з усіх
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            array[j] = A[start];
            start++;
        }
        else {
            array[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)
        A[j] = array[j];
    delete[] array;

}

/* функція, що здійснює часткове сортування масиву */
void MergeSort(int* A, int first, int last)
{
	// поділ масиву до того моменту, доки не досягнемо first = last
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}
