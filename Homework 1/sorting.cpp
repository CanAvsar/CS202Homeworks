/**
* Title: Algorithm Efficiency and Sorting
* Author: Can Avşar
* ID: 21902111
* Section: 1
* Assignment: 1
* sorting.cpp
 */

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include "sorting.h"
#include <math.h>

using namespace std;

void insertionSort(int* arr, const int arraysize, int& compCount, int& moveCount)
{
    for (int unsorted = 1; unsorted < arraysize; ++unsorted)
    {
        int nextItem = arr[unsorted];
        moveCount++;
        
        int loc = unsorted;
        
        compCount++;
        
        for ( ;(loc > 0) && (arr[loc-1] > nextItem); --loc)
        {
            arr[loc] = arr[loc-1];
            compCount++;
            moveCount++;
        }
        
        arr[loc] = nextItem;
        moveCount++;
    }
}

void mergeSort( int* arr, int first, int last, int &compCount , int &moveCount )
{
    if (first < last)
    {
        int mid = (first + last)/2; // index of midpoint
        
        mergeSort(arr, first, mid, compCount, moveCount);
        
        mergeSort(arr, mid+1, last, compCount, moveCount);
        
        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void merge(int arr[], int first, int mid, int last, int& compCount, int& moveCount)
{
    int tempArray[MAX_SIZE]; // temporary array
    
    int first1 = first; // beginning of first subarray
    
    int last1 = mid; // end of first subarray
    
    int first2 = mid + 1; // beginning of second subarray
    
    int last2 = last; // end of second subarray
    
    int index = first1; // next available location in tempArray
    
    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        compCount++;
        if (arr[first1] < arr[first2])
        {
            tempArray[index] = arr[first1];
            moveCount++;
            ++first1;
        }
        else
        {
            tempArray[index] = arr[first2];
            moveCount++;
            ++first2;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = arr[first1];
        moveCount++;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = arr[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index)
    {
        arr[index] = tempArray[index];
        moveCount++;
    }
} // end merge

void quickSort( int* arr, int first, int last, int& compCount, int &moveCount )
{
    int pivotIndex;
    
    if (first < last)
    {
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void partition(int arr[], int first, int last, int &pivotIndex, int& compCount, int& moveCount)
{
    int pivot = arr[first];
    moveCount++;
    
    int lastS1 = first;           // index of last item in S1
    
    int firstUnknown = first + 1; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    for ( ; firstUnknown <= last; ++firstUnknown)
    {
        compCount++;
        if (arr[firstUnknown] < pivot)
        {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount = moveCount + 3;
        }
    }
    
    //place pivot in proper position and mark its location
    swap(arr[first], arr[lastS1]);
    moveCount = moveCount + 3;
    
    pivotIndex = lastS1;
}

void radixSort(int *arr, int arraySize)
{
    int digitOfMaxElement = getDigitOfMaxElement(arr, arraySize);
    
    for (int i = 1; i <= digitOfMaxElement; i++)
    {
        int count[10];
        int elementGroups[10][arraySize];
        
        for (int j = 0; j < 10; j++)
        {
            count[j] = 0;
            
            for ( int k = 0; k < arraySize; k++)
            {
                elementGroups[j][k] = 0;
            }
        }
        
        for (int m = 0; m < arraySize; m++){
            
            int k = 0;
            
            if (i == 1)
            {
                k = arr[m] % 10;
            }
            else
            {
                k = arr[m] / getPowerOfANumber(10, (i - 1));
                k = k % getPowerOfANumber(10, (i - 1));
            }
            
            if (k > 9)
            {
                elementGroups[0][count[0]] = arr[m];
                count[0] = count[0] + 1;
            }
            else
            {
                elementGroups[k][count[k]] = arr[m];
                count[k] = count[k] + 1;
            }
        }
        
        int index = 0;
        
        for(int b = 0; b < 10;b++)
        {
            for(int c = 0; c < count[b]; c++)
            {
                arr[index] = elementGroups[b][c];
                index++;
            }
        }
    }
}

int getPowerOfANumber(int first, int second)
{
    int power = 1;

    if(second == 0)
    {
        return power;
    }
    
    for(int i = 0; i < second; i++)
    {
        power = power * first;
    }
    
    return power;
}

int getDigitOfMaxElement(int* arr, int arraySize)
{
    int digitOfMaxElement;
    int maxElement = arr[0];
    
    for (int i = 0; i < arraySize; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    
    digitOfMaxElement = log10(maxElement)+1;
    
    return digitOfMaxElement;
}


void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void printArray(int *arr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
}

void createArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    
    int randomNumber;
    srand ((unsigned) time(NULL));
    
    for (int i = 0; i < size; i++)
    {
        randomNumber = rand() % (MAX_NUMBER);
        
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;
        arr4[i] = randomNumber;
    }
}

void performanceAnalysis()
{
    int compCount;
    int moveCount;
    double mtime;
    long seconds;
    long miliseconds;
    timeval start;
    timeval end;
    
    // Arrays with 2000 items
    int *arrFirst2K = new int[2000];
    int *arrSecond2K = new int[2000];
    int *arrThird2K = new int[2000];
    int *arrFourth2K = new int[2000];
    
    // Arrays with 6000 items
    int *arrFirst6K = new int[6000];
    int *arrSecond6K = new int[6000];
    int *arrThird6K = new int[6000];
    int *arrFourth6K = new int[6000];
    
    // Arrays with 10000 items
    int *arrFirst10K = new int[10000];
    int *arrSecond10K = new int[10000];
    int *arrThird10K = new int[10000];
    int *arrFourth10K = new int[10000];
    
    // Arrays with 14000 items
    int *arrFirst14K = new int[14000];
    int *arrSecond14K = new int[14000];
    int *arrThird14K = new int[14000];
    int *arrFourth14K = new int[14000];
    
    // Arrays with 18000 items
    int *arrFirst18K = new int[18000];
    int *arrSecond18K = new int[18000];
    int *arrThird18K = new int[18000];
    int *arrFourth18K = new int[18000];
    
    // Arrays with 22000 items
    int *arrFirst22K = new int[22000];
    int *arrSecond22K = new int[22000];
    int *arrThird22K = new int[22000];
    int *arrFourth22K = new int[22000];
    
    // Arrays with 26000 items
    int *arrFirst26K = new int[26000];
    int *arrSecond26K = new int[26000];
    int *arrThird26K = new int[26000];
    int *arrFourth26K = new int[26000];
    
    // Arrays with 30000 items
    int *arrFirst30K = new int[30000];
    int *arrSecond30K = new int[30000];
    int *arrThird30K = new int[30000];
    int *arrFourth30K = new int[30000];
    
    
    createArrays(arrFirst2K, arrSecond2K, arrThird2K, arrFourth2K, 2000);
    createArrays(arrFirst6K, arrSecond6K, arrThird6K, arrFourth6K, 6000);
    createArrays(arrFirst10K, arrSecond10K, arrThird10K, arrFourth10K, 10000);
    createArrays(arrFirst14K, arrSecond14K, arrThird14K, arrFourth14K, 14000);
    createArrays(arrFirst18K, arrSecond18K, arrThird18K, arrFourth18K, 18000);
    createArrays(arrFirst22K, arrSecond22K, arrThird22K, arrFourth22K, 22000);
    createArrays(arrFirst26K, arrSecond26K, arrThird26K, arrFourth26K, 26000);
    createArrays(arrFirst30K, arrSecond30K, arrThird30K, arrFourth30K, 30000);
    
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Part A: Time Analysis of Insertion Sort" << endl;
    cout << "Array Size      Time Elapsed      compCount       moveCount" << endl;
    cout << " ";
    
    // Analysis of array with 2000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst2K, 2000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 2000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 6000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst6K, 6000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 6000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 10000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst10K, 10000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 10000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 14000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst14K, 14000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 14000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 18000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst18K, 18000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 18000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 22000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst22K, 22000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 22000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 26000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst26K, 26000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 26000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 30000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    insertionSort(arrFirst30K, 30000, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 30000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Part B: Time Analysis of Merge Sort" << endl;
    cout << "Array Size      Time Elapsed      compCount      moveCount" << endl;
    cout << " ";
    
    // Analysis of array with 2000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond2K, 0, 1999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 2000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 6000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond6K, 0, 5999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 6000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 10000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond10K, 0, 9999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 10000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 14000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond14K, 0, 13999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 14000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 18000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond18K, 0, 17999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 18000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 22000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond22K, 0, 21999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 22000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 26000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond26K, 0, 25999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 26000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 30000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    mergeSort(arrSecond30K, 0, 29999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 30000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Part C: Time Analysis of Quick Sort" << endl;
    cout << "Array Size      Time Elapsed      compCount      moveCount" << endl;
    cout << " ";
    
    // Analysis of array with 2000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird2K, 0, 1999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 2000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 6000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird6K, 0, 5999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 6000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 10000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird10K, 0, 9999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 10000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 14000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird14K, 0, 13999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 14000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 18000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird18K, 0, 17999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 18000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 22000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird22K, 0, 21999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 22000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 26000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird26K, 0, 25999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 26000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    // Analysis of array with 30000 items
    compCount = 0;
    moveCount = 0;
    gettimeofday(&start, 0);
    quickSort(arrThird30K, 0, 29999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 30000 << "         " << mtime << " ms"  <<  "         " << compCount <<  "         " << moveCount << "   " << endl;
    
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "Part D: Time Analysis of Radix Sort" << endl;
    cout << "Array Size      Time Elapsed" << endl;
    cout << " ";
    
    // Analysis of array with 2000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth2K, 0, 1999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 2000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 6000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth6K, 0, 5999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 6000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 10000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth10K, 0, 9999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 10000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 14000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth14K, 0, 13999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 14000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 18000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth18K, 0, 17999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 18000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 22000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth22K, 0, 21999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 22000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 26000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth26K, 0, 25999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 26000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
    // Analysis of array with 30000 items
    gettimeofday(&start, 0);
    quickSort(arrFourth30K, 0, 29999, compCount, moveCount);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - start.tv_sec;
    miliseconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + miliseconds/1000.0) + 0.5;
    cout << "  " << 30000 << "         " << mtime << " ms"  <<  "         "<< endl;
    
}



