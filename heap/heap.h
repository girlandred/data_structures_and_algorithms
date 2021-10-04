#pragma once

int Parent(int i);
int Left(int i);
int Right(int i);
void MaxHeapify(int* arr, int n, int i);
void MinHeapify(int* arr, int n, int i);
void BuildMaxHeap(int* arr, int n);
void BuildMinHeap(int* arr, int n);
void HeapSort(int* arr, int n);
int HeapMax(int* arr, int n);
int HeapMin(int* arr, int n);
int HeapExtractMax(int* arr, int& n);
int HeapExtractMin(int* arr, int& n);
void HeapIncreaseKey(int* arr, int i, int key);
void HeapDecreaseKey(int* arr, int i, int key);
void HeapInsertion(int *arr, int &n, int key);
void displayArray(int* arr, int n);