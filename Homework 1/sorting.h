/**
* Title: Algorithm Efficiency and Sorting
* Author: Can Avşar
* ID: 21902111
* Section: 1
* Assignment: 1
* sorting.h
*/

#ifndef sorting_h
#define sorting_h

const int MAX_SIZE = 30000;
const int MAX_NUMBER = 50000;

void insertionSort(int* arr, const int arraysize, int& compCount, int& moveCount);
void mergeSort( int* arr, int first, int last, int &compCount , int &moveCount );
void merge(int theArray[], int first, int mid, int last, int& compCount, int& moveCount);
void quickSort( int* arr, int first, int last, int& compCount, int &moveCount );
void partition(int theArray[], int first, int last, int &pivotIndex, int& compCount, int& moveCount);
void radixSort(int *arr, int arraySize);
void swap(int &x, int &y);
void performanceAnalysis();
void createArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void printArray(int *arr, int arraySize);
int getDigitOfMaxElement(int* arr, int arraySize);
int getPowerOfANumber(int first, int second);

#endif
