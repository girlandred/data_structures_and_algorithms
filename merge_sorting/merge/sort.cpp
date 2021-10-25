#include "sort.h"

void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* array = new int[100];
    middle = (first + last) / 2;
    start = first;
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

void MergeSort(int* A, int first, int last)
{
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}
