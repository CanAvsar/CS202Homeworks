/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: MedianHeap.h
 */

#ifndef MedianHeap_h
#define MedianHeap_h

const int MEDIAN_HEAP_SIZE = 100;

class MedianHeap
{
public:
    void insert (int value ); // Inserts an element into median heap
    int findMedian(); // Returns the value of the median
    
protected:
    
private:
    int items[MEDIAN_HEAP_SIZE];
    MinHeap minHeap;
    MaxHeap maxHeap;
};

#endif /* MedianHeap_h */
