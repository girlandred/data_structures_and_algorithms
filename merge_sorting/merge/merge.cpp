#include <iostream>
#include "sort.h"

int main()
{
    int i;
    int n;
    int* A = new int[100];
    std::cout << "Enter array size: \n";
    std::cin >> n;
    std::cout << "Entered elements: ";
    for (i = 1; i <= n; i++) {
        std::cin >> A[i];
    }
    MergeSort(A, 1, n);
    std::cout << "Sorted array: ";
    for (i = 1; i <= n; i++)
        std::cout << A[i] << " ";
    delete[] A;
}