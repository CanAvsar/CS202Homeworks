/*
* Title: Heaps and AVL Trees
* Author: Can Avşar
* ID: 21902111
* Section: 1
* Assignment: 3
* Description: main.cpp
*/

#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

using namespace std;

int main(int argc, const char * argv[])
{

    MedianHeap medianHeap1 = MedianHeap();

    medianHeap1.insert(1);
    medianHeap1.insert(1);
    medianHeap1.insert(20);
    medianHeap1.insert(25);
    medianHeap1.insert(2);
    medianHeap1.insert(4);
    medianHeap1.insert(7);
    medianHeap1.insert(3);
    medianHeap1.insert(19);
    
    
    MedianHeap medianHeap2 = MedianHeap();

    medianHeap2.insert(13);
    medianHeap2.insert(13);
    medianHeap2.insert(20);
    medianHeap2.insert(25);
    medianHeap2.insert(1);
    medianHeap2.insert(2);
    medianHeap2.insert(8);
    medianHeap2.insert(5);
    medianHeap2.insert(29);
    
    
    cout << "Median of first is: " << medianHeap1.findMedian() << endl;
    cout << "Median of second is: " << medianHeap2.findMedian() << endl;


}
