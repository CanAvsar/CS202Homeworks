/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: MedianHeap.cpp
 */

#include <stdio.h>
#include "MinHeap.h"
#include "MaxHeap.h"
#include "MedianHeap.h"

void MedianHeap::insert(int value)
{
    int currentMedian = findMedian();
    int top = 0;
    
    if(value > currentMedian)
    {
        minHeap.insert(value);
    }
    else
    {
        maxHeap.insert(value);
    }
    
    if(minHeap.size() > maxHeap.size() + 1)
    {
        top = minHeap.extractMin();
        maxHeap.insert(top);
    }
    if(maxHeap.size() > minHeap.size() + 1)
    {
        top = maxHeap.extractMax();
        minHeap.insert(top);
    }
        
}

int MedianHeap::findMedian()
{
    if(minHeap.size() == 0 && maxHeap.size() == 0)
    {
        return 0;
    }
    if(minHeap.size() >= maxHeap.size())
    {
        return minHeap.peek();
    }
    if(maxHeap.size() > minHeap.size())
    {
        return maxHeap.peek();
    }
    else
    {
        return 0;
    }
}
