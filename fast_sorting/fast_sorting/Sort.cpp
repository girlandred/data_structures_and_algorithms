#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Sort.h"

using namespace std;

/* функція, що змінює елементи місцями */
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* функція, що виконує розбиття масиву та змінює порядок елементів підмасиву */
int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] < x)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

/* функція, що виконує швидке сортування */
void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

/* функція, для відображення масиву */
void show(int A[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

/* функція, що реалізує випадкову перестановку */
int RandomizedPartition(int A[], int p, int r)
{
    srand(time(NULL));
    int i = p + rand() % (r - p);
    swap(&A[r], &A[i]);
    return Partition(A, p, r);
}

/* функція, що реалізує випадкове швидке сортування */
void RandomizedQuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = RandomizedPartition(A, p, r);
        RandomizedQuickSort(A, p, q - 1);
        RandomizedQuickSort(A, q + 1, r);
    }
}

/* функція, що рекурсивно розбиває вхідний масив */
int RandomizedSelect(int A[], int p, int r, int i)
{
    if (p == r)
        return A[p];
    if (i == 0)
        return -1;
    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return RandomizedSelect(A, p, q - 1, i);
    else return RandomizedSelect(A, q + 1, r, i - k);
}
