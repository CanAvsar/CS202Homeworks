/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: MinHeap.cpp
 */

#include <stdio.h>
#include "MinHeap.h"

MinHeap::MinHeap(): heapSize(0)
{
    
}

void MinHeap::insert(int value)
{
    if (heapSize >= MIN_HEAP_SIZE)
    {
        return;
    }
    // Place the new item at the end of the heap
    items[heapSize] = value;
    
    // Trickle new item up to its proper position
    int place = heapSize;
    int parent = (place - 1)/2;
    while ((place > 0) && (items[place] < items[parent]))
    {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        place = parent;
        parent = (place - 1)/2;
    }
    ++heapSize;
}

int MinHeap::peek()
{
    return items[0];
}

int MinHeap::extractMin()
{
    int valueToReturn = items[0];
    deleteItem(items[0]);
    return valueToReturn;
}

int MinHeap::size()
{
    return heapSize;
}

void MinHeap::deleteItem(int value)
{
    if (heapSize == 0)
    {
        return;
    }
    else
    {
        value = items[0];
        items[0] = items[--heapSize];
        heapRebuild(0);
    }
}

void MinHeap::heapRebuild(int root)
{
    int child = 2 * root + 1; // index of root's left child, if any
    
    if (child < heapSize)
    {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;       // index of a right child, if any
        
        // If root has right child, find larger child
        if ( (rightChild < heapSize) && (items[rightChild] < items[child]))
        {
            child = rightChild; // index of larger child
        }
        
        // If root’s item is smaller than larger child, swap values
        if ( items[root] > items[child])
        {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}
    
    

