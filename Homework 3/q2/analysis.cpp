/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: analysis.cpp
 */

#include <stdio.h>
#include <iostream>
#include "analysis.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void analysis::rotationAnalysis()
{
    
    cout << "Rotations on AVL Trees" << endl;
    cout << "Array Size   " << "Random   " << "Ascending   " << "Descending   " << endl;
    
    for(int arraySize = 1000; arraySize <= 10000; arraySize += 1000)
    {
        int* randomArray;
        int* ascendingArray;
        int* descendingArray;
        
        AVLTree tree;
        createRandomArray(randomArray, arraySize);
        for(int i = 0; i < arraySize; i++)
        {
            tree.insert(randomArray[i]);
        }
        cout << arraySize << "          "  << tree.getNumberOfRotations() << "      ";
        
        
        AVLTree tree2;
        createAscendingArray(ascendingArray, arraySize);
        for(int i = 0; i < arraySize; i++)
        {
            tree2.insert(ascendingArray[i]);
        }
        cout << tree2.getNumberOfRotations() << "        ";

        AVLTree tree3;
        createDescendingArray(descendingArray, arraySize);
        for(int i = 0; i < arraySize; i++)
        {
            tree3.insert(descendingArray[i]);
        }
        cout << tree3.getNumberOfRotations() << "          ";
        
        cout << endl << endl;
    }
}


void analysis::createRandomArray(int*& arr, const int size)
{
    arr = new int[size];
    
    int randomNumber;
    
    for (int i = 0; i < size; i++)
    {
        randomNumber = rand() % (100000);
        arr[i] = randomNumber;
    }
}

void analysis::createAscendingArray(int*& arr, const int size)
{
    arr = new int[size];
    
    int randomNumber;
    int maxNumber;
    
    maxNumber = 10;
    randomNumber = 0;
    
    for (int i = 0; i < size; i++)
    {
        randomNumber = randomNumber + (rand() % (maxNumber));
        arr[i] = randomNumber;
    }
}

void analysis::createDescendingArray(int*& arr, const int size)
{
    arr = new int[size];
    
    int randomNumber;
    int maxNumber;
    
    maxNumber = 10;
    randomNumber = 0;
    
    for (int i = 0; i < size; i++)
    {
        randomNumber = randomNumber + (rand() % (maxNumber));
        arr[i] = randomNumber;
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[size-1] - arr[i];
    }
}
