/**
* Title: Algorithm Efficiency and Sorting
* Author: Can Avşar
* ID: 21902111
* Section: 1
* Assignment: 1
* main.cpp */

#include <iostream>
#include "sorting.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int compCount;
    int moveCount;
    
    int arrayOne[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arrayTwo[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arrayThree[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arrayFour[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    
    cout << "Array Sorting with Insertion Sort" << endl;;
    insertionSort(arrayOne, 16, compCount, moveCount);
    printArray(arrayOne, 16);
    cout << endl << endl;

    cout << "Array Sorting with Merge Sort" << endl;;
    mergeSort(arrayTwo, 0, 15, compCount, moveCount);
    printArray(arrayTwo, 16);
    cout << endl << endl;
    
    cout << "Array Sorting with Quick Sort" << endl;;
    quickSort(arrayThree, 0, 15, compCount, moveCount);
    printArray(arrayThree, 16);
    cout << endl << endl;

    cout << "Array Sorting with Radix Sort" << endl;;
    radixSort(arrayFour, 16);
    printArray(arrayFour, 16);
    cout << endl << endl;

    performanceAnalysis();
    
}
